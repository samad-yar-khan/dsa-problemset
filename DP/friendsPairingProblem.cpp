#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
using namespace std;

//brute force recursiive approach
int rec(int n){
            
        if(n==1||n==0){
            return 1;
        }
        if(n<0){
            return 0;
        }
        
        //i will only work on thre first two
        int c1 = rec(n-1);//dont pair
        int c2 = (n-1)*rec(n-2);
        
        return c1+c2;
}

//memoizsaton
#define ll long long int
ll memo_imp(int n , ll*dp){

    //base case 
    //we will will hit it at the end
    if(n==1 || n==0){
        return 1;
    }
    //edge case
    //edge because it may come at some point
    if(n<0)
    {
        return 0;
    }

    //checl if aready have the ans or not
    if(dp[n]!=-1){
        return dp[n];
    }


    //we dont have the anwe at thisplace
    ll c1 = memo_imp(n-1,dp)%mod;//dont pair
    ll c2 = (n-1)*memo_imp(n-2 ,dp)%mod;

    dp[n] = (c1+c2)%mod;
}

ll memo(int n ){

    ll*memo=new ll[n+1];

    //memo[i] i sbasicllay the numbe rof ways to couple i friends 

    for(int i= 0 ; i <= n ; i++){
        memo[i] = -1; 
    }

    int ans = memo_imp( n , memo)%mod;
    delete [] memo;//there is no garbage colleected like in java so we must deaalovatte the memory ourseves
    return ans;
}

//dp
//O(N) time and O(N) space
ll dp(int n ){

    ll*dp=new ll[n+1];

    //memo[i] i sbasicllay the numbe rof ways to couple i friends 

    for(int i= 0 ; i <= n ; i++){
        dp[i] = -1; 
    }

    dp[0] = 1;
    dp[1] = 1;
    
    for(int i = 2 ; i <= n ; i++){
        dp[i] = (dp[i-1] + (i-1)*(dp[i-2]))%mod;
    }
    int ans = dp[n];
    delete [] dp;//there is no garbage colleected like in java so we must deaalovatte the memory ourseves
    return ans;
}

// optimised dp with o(1) spacee
//our  recurrrance relation is T(N) = T(N-1) + (N-1)*T(N-2);
// we only need to wavalues
ll betterDp(int n){

    ll C1=1;//dp[0]
    ll C2=1;//dp[1]

    for(int i = 2 ; i <= n ; i++){

        ll temp = (C2 + C1*(i-1))%mod;
        C1 = C2;
        C2 = temp;
    }

    return C2;

}   

