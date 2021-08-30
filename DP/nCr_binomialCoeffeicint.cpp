#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

//https://practice.geeksforgeeks.org/problems/ncr1019/1#
/*
We sove the qn using a pascals triangle 
now for pascals triangle we make a matrix represnetation instead of trainge


*/

int nCr(int n, int r){

    if(r>=n){
        return 0;
    }

    //we use the pascals triangle to solve ncr 
    // we need max of r elemnts to reahc our ans
    int*pascal = new int[r+1];
    for(int i = 0 ; i <=r ; i++){
        pascal[i] = 0;
    }
    //we havc teh first row 0C0 for  now
    pascal[0] = 1;

    for(int i = 1 ;i<=n ; i++){
        for(int j = min(i,r) ;j>=1 ; j--){
            pascal[j] = (pascal[j-1]+pascal[j])%mod;
        }
    }

    int ans = pascal[r];
    return ans;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T = 0;
    cin>>T;
    while(T--){
        int n = 0 ;
        int r = 0 ;
        cin>>n>>r;
        cout<<nCr(n,r)<<"\n";
    }   
    return 0;
}