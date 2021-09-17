#include<bits/stdc++.h>
using namespace std;

  int lcs(string &s1 , string &s2  , int i , int j,int dp[1001][1001] ){
	        
	        if(i >= s1.length() || j >= s2.length()){
	            return 0;
	        }
	        
	        
	        if(dp[i][j]!=-1){
	            return dp[i][j];
	        }
	       
	        
	        //favourable case
	        int ans =0;
	        if(s1.at(i) == s2.at(j) && i!=j ){
	            int smallAns = lcs(s1,s2 , i+1 , j+1,dp);
	            ans = smallAns + 1 ;
	        }else{
	            int case1 = lcs(s1,s2,i+1,j ,dp);
	            int case2 = lcs(s2,s2,i,j+1,dp);
	            ans = max(case1,case2);
	        }
	        dp[i][j] = ans;
	        return ans;
	        
	    }

        int lcs_dp(string &s1 , string &s2  ){

            int **dp = new int*[s1.length()+1];
            for(int i = 0 ; i < s1.length() +1 ; i++){
                dp[i] = new int[s2.length() +1];
                for(int j =  0 ; j < s2.length()  + 1 ; j++){
                    dp[i][j] = 0;
                }
            }

            ///dp[i][j] stpres the max subseq from substring s1(i) and s2(j) such that the common qlemnts do  not have same indexes

            for(int i = s1.length()-1; i>=0 ; i--){
                for(int j = s2.length()-1 ; j>=0 ; j--){

                        if(s1[i] == s2[j] && i!=j){
                            dp[i][j] = dp[i+1][j+1]+1;
                        }else{
                            dp[i][j] = max(dp[i][j+1] , max(dp[i+1][j],dp[i+1][j+1]));
                        }

                }
            }

            int ans = dp[0][0];
            for(int i = 0 ; i < s1.length() +1 ; i++){
                delete [] dp[i] ;
            }
            delete [] dp;

            return ans;
	        
	    }
	//the logic behin the qn is taht we fifn the lcs betwene these two strings such that index of the indentixal charcters in the original array must not be the same
		int LongestRepeatingSubsequence(string str){
		    // Code here
		    
		    int dp[1001][1001];
		    
		    for(int i = 0 ; i<str.length() ; i++){
		        for(int j =0; j < str.length() ; j++){
		            dp[i][j] = -1;
		        }
		    }
		    
		    
		    // return lcs(str,str,0,0,dp);
            return lcs_dp(str , str);
		    
		}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    int T=0;
    cin>>T;
    while(T--){

        string s{""};
        cin>>s;

    }

}