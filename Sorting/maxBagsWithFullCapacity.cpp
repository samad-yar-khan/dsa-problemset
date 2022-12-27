#include<bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/maximum-bags-with-full-capacity-of-rocks/
 int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int>diff(capacity.size(),0);
        int n = capacity.size();
        for(int i =0;i<n;i++){
            diff[i]=capacity[i]-rocks[i];
        }
        sort(diff.begin(),diff.end());
        int ans=0;
        for(int i =0;i<n && additionalRocks>=0;i++){
            additionalRocks-=diff[i];
            if(additionalRocks>=0){
                ans++;
            }
        }
        return ans;
        

    }