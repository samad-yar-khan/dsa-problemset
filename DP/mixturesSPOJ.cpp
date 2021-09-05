#include <bits/stdc++.h>
using namespace std;
#define modVal 1000000007
#define ll long long

//https://www.spoj.com/problems/MIXTURES/
//solve like MCM

int getMixSum (int a , int b , int presum []){

    int ans = 0;
    if(a==0){
        ans = presum[b]%100;
    }else{
        ans = (presum[b]%100-presum[a-1]%100+100)%100;
    }

    return ans ;
}

ll minSmokeMemo(int mix[] , int si  , int ei , int presum [] , ll smokeProduced[101][101] ){

    //one element
    //base case //only one portion
    if(si>=ei){
        return 0;
    }

    if(smokeProduced[si][ei]!=-1){
        return smokeProduced[si][ei];
    }
    //what we do is that we wish to dide the portions into two haves such that the 2 parts give th min smoke and the resultant of the two when mixed gives the minimun aswell
    ll  minSmokeProduced = INT_MAX;
    for(int  i = si ; i< ei ; i++){

     
        ll smokeProducedLeft = minSmokeMemo( mix ,  si  ,  i ,  presum ,smokeProduced);
        ll smokeProducedRight =  minSmokeMemo( mix , i+1 ,ei , presum ,smokeProduced);

        ll valMixLeft = getMixSum(si, i , presum);
        ll valMixRight = getMixSum(i+1 , ei , presum);

        ll tempSmoke=smokeProducedLeft+smokeProducedRight+(valMixLeft*valMixRight);
        minSmokeProduced = min(tempSmoke , minSmokeProduced);

    }

    smokeProduced[si][ei]= minSmokeProduced;
    return smokeProduced[si][ei];


}

ll minSmokeBrute(int mix[] , int si  , int ei , int presum []){

    //one element
    //base case //only one portion
    if(si>=ei){
        return 0;
    }

    //what we do is that we wish to dide the portions into two haves such that the 2 parts give th min smoke and the resultant of the two when mixed gives the minimun aswell
    ll  minSmokeProduced = INT_MAX;
    for(int  i = si ; i< ei ; i++){

     
        ll smokeProducedLeft = minSmokeBrute( mix ,  si  ,  i ,  presum );
        ll smokeProducedRight =  minSmokeBrute( mix , i+1 ,ei , presum );

        ll valMixLeft = getMixSum(si, i , presum);
        ll valMixRight = getMixSum(i+1 , ei , presum);

        ll tempSmoke=smokeProducedLeft+smokeProducedRight+(valMixLeft*valMixRight);
        minSmokeProduced = min(tempSmoke , minSmokeProduced);

    }

    return minSmokeProduced;


}

int minSmoke(int mix[] , int n){

    int presum[101] = {0};
    int sum=0;
    for(int i = 0 ;  i < n ; i++){
        sum+=mix[i];
        presum[i]=sum%100;
    }

    // return minSmokeBrute(mix  , 0, n-1 , presum);
    //memoization
    ll dp[101][101];
    for(int i = 0 ;i <=n ; i++){
        for(int j = 0 ;  j <=n ; j++){
            dp[i][j] = -1;
        }
    }
    return minSmokeMemo( mix , 0  , n-1 ,  presum , dp);


}

int minSmokeDP(int mix[] , int n){

    int presum[101] = {0};
    int sum=0;
    for(int i = 0 ;  i < n ; i++){
        sum+=mix[i];
        presum[i]=sum%100;
    }

    // return minSmokeBrute(mix  , 0, n-1 , presum);
    //memoization
    ll dp[101][101];
    for(int i = 0 ;i <=n ; i++){
        for(int j = 0 ;  j <=n ; j++){
            dp[i][j] = 0;
        }
    }

    // dp[i][j] -> min smoke proued in mixing chemicals from i to j
    for(int gap = 1 ; gap<n ; gap++){
        for(int i = 0 , j= gap ; i<n && j<n ; i++,j++ ){
            ll ans = INT_MAX;
            for(int partition=i ; partition < j ; partition++){
                ll leftSmoke =dp[i][partition];
                ll rightSmoke = dp[partition+1][j];
                ll valLeft = getMixSum(i,partition,presum);
                ll valRight = getMixSum(partition+1,j,presum);
                ll temp = leftSmoke+rightSmoke + (valLeft*valRight);
                ans=min(ans , temp);
            }
            dp[i][j] = ans;
        }
    }   

    ll ans = dp[0][n-1];
    return ans;

}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r" , stdin);
        freopen("../output.txt", "w", stdout);
    #endif
    

    int n = 0; 
    while(cin>>n){

        int arr[101];

        for(int i = 0 ;i < n ; i++){
            cin>>arr[i];
        }

        cout<<minSmokeDP(arr ,n)<<"\n";
       
    }

}