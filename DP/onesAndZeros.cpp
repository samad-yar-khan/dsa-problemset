#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/ones-and-zeroes/

//memoization
int solve(vector<pair<int,int>>&vec, int m, int n , int N , int curr,vector<vector<vector<int>>>&dp){
        if(curr>=N){
            return 0;
        }
        
        if(dp[curr][m][n]!=-1){
            return dp[curr][m][n];
        }
        
        int case1 = INT_MIN;
        int case2 = INT_MIN;
        
        case1 = solve(vec,m,n,N,curr+1,dp);
        if(m-vec[curr].first >=0 && n - vec[curr].second>=0){
            case2 = solve(vec,m-vec[curr].first,n-vec[curr].second , N, curr+1,dp)+1;
        }
        dp[curr][m][n] = max(case1,case2);
        return dp[curr][m][n];
        
        
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>>vec;
        int N = strs.size();
    
        for( int i =0 ; i < N ; i++ ){
            int o=0,z=0;
            for(int j =0;j<strs[i].length();j++){
                if(strs[i][j] == '0'){
                    z++;
                }else{
                    o++;
                }
            }
            vec.push_back(make_pair(z,o));
        }
        
        vector<vector<vector<int>>>dp(N+1,vector<vector<int>>(m+1,vector<int>(n+1,-1)));
        return solve(vec,m,n,N,0,dp);
        
    }

    //iterarve dp
    // time = O(N*n*m)
      int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>>vec;
        int N = strs.size();
    
        for( int i =0 ; i < N ; i++ ){
            int o=0,z=0;
            for(int j =0;j<strs[i].length();j++){
                if(strs[i][j] == '0'){
                    z++;
                }else{
                    o++;
                }
            }
            vec.push_back(make_pair(z,o));
        }
          vector<vector<vector<int>>>dp(N+1,vector<vector<int>>(m+1,vector<int>(n+1,0)));
        for(int x = 0 ; x<m ; x++){
           for(int y=0;y<n;y++){
               if(vec[N-1].first <= x && vec[N-1].second<=y){
                   dp[N-1][x][y]= 1;
               }
           }
        }
        int ans=0;
        for(int c =N -2;c>=0;c--){
            for(int x = m ;x>=0 ; x--){
                for(int y=n;y>=0;y--){

                    int case1 = INT_MIN;
                    int case2 = INT_MIN;
                    if(vec[c].first <= x && vec[c].second<=y){
                        case1 = dp[c+1][x-vec[c].first][y-vec[c].second]+1;
                    }
                    case2 = dp[c+1][x][y];
                    dp[c][x][y] = max(case1,case2);
                    ans = max(ans,dp[c][x][y]);
                }
            }
        }
      
        
    }

    //at any point I am looking at the c+1th grid only, hence I need only two grids, to calc dp[c][x][y] i only need the c+1th grid
    //time = O(N*n*m)   
    //space = O(n*m)
    //this will reduve space to be o(m*n)
int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int,int>>vec;
        int N = strs.size();
    
        for( int i =0 ; i < N ; i++ ){
            int o=0,z=0;
            for(int j =0;j<strs[i].length();j++){
                if(strs[i][j] == '0'){
                    z++;
                }else{
                    o++;
                }
            }
            vec.push_back(make_pair(z,o));
        }
        vector<vector<int>>d1(m+1,vector<int>(n+1,0));
        vector<vector<int>>d2(m+1,vector<int>(n+1,0));
        vector<vector<int>>&dp1=d1;
        vector<vector<int>>&dp2=d2;
                  
        int ans=0;

        for(int x = 0 ; x<=m ; x++){
           for(int y=0;y<=n;y++){
               if(vec[N-1].first <= x && vec[N-1].second<=y){
                   dp1[x][y]= 1;
                   ans =1;
               }
           }
        }
        for(int c =N -2;c>=0;c--){
            for(int x = m ;x>=0 ; x--){
                for(int y=n;y>=0;y--){

                    int case1 = INT_MIN;
                    int case2 = INT_MIN;
                    if(vec[c].first <= x && vec[c].second<=y){
                        case1 = dp1[x-vec[c].first][y-vec[c].second]+1;
                    }
                    case2 = dp1[x][y];
                    dp2[x][y] = max(case1,case2);
                    ans = max(ans,dp2[x][y]);
                }
            }
            swap(dp1,dp2);//swapping refs to save time
        }
                  return ans;
      
        
    }