#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/longest-path-with-different-adjacent-characters/

    pair<int,int> dfs(vector<vector<int>>&g, vector<bool>&vis, int c, string &s){
        if(vis[c]){
            return {0,0};
        }
        vis[c] = true;
        int m =1;
        int cc =1;
        int frst=-1;
        int sec = -1;
        for(int i =0;i<g[c].size();i++){
            if(vis[g[c][i]]){
                continue;
            }
            pair<int,int> mm = dfs(g,vis,g[c][i],s);
            m = max(max(mm.first,mm.second),m);
            if(s[g[c][i]] !=s[c]){
                cc=max(cc,mm.second+1);
                if(frst==-1){
                    frst = mm.second;
                }else if(sec==-1){
                    sec = mm.second;
                    if(frst<sec){
                        swap(frst,sec);
                    }
                }else{
                    if(mm.second>frst){
                        sec = frst;
                        frst = mm.second;
                    }else if(mm.second> sec){
                        sec= mm.second;
                    }
                }
                
            }
        }
        
        int ind =0;
        int ccc=1;
        if(frst>-1){
            ccc+=frst;
        }
        if(sec > -1){
            ccc+=sec;
        }
        m=max(m,ccc);
        return {m,cc};
        
    }
    
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>>g(n,vector<int>(0));
        vector<bool>vis(n,0);
        for(int i =0;i<n;i++){
            if(parent[i]>=0){
                g[parent[i]].push_back(i);
            }
        }
       
        return dfs(g,vis,0,s).first;
    }