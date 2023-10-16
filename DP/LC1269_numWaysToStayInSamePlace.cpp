#include<bits/stdc++.h>
using namespace std;

    long long mod_val = 1e9 + 7; 

    int solve_rec(int ind, int steps, int &arrLen){
        if(ind < 0 || ind >= arrLen){
            return 0;
        }
        if(steps==0){
            return ind ==0;
        }
        
        int right = solve_rec(ind+1,steps-1, arrLen);
        int in_place = solve_rec(ind,steps-1, arrLen);
        int left = solve_rec(ind-1,steps-1, arrLen);

        return right + left + in_place;
        
    }

    int solve_memo(int ind, int steps, int &arrLen, vector<vector<int>>&dp){
        if(ind < 0 || ind >= arrLen){
            return 0;
        }
        if(steps==0){
            return ind ==0;
        }

        if(dp[steps][ind]!=-1){
            return dp[steps][ind];
        }


        long long right = solve_memo(ind+1,steps-1, arrLen,dp);
        long long in_place = solve_memo(ind,steps-1, arrLen,dp);
        long long left = solve_memo(ind-1,steps-1, arrLen,dp);

        dp[steps][ind] = (right + in_place + left)%mod_val;

        return dp[steps][ind];
        
    }


    void swap_arrays(vector<int>&prev, vector<int>&curr,int steps){
        for(int i =0;i<=min(int(prev.size()-1),steps);i++){
            prev[i] = curr[i];
            curr[i] = 0;
        }
    }
    int numWays(int steps, int arrLen) {
        
        vector<int>prev(arrLen+1,0);
        vector<int>curr(arrLen+1,0);
        prev[0] = 1;
        prev[1] = 1;

        for(int i =2;i<=steps;i++){
            for(int j =0;j<=min(arrLen-1,i);j++){
                long long l = 0;
                long long r = 0;
                long long c =0 ;

                if(j>0){
                    l = prev[j-1];
                }

                if(j<arrLen-1){
                    r = prev[j+1];
                }

                c = prev[j];
                long long ans = (c+r+l)%mod_val;
                curr[j] = ans;
            }
        swap_arrays(prev, curr,steps);
        }
        
        return prev[0];
    }