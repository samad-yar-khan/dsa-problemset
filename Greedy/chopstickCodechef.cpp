#include<bits/stdc++.h>
using namespace std;

//https://www.codechef.com/problems/TACHSTCK

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int N=0;
    int D=0;

    cin>>N>>D;

    int*arr =  new int [N];

    for(int i=0;i<N ;i++){
        cin>>arr[i];
       
    }
    //we have to  keet in min dthat if a chopstick cant be paired with the nearst chopstck , the it cant be paired with any other chopstick
    sort(arr, arr+N);
    int i =0;
    int c = 0 ;
    while(i < N-1){

        if(arr[i+1] -arr[i]<=D){
            c++;
            i+=2;
        }else{
            i+=1;
        }

    }

    cout<<c<<"\n";


}