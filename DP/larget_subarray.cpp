#include <bits/stdc++.h>
using namespace std;
#define modVal 1000000007
#define ll long long


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

        int n =0;
        cin>>n;
        vector<int>vec(n+1,0);
        for(int i =0;i<n;i++){
            cin>>vec[i];
        }
        int ans = INT_MIN;
        vector<vector<int>>dp(n,vector<int>(2,1));
        for(int i = dp.size()-2;i>=0;i--){
            int same = 1;
            int incr = 1;
            //same
            if(vec[i] == vec[i+1]){
                same = max(dp[i+1][0] + 1,same);
                incr = max(dp[i+1][1] + 1,incr);
            }
            if(vec[i] == vec[i+1] + 1){
                same = max(dp[i+1][1] + 1,same);
            }
            if(vec[i] + 1== vec[i+1]){
                incr = max(dp[i+1][0] + 1,incr);
            }
            dp[i][0] = same;
            dp[i][1] = incr;
            ans = max(ans,max(same,incr));
        }

        cout<<ans<<"\n";
    }

}