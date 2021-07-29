#include<bits/stdc++.h>
using namespace std;

int solve(int n , int lastFour , int**dp ){

    if(n== 0){
        return 1;
    }
    if(n<0){
        return 0;
    }

    if(dp[n][lastFour] != -1){
        return dp[n][lastFour];
    }

    int way1 = 0 ;
    int way2 = 0 ;
    int way3 = 0 ;
    int way4 = 0 ;

    way1 = solve(n-1 , 0 , dp);
    way2 = solve(n-2 , 0 , dp);
    way3 = solve(n-6 , 0 ,dp);
    if(lastFour == 0){
        way4=solve(n-4 , 1,dp);
    }

    dp[n][lastFour] =  way1 + way2 + way3 + way4; 
    return dp[n][lastFour];
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T=0;
    cin>>T;
    while(T--){

       int n=0;
       cin>>n;
       int**dp = new int*[n+1];
       for(int i = 0 ; i <= n ; i++){
           dp[i] = new int[2];
           for(int j = 0 ; j < 2 ; j++){
               dp[i][j] = -1;
           }
       }

       cout<<solve(n , 0 , dp)<<"\n";
       for(int i = 0 ; i < n ; i++){
         delete []   dp[i] ;
       }
       delete [] dp;
    }
}