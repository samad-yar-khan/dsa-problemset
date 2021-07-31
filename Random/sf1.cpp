// Given N boxes containing different number of Books in each box(numBook[i]),take a minimum number of books from the boxes conditions are such that:

// you must take either all or none of the books inside a given box.
// you cannot skip taking books from boxes adjacent to each other.Box1 and 2 can not be skipped but you can skip box 1 and 3.
// you must have a minimum number of books in your hand
// for example ,if there are 6 boxes and the number of books in box are {7,2,13,12,9,1} then the minimum number of books u can take is 15(by skipping box 1,3,5).

// 0>N>100

// numBook[i]<10000

#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T=0;
    cin>>T;
    while(T--){

        int n = 0;
        cin>>n;
        int arr[100] = {0};
        for(int i = 0 ;i<n ; i++){
            cin>>arr[i];
        }

        int dp[100] = {0};
        dp[0] = 0;
        dp[1] = 0;

        for(int i =2; i <=n ; i++ ){
            int ind = n-i;
            int nInd = n-i+1;
            int case1 = arr[ind] + dp[i-1];
            int case2 = arr[nInd] + dp[i-2];

            dp[i] = min(case1 , case2);

        }

        cout<<dp[n]<<"\n";

    }
}