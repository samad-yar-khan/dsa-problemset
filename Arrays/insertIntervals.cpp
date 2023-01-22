#include<bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/insert-interval/
 vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>>vec;
        bool in =0;
        for(int i =0;i<intervals.size();i++){
            if(!in && newInterval[0]<=intervals[i][0]){
                in = true;
                vec.push_back(newInterval);
            }
            vec.push_back(intervals[i]);
        }
        if(!in){
            vec.push_back(newInterval);
        }
        int i =0;
        vector<vector<int>>ans;
        while(i<vec.size()){
            int j =i;
            int si = vec[i][0];
            int ei = vec[i][1];
            while(j<vec.size() && vec[j][0]<=ei){
                ei = max(ei,vec[j][1]);
                j++;
            }
            i=j;
            ans.push_back(vector<int>{si,ei});
        }
        return ans;
    }