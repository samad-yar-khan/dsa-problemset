#include<bits/stdc++.h>
using namespace std;
#define ll long long

int LIS(vector<int> arr){
    
    int n = arr.size();

    //so wwe make a dp
    ///dp[i] store the best ending or minimun ending for a increaing subseq of lenbgth i

    vector<int> dp(n+1,INT_MAX);
    dp[0] = INT_MIN;//becasue we domt need a  lis of len 0

    //for each element , we piut it a posn where 
    //dp[i] < A < dp[i+1] and swap dpp[i+1] with A

    // for(int i=0;i < n ; i++){
    //     for(int len = 0 ; len <n ; len++ ){
    //         if(dp[len] < arr[i] && arr[i] <dp[len+1] ){
    //             dp[len+1] = arr[i];
    //         }
    //     }
    // }

    //we use the exact same approach but isntead of using a linear aproach to find a space
    //where dp[i] < A < dp[i+1] , we can use binary search as the seq in monotonous 

    for(int i=0;i < n ; i++){
        
        int len = upper_bound(dp.begin() , dp.end() , arr[i]) - dp.begin();
        if(dp[len-1] < arr[i] && arr[i] <dp[len] ){
            dp[len] = arr[i];
        }
      
    }

    int ans = -1;
    for(int i = 1 ; i <=n ; i++){
        if(dp[i]!=INT_MAX){
            ans = i;
        }
    }
    return ans;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r" , stdin);
        freopen("output.txt", "w", stdout);
    #endif

    int T=0;
    cin>>T;
    while(T--){
        int n = 0 ;
        cin>>n;
        vector<int> arr;
        for(int i = 0;i < n ;i++){
            int a = 0;
            cin>>a ;
            arr.push_back(a);
        }
        cout<<LIS(arr)<<"\n";
    }


    return 0;

}