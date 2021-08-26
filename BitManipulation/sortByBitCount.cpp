#include<bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/sort-by-set-bit-count1153/1#

  static bool comparator(int a , int b){
            
        int c1 = 0 ;
        int c2 = 0;
        
        while(a>0){
            c1+=(a&1);
            a=a>>1;
        }
        
        while(b>0){
            c2+=(b&1);
            b=b>>1;
        }
        
        return c1>c2;
    }
    
    void mergeSorted(int *arr , int i , int j , int x , int y , int *temp){
        
        int k = 0 ;
        while( i<=j && x<=y){
            if(__builtin_popcount(arr[i]) >= __builtin_popcount(arr[x]) ){
                temp[k++] = arr[i++];
            }else{
                temp[k++] = arr[x++];
            }
        }
        while(i<=j){
            temp[k++] = arr[i++];
        }
        while(x<=y){
            temp[k++] = arr[x++];
        }
    }
    
    void mergeSort(int arr[] , int i , int j){
        
        //base case
        if(i>=j){
            return;
        }
        
        int mid = i+((j-i)/2);
        //ih
        mergeSort(arr , i , mid);
        mergeSort(arr , mid+1 , j);
        
        int *temp = new int[j-i+1];
        
        mergeSorted(arr , i , mid ,mid+1 ,j , temp);
        
        //copy back
        for(int k = 0 ; k <(j-i+1) ; k++){
            arr[i+k] = temp[k];
        }

        delete [] temp;
        
    }

    
    void sortBySetBitCount(int arr[], int n)
    {
        // Your code goes here
        //stable_sort(arr, arr+n , comparator); //stable sort uses merge sort and is used in case we need to presere order of elements in case of equal feild 
        mergeSort(arr , 0 , n-1);
    }