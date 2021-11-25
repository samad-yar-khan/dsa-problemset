#include<bits/stdc++.h>
using namespace std;

//https://practice.geeksforgeeks.org/problems/detect-cycle-in-a-directed-graph/1#

//forcycle in a dg we nee dto maintain two visited arrays , one to maintains if its  been visited before 
//othe rto maintain if we have visted it going down, while going upo we reset this one

bool dfs(int cv , int V,vector<int> adj[],vector<bool> &vis , vector
    <bool> &down){
        
        if(down[cv]){
            return true;
        }
        
        down[cv]=true;
        vis[cv]=true;
        
        for(int i =0;i<adj[cv].size() ;i++){
            int v = adj[cv][i];
            if(down[v]){
                down[cv]=false;
                return true;
            }
            if(vis[v]){
                continue;
            }
            bool found=dfs(v,V,adj,vis,down);
            if(found){
                down[cv]=false;
                return true;
            }
        }
        down[cv]=false;
        return false;
        
    }
    
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool> vis(V,false);
        vector<bool> down(V,false);
        for(int i =0;i<V;i++){
            if(!vis[i]){
                bool found= dfs(i,V,adj,vis,down);
                if(found){
                    return found;
                }
            }
        }
       return false;
    }