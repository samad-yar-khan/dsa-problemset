#include<bits/stdc++.h>
using namespace std;

//https://binarysearch.com/problems/Minimum-Size-of-Two-Non-Overlapping-Intervals

int upperBound(vector<vector<int>>& intervals,vector<int>&minDis, int a){
    int i =0;
    int j = intervals.size()-1;
    int ans = -1;

    while(i<=j){
        int mid = i+j;
        mid/=2;
       
            if(intervals[mid][0] <= a){
                i = mid+1;
            }else{
                ans = minDis[mid] ;
                j = mid-1;
            }
        
    }
    return ans;
}

int solve(vector<vector<int>>& intervals) {
    int n= intervals.size();
    sort(intervals.begin(),intervals.end());
    vector<int>minDis(n,0);
    int currMin = INT_MAX;
    for(int i =n-1;i>=0;i--){
        currMin = min(currMin,intervals[i][1]-intervals[i][0]+1);
        minDis[i] = currMin;
    }
    int ans =INT_MAX;

    for(int i =0;i<n;i++){
        int curr = intervals[i][1] - intervals[i][0] + 1;
        int f = upperBound(intervals, minDis,intervals[i][1]);
        if(f==-1){
            continue;
        }
        curr = curr +f; 
        ans = min(ans,curr);
    } 
    return ans==INT_MAX?0:ans;
 }
