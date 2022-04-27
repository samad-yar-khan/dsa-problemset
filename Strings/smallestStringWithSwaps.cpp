#include<bits/stdc++.h>
using namespace std;

//we see the string as seperate component on a graph and sort those indiviudal components
//https://leetcode.com/problems/smallest-string-with-swaps/
   void dfs(int curr, vector<vector<int>>&g , vector<bool>&vis, vector<int>&seg,int ind,vector<int>&segment){
            
        if(vis[curr]){
            return;
        }
        segment.push_back(curr);
        vis[curr] = true;
        seg[curr] = ind;
        for(int i =0;i<g[curr].size();i++){
            if(!vis[g[curr][i]])
            {
                dfs(g[curr][i],g,vis,seg,ind,segment);
            }
        }
        
    }
    
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int len = s.length();
        int ps = pairs.size();
        vector<vector<int>>g(len,vector<int>(0));
        for(int i =0;i<ps;i++){
            int a = pairs[i][0];
            int b = pairs[i][1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        vector<bool>vis(len,false);
        vector<int>seg(len,0);
        int seg_no=0;
        vector<vector<int>>inds;
        for(int i =0;i<len;i++){
            if(!vis[i]){
                vector<int> segment;
                dfs(i,g,vis,seg,seg_no++,segment);
                sort(segment.begin(),segment.end());
                inds.push_back(segment);
            }
        }
        
        for(int i =0;i<inds.size();i++){
            string temp{""};
            for(int j =0;j<inds[i].size();j++){
                temp+=(s[inds[i][j]]);
            }
           
           
            sort(temp.begin(),temp.end());
            for(int j =0;j<inds[i].size();j++){
                s[inds[i][j]]=temp[j];
            }
        }
        
        
        return s;
    }