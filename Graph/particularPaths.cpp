#include<bits/stdc++.h>
using namespace std;

/*
https://binarysearch.com/problems/Particular-Paths
    the question wants us to go from 0,0 to the end but the sum should be a equal to k
    this can be a simple dp dfs problem but the constarints rows *cols *k for our DP, woyle exceed memo limit
    becasue k  <=  10^5, rows = cols <= 10^2
    the ke to the question is dfs + dp . but the main problem lies in forming that dp
    dp cant use space of  the order of 10^9 , so we notice that max, k needed will be rows + cols -1 and anything after that is not feasable
    so we limit ke to n+m-1 and in this manner , memory usage limits to 10^6 amf we solve the question in n*m*(n+m-1 or k) 
*/

int modVal = 1e9 + 7;

int sol(vector<vector<int>>& matrix , vector<vector<vector<int>>>&dp,int x,int y, int k){
    
    if(x >= matrix.size() || y>= matrix[0].size() || k<0){
        return 0;
    }

    if( x == matrix.size()-1 && y == matrix[0].size()-1){
        k-=matrix[x][y];
        if(k<0 || k>0){
            return 0;
        }
        return 1;
    }
    if(dp[x][y][k] != -1){
        return dp[x][y][k];
    }

    long long ra = sol(matrix,dp,x,y+1,k-matrix[x][y]);
    long long da = sol(matrix,dp,x+1,y,k-matrix[x][y]);

    int ans = (ra%modVal + da%modVal)%modVal;
    dp[x][y][k] = ans;
    return ans;


}


int solve(vector<vector<int>>& matrix, int k) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    int maxK = rows+cols-1;
    k=min(maxK,k);
    
    vector<vector<vector<int>>>dp(rows, vector<vector<int>>(cols,vector<int>(k+1,-1)));
    return sol(matrix,dp,0,0,k);
}