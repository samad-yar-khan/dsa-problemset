#include<bits/stdc++.h>
using namespace std;

//https://practice.geeksforgeeks.org/problems/allocate-minimum-number-of-pages0937/1#
/*
logic is that we we will make a range in which we can keep thesee books but after that
we will have to apply binary searhc ans see if we can allocated that freq of books to our studest aor should we supply more books
starting pt = max  pages book in our array
eding index = sum of all pages


*/


    bool isPossible(int * arr , int n , int allocation , int students){
       
       int students_taken = 1 ;
       int booksTaken = 0 ; 
       
       for(int i = 0 ;i <n ; i++){
           
           if(arr[i]>allocation){
               return false;
           }
           
           if(booksTaken+arr[i] > allocation){
               //cant allocate more bok ok here so go to next stduent
               booksTaken = arr[i];
               students_taken++;
               
               if(students_taken > students){
                   return false;
               }
               
               
           }else{
               booksTaken += arr[i];
           }
       }
       
      
     return true;  
    }


    int findPages(int arr[], int n, int m) 
    {
        
        //edge case
        if(n<m){
            return -1;
        }
        //code here
        // sort(arr , arr + n );
        
        //finding my search space
        //min of max pages a person can read in a case
        //mabnlo ek person bas largest nummber  of pageske equal ya zada hi read karsakte hai 
        int  leftBound =0;
        int rightBound = 0 ; //max pages cvan be all pages of all books
        for(int i = 0 ; i < n ; i++){
            rightBound += arr[i];
            leftBound=max(leftBound,arr[i]);
        }
       
        int ans = -1 ;
       
        while(leftBound <= rightBound){
            
            int maxAllocatePages = leftBound + ((rightBound-leftBound)/2);
            
            if(isPossible(arr , n , maxAllocatePages , m )){
               ans =maxAllocatePages;
                //now larger aallocation is possible but we havge to look for smaller allcoation
                rightBound = maxAllocatePages-1;
            }else{
                //mot possible look for  bigger allovation
                leftBound = maxAllocatePages+1;
            }
            
            
        }
        return ans;
    }