#include<bits/stdc++.h>
using namespace std;



 int partition (int arr[], int low, int high);

    void quickSort(int arr[], int low, int high)
    {
        // code here
        if(low>=high){
            return;
        }
        
        int pivot = partition(arr , low , high);
        quickSort(arr, low,  pivot-1);
        quickSort(arr, pivot+1,  high);
        
    }
    
    int partition (int arr[], int low, int high)
    {
           // Your code here

//this is a much simpler way to use quicksort algo
//what we do  is that we assume that we already have two partitions in our array
//assume element at last index i.e. high to be the pivot
//these partition arr bounded by i and j   
//WE Initially set i = s-1 , and j = si 
//asume all elemnts from si to i will be smller than pivot elemnt by the end of iteration and all elemnts from
//i+1 to j will be bigger than pivot eleent
//we iteate from j = si to ei
//if jth elemnt is smaller than than the pivot ellemnts , taht means that we need to expand our region with
//smaller elemnts , so we increase the boundry by doing i++
//now we swap elemts at j and i , this make ssure that elemt at j is larger than pivot and the elemt at i+1
//is smaller than pivot and i region was expanded
//if jth elemt is already moroe than pivot , we ust do j++ , signifying taht we increaed the region witj greater elemts
//at the end we got smaller elemnnts from si to i and largeer ellemnst from i+1 to j
//now we swap i+1 and our pivoot eleent at the end of the array
//and it will be at its correct position
//with small elemnts towards the left and larger to the right and we reiten i+1 as pivot index 

       int i = low-1 , j=low , p{high};
       
       while(j<high){
            
            if(arr[j] <= arr[p]){
                i++;//expand i 
                swap(arr[i] , arr[j]);
            }
            
            j++;
           
       }
       //now i is the boundru of smaller array 
       //j is the end point of larer arr
       //nowe pivoot pint will be i+1 
       //as if we swap i+1 with p , all elemts to the lft of p wll be smaller an to the right biggrt
       
       swap(arr[i+1]  , arr[p]);
       p = i+1;
       return p;
       
    }

    int main(){
        cout<<"Enter size : ";
        int n{0};
        cin>>n;
        int*arr = new int[n];

        cout<<"Enter elementa : ";

        for(int i{0} ; i < n ; i++){
            cin>>arr[i];
        }   

        quickSort(arr , 0 , n-1);

       for(int i{0} ; i < n ; i++){
            cout<<arr[i]<<" ";
        }   
        

        delete [] arr;

    }