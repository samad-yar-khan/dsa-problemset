#include<iostream>
using namespace std;


void solve(int *arr  , int n ){

    int*aux = new int[n];

    int i = 0 ;
    int j = n-1;
    int k = n-1;

    while(i<=j && k >=0){
        if(arr[i]*arr[i]  > arr[j]*arr[j]){
            aux[k] = arr[i]*arr[i];
            k--;i++;
        }else{
            aux[k] = arr[j]*arr[j];
            k--;j--;
        }
    }

    for(int i = 0; i < n ; i++){
        arr[i] = aux[i];
    }

    delete [] aux;

}

int main(){
    int arr[] = {-7,-5,-2,0,1};
    
    solve(arr , 5);
    for(int i = 0 ; i < 5 ; i++ ){
        cout<<arr[i]<<" ";
    }

}