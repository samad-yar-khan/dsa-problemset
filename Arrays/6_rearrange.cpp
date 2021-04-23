//https://practice.geeksforgeeks.org/problems/-rearrange-array-alternately-1587115620/1#

#include<iostream>
using namespace std;

void rearrange_brute(long long *arr, int n){ 
    int i = 0 ;
    int j = n-1;
    int k = 0;
    
    long long *temp_arr = new long long[n];	 
   

    while(k < n &&  i<=j){

        temp_arr[k++] = arr[j--];
        if( i != j+1 && k < n){
            temp_arr[k++] = arr[i++];
        }

    }

    for(int itr = 0 ; itr< n ; itr++){

        arr[itr] = temp_arr[itr];
    }

    delete[] temp_arr;

}   

void rearrange(long long *arr, int n){ 
    int i = 0 ;
    int j = n-1;
    int k = 0;
    long long max_num = arr[n-1];
     int x = n-1;
    while(arr[x] == max_num){
        x--;
    }
    x++;
   	 
    while(k < n &&  i<=j){
        
        long long replacement{0} ;
        if(j < k){

            replacement = arr[j]%max_num;

        }else{
            replacement = arr[j];
        }

        arr[k] = replacement*max_num + arr[k];
        k++;
        j--;

        if( i != j+1 && k < n){
           

            if(i < k){

            replacement = arr[i]%max_num;

             }else{
            replacement = arr[i];
             }
             
            arr[k] = (replacement*max_num) + arr[k];
            k++;
            i++;

        }

    }

    for(int itr = 0 ; itr< x ; itr++){
        arr[itr] = arr[itr]/max_num;
    }

    for(int itr = x ; itr< n ; itr++){
        arr[itr] = arr[itr]/max_num  - 1;
    }

}   

int main(){

    int n= 0;
    cin>>n;
    long long *arr = new long long[n];

    cout<<"Elements : ";
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }

    rearrange(arr,n);

    for(int i = 0 ; i < n ; i++){
        cout<<arr[i]<<" ";
    }
}   