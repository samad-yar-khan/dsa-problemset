#include<bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/longest-consecutive-sequence/submissions/
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        for(int i=0;i<nums.size();i++){
            st.insert(nums[i]);
        }
        int ans = 0;
        for(int i =0;i<nums.size();i++){
            if(st.find(nums[i])!=st.end()){
                int curr = nums[i];
                int prev = curr-1;
                int next = curr + 1;
                int pc=0;
                int nc=0;
                while(st.find(prev)!=st.end()){
                    st.erase(prev);
                    prev--;
                    pc++;
                }
                 while(st.find(next)!=st.end()){
                    st.erase(next);
                    next++;
                    nc++;
                }
                st.erase(curr);
                ans=max(ans, nc+pc+1);
            }
        }
        return ans;
     
    }