#include<bits/stdc++.h>
using namespace std;

	void dfs(int V, vector<int> adj[],vector<bool>&vis,stack<int>&st,int v){
	    
	    if(vis[v]){
	        return;
	    }
	    vis[v] = true;
	    for(int i =0;i<adj[v].size();i++){
	            
	           int n = adj[v][i];
	           if(!vis[n]){
	               dfs(V,adj,vis,st,n);
	           }
	        
	    }
	    
	    st.push(v);
	    
	    
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    // code here
	
	    stack<int>st;
	    vector<bool>vis(V,false);
	    for(int i =0;i<V;i++){
	        if(!vis[i]){
	            dfs(V,adj,vis,st,i);
	        }
	    }
	    
	   vector<int>ans;
	    while(!st.empty()){
	        ans.push_back(st.top());
	        st.pop();
	    }
	    return ans;
	    
	    
	}