#include<bits/stdc++.h>
using namespace std;

int maxSubarraySumDp(int arr[] , int n){

    //dp will contain the max sum if we include the elemnt at ith pos
    int*dp = new int [n];

    dp[0] = arr[0];
    int ans = arr[0];

    for(int i = 1  ; i < n ; i++){
        //we take the max till i+1 and add our number to it
        int case1 = arr[i] + dp[i-1];
        //if ans becomes negavve it wont be fritotful to add it later
        //we start from our number
       int case2 = arr[i];
        dp[i] = max(case1 , case2) ;
        ans = max(ans , dp[i]);
    }
    delete [] dp;
    return ans;
}

//space optiimised dp
int kadanes(int *arr , int n){

    //we only need the previous number or prev sum
    int currSum = arr[0];
    int maxSum = arr[0];

    for(int i = 1 ; i< n ; i++){

        int case1 =arr[i]+currSum;
        int case2 = arr[i];

        currSum=max(case1,case2);
        maxSum =  max(case1 , case2);
    }

    return maxSum;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t = 0 ;
    cin>>t;
    while(t--){ 

        int n = 0 ;
        cin>>n;

        int*arr= new int[n];

        for(int i = 0 ; i < n ; i++){
            cin>>arr[i];
        }

        cout<<kadanes(arr , n)<<'\n';

        delete [] arr;

    }

    return 0;
}

/*

3
3
-1 -2 -3
4
1 2 3 4
5
1 2 3 -1 5


*/