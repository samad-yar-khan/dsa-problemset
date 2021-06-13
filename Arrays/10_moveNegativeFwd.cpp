/*
Move all negative numbers to beginning and positive to end with constant extra space
Difficulty Level : Easy
Last Updated : 09 Jun, 2021
An array contains both positive and negative numbers in random order. Rearrange the array elements so that all negative numbers appear before all positive numbers.

Examples : 

Input: -12, 11, -13, -5, 6, -7, 5, -3, -6
Output: -12 -13 -5 -7 -3 -6 11 6 5
Note: Order of elements is not important here.
*/
#include<iostream>
using namespace std;

void solve(int * arr , int n){

    int i = 0 , j = n -1;
    while(i < j){
        if(arr[i] >= 0 && arr[j] < 0){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;j--;
        }else if(arr[i] >= 0 && arr[j] >=0){
            j--;
        }else if(arr[i] < 0 && arr[j] <0){
            i++;
        }else{
            i++;j--;
        }
    }
}

int main(){
    int arr[]={1,2,0,-1,0,9,-22,-10};
    solve(arr,8);
    for(int i = 0 ; i < 8 ; i++){
        cout<<arr[i]<<" ";
    }
}
