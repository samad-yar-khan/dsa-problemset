#include<bits/stdc++.h>
using namespace std;

//https://www.codingninjas.com/codestudio/problems/travelling-salesman-problem_1385180?leftPanelTab=1

int helper(string&s){
    int a=0;
    int l=1;
    for(int i =0;i<s.size();i++){
        if(s[i] == '1'){
            a+=l;  
        }
        l=l<<1;
    }
    return a;
}

int dfs(int n, vector<vector<int>>&g,string&vis, int c, vector<vector<int>>&dp,int nums,int sp){
        
    if(nums>=n){
        return g[c][sp];
    }
    int h = helper(vis);
    if(dp[h][c]!=-1){
        return dp[h][c];
    }
    int ans =INT_MAX;
    
    for(int i =0;i<n;i++){
        if(vis[i] == '0'){
            vis[i] = '1';
            int t=dfs(n,g,vis,i,dp,nums+1,sp) + g[c][i];
            ans = min(ans,t);
            vis[i] = '0';
        }
    }
  
    
    dp[h][c]=ans;
    return ans;
    
}

int shortestRoute(vector<vector<int>> &distance)
{
	// Write your code here.
    int r = distance.size();
    int c = distance[0].size();
    int A=INT_MAX;
  
    int R=(1<<distance.size())-1;
    vector<vector<int>>dp(R,vector<int>(r,-1));
//         unordered_map<string,int>dp;
    
       string vis(r,'0');
    vis[0] = '1';    
    int ans=dfs(r,distance,vis,0,dp,1,0);
    
    
    A = min(ans,A);
    
   return A;
    
}