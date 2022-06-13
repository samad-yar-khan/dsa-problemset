#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/soup-servings/
//this is basically a dp optimization problem, the main problem is optimising dp
//so a serving can be considers anythung less thab 25ml
// so consdier 25 ml as one serving
//do tak the ciel of n/25
//and this will be a and b
//no if(a ==0 && b!=0), out value would be 1, as its its success
//if( a==0==b ) that shpuld return 0.5 as we need half of that ans
//if a!=0 and b==0, we return 0 , as  its thw wrong ans
//now dps hits when we see that the methods favour lweing of a and npt be
//1) p(a-4,b)
//2) p(a-3,b-1)
//3) p(a-2,b-2)
//4) p(a-1,b-3)

//so as n increases it becomes harder to decrease b before a and our answers probaboilyiy would reahc near 1
//so after 4800 we reteurn 1
//4800/25 ~ 200
//we memlize for dp[200][200]

    
    double solve(int a, int b,vector<vector<double>>&dp){
        
        
        
        if(a<=0 ){
            return b<=0 ? 0.5 : 1;//c2 AND C1
        }
        if(b<=0){
            return 0;//c3
        }
        if(dp[a][b]!=-1){
            return dp[a][b];
        }
        
        dp[a][b] = 0.25*(solve(a-4,b,dp) + solve(a-3,b-1,dp) + solve(a-2,b-2,dp) + solve(a-1,b-3,dp));
        return dp[a][b];
        
    }
    
    double soupServings(int n) {
        if(n>=4800){
            return 1;
        }
        int N = n/25;
        if(n%25){
            N++;//servings
            
        }
        vector<vector<double>>dp(200,vector<double>(200,-1));
        
        
        return solve(N,N,dp);
        
        
    }