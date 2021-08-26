#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long int
using namespace std;

/*
brute force recursiive approach
the probelem was that we had n people and we   can either makes pairs of two of some or we can leave them 
as they please
for 3 friend
F1 F2 F3
therw can be 4 ways 
1){ F1 , F2 , F3 } // no pairs
2){ (F1,F2) , F3 }
3){ (F1,F3) , F2 }
4){ F1 , (F2,F3) }

//so of we have n freidns , we will only work on the first freind

case1 
we can pair it with non of the freidns and see how the (n-1) pair sof freidns can be made
case2
here we can actally pair our friend with any ofnthe left n-1 friends and see how the how thw rest ofthe freind are pairs
so F1 can be pairs with F2 and we add the and of pairing levfotver one friend F3
or F1 can be paires with F3 and we calucllated how to apir rets of the feisnd F2

basically we pairs our with each of the left n-1 feiends and see how the left over n-2 feinnds can bepaied with each otehr
T(n-2) + T(n-2).. and so on
so case2 is just (n-1)*(T(n-2))

*/
int rec(int n){
            
        if(n==1||n==0){
            return 1;
        }
        if(n<0){
            return 0;
        }
        
        //i will only work on thre first two
        int c1 = rec(n-1);//dont pair
        int c2 = (n-1)*rec(n-2);
        
        return c1+c2;
}

//memoizsaton
#define ll long long int
ll memo_imp(int n , ll*dp){

    //base case 
    //we will will hit it at the end
    if(n==1 || n==0){
        return 1;
    }
    //edge case
    //edge because it may come at some point
    if(n<0)
    {
        return 0;
    }

    //checl if aready have the ans or not
    if(dp[n]!=-1){
        return dp[n];
    }


    //we dont have the anwe at thisplace
    ll c1 = memo_imp(n-1,dp)%mod;//dont pair
    ll c2 = (n-1)*memo_imp(n-2 ,dp)%mod;

    dp[n] = (c1+c2)%mod;
}

ll memo(int n ){

    ll*memo=new ll[n+1];

    //memo[i] i sbasicllay the numbe rof ways to couple i friends 

    for(int i= 0 ; i <= n ; i++){
        memo[i] = -1; 
    }

    int ans = memo_imp( n , memo)%mod;
    delete [] memo;//there is no garbage colleected like in java so we must deaalovatte the memory ourseves
    return ans;
}

//dp
//O(N) time and O(N) space
ll dp(int n ){

    ll*dp=new ll[n+1];

    //memo[i] i sbasicllay the numbe rof ways to couple i friends 

    for(int i= 0 ; i <= n ; i++){
        dp[i] = -1; 
    }

    dp[0] = 1;
    dp[1] = 1;
    
    for(int i = 2 ; i <= n ; i++){
        dp[i] = (dp[i-1] + (i-1)*(dp[i-2]))%mod;
    }
    int ans = dp[n];
    delete [] dp;//there is no garbage colleected like in java so we must deaalovatte the memory ourseves
    return ans;
}

// optimised dp with o(1) spacee
//our  recurrrance relation is T(N) = T(N-1) + (N-1)*T(N-2);
// we only need to wavalues
ll betterDp(int n){

    ll C1=1;//dp[0]
    ll C2=1;//dp[1]

    for(int i = 2 ; i <= n ; i++){

        ll temp = (C2 + C1*(i-1))%mod;
        C1 = C2;
        C2 = temp;
    }

    return C2;

}   

