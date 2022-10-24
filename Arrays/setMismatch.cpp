#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/set-mismatch/submissions/
vector<int> findErrorNums(vector<int>& nums) {

        long long sum =0;
        long long n = nums.size();
        long long squareSum = 0;
        for(int i =0;i<nums.size();i++){
            sum+=(nums[i]*1LL);
            squareSum+=(nums[i]*nums[i]*1LL);
        }

        long long os = (n*(n+1))/2;
        long long oss = (n*(n+1)*(2*n + 1))/6;
        long long aMinusB = sum - os;
        long long aSquareMinusBSquare = squareSum - oss;
        long long aPlusB = aSquareMinusBSquare/aMinusB;

        vector<int>ans(2,0);
        ans[0] = (aPlusB+aMinusB)/2 ;
        ans[1] = (aPlusB-aMinusB)/2 ;
        return ans;   
    }