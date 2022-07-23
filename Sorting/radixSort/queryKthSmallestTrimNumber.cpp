#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/query-kth-smallest-trimmed-number/
/*
    The most optimized solution is to sort the queries based on the length of the leftOver suffix
    then we use radix sort to sort the characters from the end as done in radex sort, and each iteration
    suffix of length len will be sorted, we check if query for length is present, and we store the answer 
*/

    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<pair<int, pair<int,int>>>qs;
        for(int i =0;i<queries.size();i++){
            qs.push_back(make_pair(nums[0].length()-queries[i][1],make_pair(queries[i][0],i)));
        }
        vector<int> ans(queries.size(),0);
        vector<pair<string,int>>sortedRes;
        int pos = nums[0].length()-1;
        for(int i=0;i<n;i++){
            sortedRes.push_back({nums[i],i});
        }
        vector<pair<string,int>>sorted(n,{"",0});
        sort(qs.begin(),qs.end());
        int len = nums[0].length() - 1;
        int j = qs.size() - 1;
        while(len>=0 && j >=0 ){
            vector<int>f(10,0);
            for(int i = 0 ; i < sortedRes.size() ; i++){
                f[sortedRes[i].first.at(len)-'0']++;
            }
            int sum = -1;
            for(int i = 0 ; i< 10;i++){
                sum += f[i];
                f[i] = sum;
            }
            for(int i = sortedRes.size()-1 ; i>=0 ; i--){
                int pos = f[sortedRes[i].first.at(len)-'0']--;
                sorted[pos] = sortedRes[i];
            }
            while(j>=0 && qs[j].first==len){
                ans[qs[j].second.second]=sorted[qs[j].second.first -1].second;
                j--;
            }
            sortedRes=sorted;
            len--;
        } 
        return ans;
    }