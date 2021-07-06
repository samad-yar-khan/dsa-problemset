#include<iostream>
#include<vector>
using namespace std;


 void heapify(int arr[], int n, int i)  
    {
        
      // Your Code Here
       int myIndex = i ;
         int parentIndex = (i-1)/2;
        while(parentIndex >=0 && arr[myIndex] > arr[parentIndex]){
            
        swap(arr[myIndex] , arr[parentIndex]);
        myIndex = parentIndex;
         parentIndex = (myIndex-1)/2;
        
    }
    }

  
    //Function to build a Heap from array.
    void buildHeap(int arr[], int n)  
    { 
       int i = 0 ;
        while( i < n ){
            
            heapify(arr , n , i);
                
            i++;
        }
    
    }


    //Function to sort an array using Heap Sort.
    void heapSort(int arr[], int n)
    {
        //code here
        buildHeap(arr , n);
        int j = n-1 ;
        
        while(j > 0){
            swap(arr[0] , arr[j]);//swwap firts and last elemt of heap
            //now we downHeapify
            int myIndex = 0 ;
            int lci = 2*myIndex + 1 ;
            int rci = 2*myIndex + 2;
            while(lci < j ){
                int myElement = arr[myIndex];
                int leftElement = arr[lci];
                int rightElement = rci < j ? arr[rci] : INT_MIN ;
                
                int swapI = leftElement > rightElement ? lci : rci;
                
                if(arr[swapI] > arr[myIndex]){
                    swap(arr[swapI] , arr[myIndex]);
                    myIndex = swapI;
                    lci = 2*myIndex  + 1 ;
                    rci = 2*myIndex + 2;
                
                }else{
                    break;
                }
                
            }
            
            j--;
        }
    }

    int main(){
        int n = 0 ;
        cin>>n;
        int arr[100]  = {0};
        for(int i = 0 ; i < n ;  i++){
            cin>>arr[i];
        }

        heapSort(arr , n);
         for(int i = 0 ; i < n ;  i++){
            cout<<arr[i]<<" ";
        }

    }