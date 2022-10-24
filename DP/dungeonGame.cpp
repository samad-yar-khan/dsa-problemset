#include<bits/stdc++.h>
using namespace std;

    int solve(vector<vector<int>>& dungeon, int i, int j, int n, int m, vector<vector<int>>&dp){
        if(i>=n || j>=m){
            return 1;
        }
        if(dp[i][j] != INT_MAX){
            return dp[i][j];
        }
        int down = max(1,1-dungeon[i][j]);
        int right = max(1,1-dungeon[i][j]);
        bool d=false,r=false;
        if(i+1<n){
            d=true;
            down =  solve(dungeon,i+1,j,n,m,dp)-dungeon[i][j];   
            if(down<=0){
                down = 1;
            }
        }
        if(j+1<m){
            r=true;
            right = solve(dungeon,i,j+1,n,m,dp)-dungeon[i][j];
            if(right<=0){
                right = 1;
            }
        }
        
        if(!(r||d)){
            dp[i][j] = down;
        }else if(r&&d){
            dp[i][j] = min(down,right);
        }else if(r){
            dp[i][j] = right;
        }else{
            dp[i][j] = down;
        }
        return dp[i][j];
        
    }
   
    
    
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size();
        int m = dungeon[0].size();
        //first stored global min of path
        //second stores currSum
        
        vector<vector<int>>dp(n,vector<int>(m,INT_MAX));
        for(int i = n-1; i>=0;i--){
            for(int j =m-1;j>=0;j--){
                int down = max(1,1-dungeon[i][j]);
                int right = max(1,1-dungeon[i][j]);
                bool d=false,r=false;
                if(i+1 < n){
                    down = max(1,dp[i+1][j]-dungeon[i][j]);
                    d=true;
                }
                if(j+1<m){
                    right = max(dp[i][j+1]-dungeon[i][j],1);
                    r=true;
                }
                 if(!(r||d)){
                    dp[i][j] = down;
                    }else if(r&&d){
                        dp[i][j] = min(down,right);
                    }else if(r){
                        dp[i][j] = right;
                    }else{
                        dp[i][j] = down;
                    }
                }
        }
        int ans = dp[0][0];
        //dp[i][j] stores the  min helath req to reach n-1,m-1 staring from i,j
        //if it needs helath h, we wodul need health h-dem[i][j], id this becomes -ve that means we need 1 health only
        return ans<=0?1:ans;
    }