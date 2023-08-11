#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/coin-change-ii
int sol(int amount, vector<int>&coins, int ind, vector<vector<int>>&dp){
    if(ind >= coins.size()){
            return amount == 0;
    }
    if(amount == 0){
        return 1;
    }
    if(dp[ind][amount]!=-1){
        return dp[ind][amount];
    }
        
    int case1 = amount >= coins[ind] ? sol(amount-coins[ind], coins, ind, dp) : 0;
    int case2 = sol(amount, coins,ind+1, dp);
        
    dp[ind][amount] = case1+case2;
    return dp[ind][amount];    
}    

int change(int amount, vector<int>& coins) {
    int n = coins.size();
    vector<vector<int>>dp(n,vector<int>(amount+1,0));
    for(int i =0;i<n;i++){
        dp[i][0] = 1;//if amount = 0, the ans = 1
    }
    for(int i = 1;i<=amount;i++){
        for(int j =n-1;j>=0;j--){
            int curr_amount = i;
            int case1 = curr_amount >= coins[j] ? dp[j][curr_amount - coins[j]]:0;
            int case2 = j!=n-1 ? dp[j+1][i] : 0;
            dp[j][i] = case1 +case2;
        }
    }
    return  dp[0][amount];
}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
     #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r" , stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    int T=0;cin>>T;
    while(T--){
        int amount=0;cin>>amount;
        int n=0;cin>>n;
        vector<int>arr(n,0);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        cout<<change(amount, arr)<<"\n";
    }
}