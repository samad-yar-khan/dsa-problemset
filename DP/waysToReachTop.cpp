#include<bits/stdc++.h>
using namespace std;

//numways to reach nth step i we can go a max f k steps ahead each time
//memoiatiob
int solve(int n , int k,int*dp ){
    //edge
    if(k ==  0 ){
        return 0;
    }

    //base
    if(n==0){
        return 1;//1 ways
    }

    if(dp[n]!=-1){
        return dp[n];
    }
    int ways = 0 ;
    for(int i = 1 ; i <= k && n-i>=0 ; i++){
        ways = ways + solve(n-i,k,dp);
    }
    dp[n]=ways;
    return dp[n];
}

//O(N*K)
int solveDP(int n , int k){

    if(k == 0){
        return 0;
    }
    int *dp = new int[n+1]{0};

    dp[0] = 1;

    for(int i = 1 ; i <= n ; i++){
        dp[i] = 0 ;
        for(int j =1 ; j<=k && i-j>=0 ;j++){
            dp[i] += dp[i-j];
        }
    }
    int ans = dp[n];
    delete [] dp;
    return ans;
}


//at any point w just need a sum od the last k answers 
//so along with dp[i] to savetime we make a presm array

//O(N + K)
int solveDpOptim(int n , int k){

    if(k == 0){
        return 0;
    }
    int *dp = new int[n+1]{0};
    int *presum = new int[n+1]{0};

    dp[0] = 1;
    presum[0] = 1;
    //at each point we just need the sum of all ways to go from dp[x] from x rangess from i-1 to i-k
    for(int i = 1 ; i <= n ; i++){
        if(i > k){
            dp[i] = presum[i-1] - presum[i-k-1];
        }else{
            dp[i] = presum[i-1];
        }
        presum[i] = presum[i-1] + dp[i];
    }

    int ans = dp[n];
    delete [] dp;
    delete [] presum;
    return ans;
}


int main(){

    int T = 0 ;
    cin>>T;
    while (T--)
    {
        /* code */
        int n = 0  ; int k =  0 ;

        cin>>n>>k;
    
        // int*dp = new int[n+1];
        // for(int i = 0  ; i < n ; i++){
        //     dp[i]=-1;
        // }

        // cout<<solve(n,k,dp);


        // delete [] dp;
        cout<<solveDpOptim(n,k)<<"\n";
    }
    

}