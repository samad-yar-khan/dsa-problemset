#include<bits/stdc++.h>
using namespace std;


int firstOccurance(int*arr , int  n , int key){

    int s=0;
    int e=n-1;
    int fo = -1;
    while(s<=e){

        int mid = (s + e)/2;

        if(arr[mid] < key){
            s = mid +1 ;
        }else if(arr[mid] > key){
            e = mid-1;
        }else{
            //found
            fo = mid;
            //still look int the left
            e = mid-1;

        }
    }

    return fo;
}
int lastOccurance(int*arr , int  n , int key){

    int s=0;
    int e=n-1;
    int fo = -1;

    //we always have took look for  larger index
    while(s<=e){

        int mid = (s + e)/2;

        if(arr[mid] < key){
            s = mid +1 ;
        }else if(arr[mid] > key){
            e = mid-1;
        }else{
            //found
            //do tow thibgs
            fo = mid;
            //still look int the  right
            s=mid+1;

        }
    }

    return fo;
}


int main(){

    int arr[] = {1,3,8,8,8,8,8,10};
    //finfing llats and first  occurance of 8 i this array
    cout<<"Last occurance : "<<lastOccurance(arr ,8 ,8 )<<"\n";
    cout<<"First  occurance :"<<firstOccurance(arr ,8 ,8 )<<"\n";

}
