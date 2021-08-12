#include<bits/stdc++.h>
using namespace std;

//memoization
/*
similiar to lcs but here we need to know the max substr starting from each index 
if max sattrtng from each index as well as the max ooveral subtr from that index
*/


    pair<int , int> solve(string& s1 , string& s2 , int n , int m ,int i , int j, pair<int , int>dp[1001][1001]){
        
        //base case
        if(i>=n || j>=m){
            pair<int , int > ans(0,0);
            return ans ;
        }
        
        if(dp[i][j].first !=  -1){
            return dp[i][j];
        }
        
        if(s1.at(i) == s2.at(j)){
            
            pair<int,int> case1 = solve(s1 , s2, n,m ,i+1,j+1, dp);
            pair<int,int> case2 =solve(s1 , s2 , n , m,i+1,j , dp);
            pair<int,int> case3 = solve(s1 , s2, n , m,i,j+1 ,dp);
            
            if(case1.first<0){
                case1.first = 1;
            }else{
                case1.first +=1;
            }
           

            dp[i][j].first = case1.first;
            dp[i][j].second = max(max(case1.second,case1.first) , max(case2.second , case3.second));
            return dp[i][j];
        }else{
            
            pair<int,int> case2 ;
            pair<int,int> case3  ;
            
              
            case2 =solve(s1 , s2 , n , m ,i+1,j, dp);
            case3 = solve(s1 , s2, n , m,i,j+1 ,dp);
            
            dp[i][j].second =max(case3.second , case2.second);
            dp[i][j].first = 0;
            return dp[i][j];
        }
        
        
    }
    
    int longestCommonSubstr (string S1, string S2, int n, int m)
    {
        // your code here
       pair<int,int>arr[1001][1001];
        for(int i = 0 ; i<=n ;i++){
            for(int j = 0 ;  j <= m ; j++){
                pair<int , int >p(-1,-1);
                arr[i][j] = p;
            }
        }
        int ans= solve(S1 , S2 , n , m ,0,0, arr).second;
    
        return ans;
    }

//dp approach


int longestCommonSubstrDP (string S1, string S2, int n, int m)
    {
        // your code here
          // your code here
       pair<int,int>arr[1001][1001];
        for(int i = 0 ; i<=n ;i++){
            for(int j = 0 ;  j <= m ; j++){
                pair<int , int >p(0,0);
                arr[i][j] = p;
            }
        }

        for(int i = n-1 ; i >= 0 ;i--){
            for(int j = m-1 ; j>=0 ; j--){

                if(S1[i] == S2[j]){

                    pair<int , int> case1  = arr[i+1][j+1];
                    pair<int , int> case2  = arr[i+1][j];
                    pair<int , int >case3=arr[i][j+1] ;

                    case1.first+=1;

                    pair<int,int> ans;
                    ans.first = case1.first;
                    ans.second = max(max(case1.first , case1.second ), max(case2.second , case3.second));
                        
                    arr[i][j] = ans;

                }else{

                    pair<int , int> case2  = arr[i+1][j];
                    pair<int , int >case3=arr[i][j+1] ;
                    arr[i][j].second = max(case2.second  , case3.second);
                    
                }

            }
        }

        return arr[0][0].second;
    }


int longestCommonSubstrDP (string S1, string S2, int n, int m){
       int arr[1001][1001];
        for(int i = 0 ; i<=n ;i++){
            for(int j = 0 ;  j <= m ; j++){
                arr[i][j] = 0;
            }
        }
        int ans = 0 ;
        for(int i = n-1 ; i >= 0 ;i--){
            for(int j = m-1 ; j>=0 ; j--){
                if(S1[i] == S2[j]){
                    arr[i][j] = arr[i+1][j+1] +1;
                    ans = max(ans,arr[i][j]);
                }
            }
        }
        return ans;
}
