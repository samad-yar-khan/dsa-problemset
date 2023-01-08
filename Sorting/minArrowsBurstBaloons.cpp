#include<bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

/*
The logic here is to sort the pairs, by first and second values
as we iterate through the list, we make the window according to the next added baloon
we take the max of the left range and min of right range to make a correct window for legit overlaps and avoid double counting of a baloon in two segments or counting of a balloon in non fitting segment
*/
    
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        if(n<=1){
            return n;
        }
        vector<pair<int,int>>vec;
        for(int i =0;i<n;i++){
            vec.push_back(make_pair(points[i][0],points[i][1]));
        }
        sort(vec.begin(),vec.end());
        int cnt =1;
        int l = vec[0].first;
        int r = vec[0].second;
        int i =1 ;
        while(i<n){
            int l_ = vec[i].first;
            int r_ = vec[i].second;
            if(l_>r){
                l=l_;r=r_;cnt++;
            }else{
                l=max(l,l_);
                r=min(r,r_);
            }
            i++;
        }
        return cnt;
    }