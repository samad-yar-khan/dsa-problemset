#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/binary-trees-with-factors/

long modVal = 1e9 + 7;;
    int numFactoredBinaryTrees(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int n = arr.size();
        long long total_sum =1;
        vector<long long>dp(n,0);
        dp[0] = 1;
        for(int i =1;i<n;i++){
            int j = 0;int k = i-1;
            long long ans = 1;
            while(j<=k){
                long long a = arr[j];
                long long b = arr[k];
                long long product = a*b;
                long long curr = arr[i];
               
                if(curr == product){
                    
                    if(j==k){
                        ans = (ans + (dp[j]*dp[k]))%modVal;
                    }else{
                        long long two = 2;
                        ans = (ans + (dp[j]*dp[k]*two)%modVal)%modVal;
                    }
                    j++;k--;
                }else if(curr<product){
                    k--;
                }else{
                    j++;
                }
            }

            total_sum = ((total_sum) + ans)%modVal;
            dp[i] = ans%modVal;
        }
        return total_sum;
    }