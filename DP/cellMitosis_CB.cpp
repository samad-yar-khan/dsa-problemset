#include <bits/stdc++.h>
using namespace std;
#define modVal 1000000007
#define ll long long
//https://hack.codingblocks.com/app/contests/1310/546/problem

ll solve( ll cells ,ll n , ll x , ll y , ll z ,ll* dp){

    // cout<<cells<<" ";
    
    if(cells == n){
        return 0;
    }
    if(cells < 0){
        return INT_MAX;
    }

    if(cells >n){
        return (cells-n)*z;
    }
    if(dp[cells] >= 0){
        return dp[cells];
    }
    
    dp[cells] = -2;

    ll c1 =INT_MAX , c2 = INT_MAX , c3 = INT_MAX;

    ll d1 = 2*cells ;
    ll d2 = cells+1;
    ll d3 = cells-1;

    if(d1>=n || (d1<=n && dp[d1]!=-2) ){
        c1 = solve(d1 ,n , x  , y , z , dp) + x;
    }  
    if(d2>=n || (d2<=n && dp[d2]!=-2) ){
        c2 = solve(d2 ,n , x  , y , z , dp) + y;
    }    
    if(d3>=0 && dp[d3] != -2){
        c3 = solve(d3 , n,x,y,z,dp)+z;
    }

    dp[cells]= min(c1 , min(c2 , c3));
    return dp[cells];
    

}

///the bottom up logic is that
/*

    when we calclate dp[i] from bottom up dp
    we look for min_of(dp[i/2] + x , dp[i-1]+y, dp[i+1]+z)
    but in bottom up we are filling our dp form left to right and while calcuaing dp[i] we cant possibly have the value of dp[i+1]
    so here we form cases 
    case 1 , when i is odd , we cant come from i/2 , we can only come from i-1 and i+1 , i-1 will be   precalculated and we wont have i+1 ka path through i ,
    so here we see ki i+1 pe hu (i+1)/2 ke through pohche and waha se ham peeche aye 

    case 2 ,when i is even , we can reach through i/2 or i-1 , but we cant reach through i+1 , because i+1 , ke through ana hamesha costlly hoga 
    and ham  even s odd nikalde haai ,so w ecant do both

*/

ll solve_dp(ll n , ll x , ll y , ll z ,ll* dp){

   
   //start calcuating frrom dp[2]

    for(ll cells= 2 ; cells <= n ;cells++ ){

        if(cells%2==0){

            ll c1 = dp[cells/2] + x;
            ll c2 = dp[cells-1] + y;
            dp[cells] = min(c1 , c2);

        }else{

    
            ll c1 = dp[cells-1] + y;
            ll c2 = dp[(cells+1)/2] + x + z ;//x se ham (i+1)/2 se i+1 pe aye and then waha se peeche ane  ka cost z
            dp[cells] = min(c1 , c2);

        }

     

    }
    return dp[n];

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
        ll n =0,x= 0,y=0,z=0;
        cin>>n>>x>>y>>z;

        ll*dp = new ll[n+1];
        for(int ll i = 0; i<=n ; i++){
            dp[i] = 0;
        }
        cout<<solve_dp(n ,x,y,z,dp)<<"\n";
        delete [] dp;

    }

}