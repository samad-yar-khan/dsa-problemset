#include<iostream>
using namespace std;


int bs(int input[], int si , int ei, int element){

    //bc
    if(si > ei){
        return -1;
    }

    //is
    int mid = (si+ei)/2;
    
    if(input[mid] == element){
        return mid;
    }

    if(input[mid] > element){
        ei = mid-1;
    }else{
        si = mid+1;
    }

    //ih
    return bs(input , si , ei , element);



}

int binarySearch(int input[], int size, int element){


    return  bs(input , 0 , size-1 , element);

}


int main(){

    int n{0};
    cin>>n;

    int*arr = new int[n];

    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }

    cout<<"Element : "<<'\n';
    int e{0};
    cin>>e;

    cout<<"\n"<<binarySearch(arr , n , e)<<"\n";


    delete [] arr;


}