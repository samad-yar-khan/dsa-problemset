#include<bits/stdc++.h>
using namespace std;


/*
Logic is that we need to put all elemnts of the mat in a vector and sort by value
now we start dfs from the largest values first, because their paths can be used
to build the increasing path when smaller valus reach them
we call dfs on the nodes in desecneding orders
dp[i][j] stores the longets strinctly increasing path from (i,j)
we go in revserse ordere to avoid overallping
if we reach (i,j) , and it is adjacent to some larger values, then
longgest increaisng path for that value would have alrady been calculated and 
it cannot intersect with our path
becasue our current trail will be smaller than us and the trail from our larget neighbour would be stricly larger than us
*/

//https://binarysearch.com/problems/Longest-Increasing-Path/submissions/7628749
//https://binarysearch.com/problems/Longest-Increasing-Path/
//https://leetcode.com/problems/longest-increasing-path-in-a-matrix/submissions/

int x [4] = {-1,1,0,0};
int y [4] = { 0,0 , -1,1};

int dfs(vector<vector<int>>& m , int i , int j , vector<vector<bool>>& v , vector<vector<int>>& dp){
    if(i<0 || i>=m.size() || j<0 || j>=m[0].size()){
        return 0;
    }
    if(v[i][j]){
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        return 0;
    }

    v[i][j] = true;
    int ans = 1;
    for(int c = 0;c<4;c++){
        int X= i+x[c];
        int Y= j+y[c];
        
        if(X<0 || X>=m.size() || Y<0 || Y>=m[0].size()){
            continue;
        }
        if(m[X][Y] <= m[i][j]){
            continue;
        }
        ans = max(ans,1+dfs(m,X,Y,v,dp));
    }
    dp[i][j] = ans;
    return ans;
    
}


int solve(vector<vector<int>>& matrix) {
    vector<pair<int,pair<int,int>>>vec;
    for(int i =0;i<matrix.size();i++){
        for(int j =0;j<matrix[0].size();j++){
            vec.push_back(make_pair(matrix[i][j],make_pair(i,j)));
        }
    }
    sort(vec.begin(),vec.end());
    vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),-1));
     vector<vector<bool>> v(matrix.size(),vector<bool>(matrix[0].size(),false));

  

    int ans = 1;
    for(int i =vec.size()-1;i>=0;i--){  
        pair<int,pair<int,int>> p = vec[i];
        int A = dfs(matrix,p.second.first,p.second.second,v,dp);
        ans = max(ans , A);
    }
    return ans;
}