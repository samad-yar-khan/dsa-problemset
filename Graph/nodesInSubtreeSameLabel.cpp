#include<bits/stdc++.h>
using namespace std;


    //we maintain a freq of all charcters from the child nodes and add to them as they come up and decide answers upon dfs
    
    vector<int> dfs(vector<vector<int>>&g, vector<bool>&vis, int cn,vector<int>&ans, string&l ){
        if(vis[cn]){
            vector<int>f(26,0);
            return f;
        }
        vis[cn]  =true;
        vector<int>f(26,0);
        for(int i=0;i<g[cn].size();i++){
            if(vis[g[cn][i]]){
                continue;
            }
            vector<int>ff = dfs(g,vis,g[cn][i],ans,l);
            for(int j =0;j<26;j++){
                f[j]+=ff[j];
            }
        }
        f[l[cn]-'a']++;
        ans[cn] = f[l[cn]-'a'];
        return f;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>>g(n,vector<int>(0));
        vector<bool>vis(n,0);
        for(int i =0;i<edges.size();i++){
            int a=edges[i][0];
            int b = edges[i][1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        vector<int>ans(n,0);
        dfs(g,vis,0,ans,labels);
        return ans;
    }


//not forming an array each time, beats 99%
    void dfs_OP(vector<vector<int>>&g, vector<bool>&vis, int cn,vector<int>&ans, string&l, vector<int>&f ){
        if(vis[cn]){
            return;
        }
        int pc =  f[l[cn]-'a'];//prev count
        vis[cn]  =true;
        for(int i=0;i<g[cn].size();i++){
            if(vis[g[cn][i]]){
                continue;
            }
            dfs(g,vis,g[cn][i],ans,l,f);
        }
        f[l[cn]-'a']++;
        ans[cn] = f[l[cn]-'a']-pc;//we only need the counts added by children, so we subtract prev count 
    
    vector<int> countSubTrees_OP(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>>g(n,vector<int>(0));
        vector<bool>vis(n,0);
        for(int i =0;i<edges.size();i++){
            int a=edges[i][0];
            int b = edges[i][1];
            g[a].push_back(b);
            g[b].push_back(a);
        }
        vector<int>ans(n,0);
        vector<int>f(26,0);
        dfs(g,vis,0,ans,labels,f);
        return ans;
    }