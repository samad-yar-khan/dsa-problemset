#include<bits/stdc++.h>
using namespace std;
//https://practice.geeksforgeeks.org/problems/maximum-profit4657/1#

int profit(int K , int N , int A[] , int sell , int moneySpent,pair<int , int> dp[502][202][2] ){
        
        if(N==0 || (K==0 && sell==0)){
            return 0;
        }
        
        if(sell == 1){
            if(dp[N][K][sell].first !=-1 && dp[N][K][sell].first < moneySpent){
            return dp[N][K][sell].second;
            }      
        }
        if(sell == 0 && dp[N][K][sell].second!=-1){
            return dp[N][K][sell].second;
        }
      
        
        if(sell == 1){
            if(moneySpent > A[0]){
                return profit(K , N-1 , A +1 , sell , moneySpent,dp);
            }else{
                
                int case1 = profit(K , N-1 , A +1 , 1 , moneySpent,dp);
                //add the profit first and sell teh first
                int case2 = A[0] - moneySpent;
                case2+=(profit (K , N-1, A+1, 0 , 0,dp));
                dp[N][K][sell].first = moneySpent;
                dp[N][K][sell].second = max(case1 , case2);
           
            }
        }else{
            
            //dont buy
            int case1 = profit(K , N-1 , A + 1 , 0, moneySpent,dp);
            int case2 = profit(K-1 , N-1 , A+1 , 1 , A[0] ,dp);
            
            dp[N][K][sell].second = max(case1 , case2);
            
            
        }
        return  dp[N][K][sell].second;
        
    }
    
    int maxProfit(int K, int N, int A[]) {
        // code here
        
        pair<int , int> dp[502][202][2];
        
        for(int i = 0 ; i <= N ; i++){
            for(int j = 0; j <= K ; j++){
                for(int k = 0 ; k < 2 ; k++){
                    dp[i][j][k] = make_pair(-1,-1);
                }
            }
        }
        
        return profit(K , N , A , 0 , 0 , dp);
    }

    //compplete 
    //do
    //https://leetcode.com/problems/best-position-for-a-service-centre/
    //https://leetcode.com/problems/minimize-deviation-in-array/
    //https://leetcode.com/problems/maximum-profit-in-job-scheduling/
    //https://www.geeksforgeeks.org/weighted-job-scheduling/
    //