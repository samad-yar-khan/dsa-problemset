//https://practice.geeksforgeeks.org/problems/nth-catalan-number0817/1
// #include <boost/multiprecision/ull.cpp>
// using boost::multiprecision::ull;
#include<bits/stdc++.h>
using namespace std;
#define modVal 1000000007
#define ll long long
#define ull unsigned  long long

//used to find - num of bsts , bts , bt structurs

//catlan numbers

/*
    Cn=sum(i=0 to n-1)C(i)C(n-1-i)
    C(0) = 1 
    C(1) = 2
*/

 ull solve(int n , ull dp[] ){
        
        if(n<=1){
            
            ull ans = 1;
            return ans;
            
        }
        ull zero=0;
        if(dp[n]>zero){
            return dp[n];
        }
        ull ans =0;
        for(int i = 0 ;i < n ; i++){
            ull temp = solve(i,dp)*solve(n-i-1,dp);
            ans+=temp;
        }
        
        dp[n] = ans;
        return dp[n];
    }
    
    ull findCatalan(int n) 
    {
        //code here
        ull z=1;
        ull dp[101] = {0};
        dp[0] = 1 ;
        dp[1] = 1;
        //we can do this using iteratie dp also

        for(int i  = 2 ; i <= n ; i++){
            ull ans =0;
            for(int j = 0; j < i ; j++){
                ans += (dp[j]*dp[i-1-j]);
            }
            dp[i] = ans;
        }


        // ull ans = solve(n , dp);
        ull ans =  dp[n];
        return ans;
    }

//the  direct formula for nth catalan number is 2ncn
ull findCatalan_fomula(int n ){

    //2nCn/n+1 
    
    ull two_n_fact = 1;
    ull n_fact = 1;

    for(int i = 1 ; i <= 2*n ; i++){
        two_n_fact*=i;
    }
    
    
    for(int i = 1 ; i <= n ; i++){
        n_fact*=i;
    }

    ull ans = (two_n_fact/(n_fact*n_fact));
    ans/=(n+1);
    return ans;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r" , stdin);
        freopen("../output.txt", "w", stdout);
    #endif
    

    int T= 0 ;
    cin>>T;
   
    while(T--){
        int n = 0 ;
        cin>>n;
        ull ans = findCatalan_fomula(n);
        cout<<ans<<"\n";
    }

}