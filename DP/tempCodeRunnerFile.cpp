#include <bits/stdc++.h>
using namespace std;
#define modVal 1000000007
#define ll long long


ll solve( ll cells ,ll n , ll x , ll y , ll z ,ll* dp){

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

    return min(c1 , min(c2 , c3))l
    

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
            dp[i] = -1;
        }
        cout<<solve(1,n ,x,y,z,dp)<<"\n";
        delete [] dp;

    }

}