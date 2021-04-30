#include<iostream>
using namespace std;


int partition(int *arr , int si , int ei){

    int mi= 0 ;

    for(int i = si+1 ; i <= ei ; i++ ){

        if(arr[i] <= arr[si]){
            mi++;
        }

    }

    mi+=si;

    int temp = arr[mi];
    arr[mi] = arr[si];
    arr[si] = temp;

  
    
    //put all elemnts less than equal piivot to left and rest to right 
      int i = si , j = ei ;
    while(i < mi && j >mi){
        if(arr[i] <= arr[mi] && arr[j] > arr[mi]){
           i++;j--;
        }else  if(arr[i] <= arr[mi] && arr[j] <= arr[mi]){
            i++;
        }else  if(arr[i] > arr[mi] && arr[j] > arr[mi]){
            j--;
        }else{
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;j--;
        }
    } 

    return mi;

}

void quick_sort (int *arr , int si ,int ei){

    if(si >= ei){
        return;
    }

    //we find the index of or first elemmebt and pass it o the particition func
    //now our partitio func basiclally puts all eleemnst smalelr tha A[0] to the left of pivot
    //and all element greater to its right
    int pivot_index  = partition(arr,si,ei);

    //now my 0th eleemnt is at correct ppos and i calll qss on my left and right
    quick_sort(arr,si,pivot_index-1);
    quick_sort(arr,pivot_index+1 , ei);



}

int main(){
    int a[10] = {4 , 3  , 1 , 5 ,0 , -1 , 2 , 3 , 11 ,10};

    quick_sort(a , 0 , 9);

    for(auto i:a){
        cout<<i<<" ";
    }

}