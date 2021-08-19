#include<bits/stdc++.h>
using namespace std;



int main(){

    int arr [] = {1,1,2,3,5,6,7,7,7,7,8};
    int n = 11;

    if(binary_search(arr , arr+11,5)){
        cout<<"present !\n";
    }

    int* ub = upper_bound(arr , arr+11 , 5); 
    cout<<"index up :  "<<ub-arr<<"\n";//will give index of elemnt which is jusst larget than 7

    int*lb = lower_bound(arr, arr+n , 7);//will give the adress oof the elrmnt whcih is just smalelr or equal to 7
    cout<<"index lb :  "<<lb-arr<<"\n";


}