#include<bits/stdc++.h>
using namespace std;


bool dfs(int V, vector<int>adj[],int p , int v , bool*visited){
        
        if(visited[v]){
            return true;
        }
        
        visited[v] =  true;
        
        for(int i = 0  ; i < adj[v].size() ; i++){
            if(adj[v][i] ==p){
                continue;
            }
            
            if(visited[adj[v][i]]){
                return true;
            }
            
            if(dfs(V , adj , v , adj[v][i] ,visited)){
                return true;
            }
        }
        return false;
        
    }
	bool isCycle(int V, vector<int>adj[])
	{
	    // Code here
	    //union fin 
	    bool*vis=new bool[V];
	    for(int i = 0 ;i <V;i++){
	        vis[i] = false;
	    }
	    bool ans=false;
	    for(int i = 0 ; i  < V;i++){
	        if(!vis[i]){
	            bool a = dfs(V , adj ,i,i,vis);
	            if(a){
	                ans=true;
	                break;
	            }
	        }
	    }
	    
	    delete[] vis;
	    return ans;
	}