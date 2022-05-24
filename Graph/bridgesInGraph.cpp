#include<bits/stdc++.h>
using namespace std;

//refer striver vid

//https://leetcode.com/problems/critical-connections-in-a-network/

 int dfs(vector<vector<int>>&g, int i,int p, vector<int>&in,vector<int>&min_in,int time,vector<vector<int>>&e){
        
        if(in[i]!=INT_MAX){
            return time;
        }
        in[i] = time;
        min_in[i] = time;
        int t=time;
        for(int itr =0;itr<g[i].size();itr++){
            if(g[i][itr]!=p){
                if(in[g[i][itr]]==INT_MAX){
                    t=dfs(g,g[i][itr],i,in,min_in,t+1,e);    
                }
                min_in[i]=min(min_in[i],min_in[g[i][itr]]);
                if(in[i]<min_in[g[i][itr]]){
                    vector<int>v;
                    v.push_back(i);
                    v.push_back(g[i][itr]);
                    e.push_back(v);
                }
            }
        }
        return t;
    }
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>>graph(n,vector<int>(0));
        for(int i =0;i<connections.size();i++){
            int a = connections[i][0];
            int b = connections[i][1];
            graph[a].push_back(b);
            graph[b].push_back(a);
        }
        
        vector<int>in(n,INT_MAX);
        vector<int>min_in(n,INT_MAX);
        vector<vector<int>>e;
        int a = dfs(graph,0,-1,in,min_in,1,e);
        return e;
    }