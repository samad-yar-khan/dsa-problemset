#include<bits/stdc++.h>
using namespace std;
//https://practice.geeksforgeeks.org/problems/maximum-profit4657/1#


//memoisation
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


    //chnaging the approach to the question
    //we look for  a dp[k][d] which reprsnets the profit we can  ammak eif we sell k stocks by dth day

int maxProfitDP1(int K, int N, int A[]) {
        // code here
        
        int**profit = new int *[K+1];
        for(int i = 0 ; i<=K ; i++){
            profit[i] = new int[N];
            for(int j = 0 ; j <N ; j++){
                profit[i][j] = 0 ;
            }
        }

        //first row and col will be zero
        //FR -> Because you cant make any profit by selling 0 stocks
        //FC -> Becase even by making a a 100 transacrtion in same dday net profit will be zero
    
        for(int k = 1 ; k <= K ; k++){
            //either ans will be by seling k stocks on day before
            //what we neeed yp chec is ki aagar mai mujhse pehle wwale sare days mai k-1 bechdu and us din se apna transaction karu to kya max profit hoga
            //this profit calcucation would have otherwise taken a loop going from 0 to days-1 each time but it is optimised by taking a max value
            //proit would be = profitBySelling K-1 products from day0 to days[x] + price[days] - days[x] (X:0 -> N)
          
            for(int days = 1 ; days < N ; days ++){

                int maxP = profit[k][days-1];      
                for(int d=0 ; d < days ; d++){

                    int temp=profit[d][k-1] + (A[days] - A[d]);
                    maxP = max(maxP,temp);
                }
            }
        }

        int ans = profit[K][N-1];
        for(int i = 0 ; i<=K ; i++){
            delete [] profit[i] ;
        }
        delete [] profit;
        return ans;
    }


 int maxProfitDP2(int K, int N, int A[]) {
        // code here
        
        int**profit = new int *[K+1];
        for(int i = 0 ; i<=K ; i++){
            profit[i] = new int[N];
            for(int j = 0 ; j <N ; j++){
                profit[i][j] = 0 ;
            }
        }

        //first row and col will be zero
        //FR -> Because you cant make any profit by selling 0 stocks
        //FC -> Becase even by making a a 100 transacrtion in same dday net profit will be zero
    
        for(int k = 1 ; k <= K ; k++){
            //either ans will be by seling k stocks on day before
            //what we neeed yp chec is ki aagar mai mujhse pehle wwale sare days mai k-1 bechdu and us din se apna transaction karu to kya max profit hoga
            //this profit calcucation would have otherwise taken a loop going from 0 to days-1 each time but it is optimised by taking a max value
            //proit would be = profitBySelling K-1 products from day0 to days[x] + price[days] - days[x] (X:0 -> N)
            int maxProfit=profit[k-1][0] - A[0];
            for(int days = 1 ; days < N ; days ++){
                maxProfit= max(profit[k-1][days-1] - A[days-1], maxProfit);
                profit[k][days] = max(profit[k][days-1]  , maxProfit + A[days]);
            }
        }

        int ans = profit[K][N-1];
        for(int i = 0 ; i<=K ; i++){
            delete [] profit[i] ;
        }
        delete [] profit;
        return ans;
    }

    //compplete 
    //do
    //https://leetcode.com/problems/best-position-for-a-service-centre/
    //https://leetcode.com/problems/minimize-deviation-in-array/
    //https://leetcode.com/problems/maximum-profit-in-job-scheduling/
    //https://www.geeksforgeeks.org/weighted-job-scheduling/
    //