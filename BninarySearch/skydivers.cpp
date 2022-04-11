#include<bits/stdc++.h>
using namespace std;

// https://binarysearch.com/problems/Skydivers
// the logic is that we need to figure out the range of capacities for the plane and use binary search to optimise our answer

int days(vector<int>&nums, int cap){

    int i =0;
    int K=0;
    while(i<nums.size()){
        int j =i;
        int cc =0;
        while(cc+nums[j] <= cap){
            cc+=nums[j];
            j++;
        }
        K++;
        if(i==j){
            j++;
        }
        i=j;
    }
    return K;

}

int solve(vector<int>& nums, int k) {

    int upperLimit = 0;
    int lowerLimit = INT_MIN;
    for(int i =0;i<nums.size();i++){

        upperLimit += nums[i];
        lowerLimit = max(lowerLimit,nums[i]);

    }

    int currCap = upperLimit ;

    while(lowerLimit <= upperLimit){

        int mid = (lowerLimit + upperLimit)/2;

        int d = days(nums,mid);
        if(d <= k){
            
            upperLimit = mid-1;
            currCap=min(mid,currCap);
        }else if(d > k){    
            lowerLimit = mid+1;
        }
    }

    return currCap;


}