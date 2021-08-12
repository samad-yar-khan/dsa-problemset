#include<bits/stdc++.h>
using namespace std;

    int dfs(int**edges , int n ,int sv ,bool*visited , int& minWt){
        
        
        visited[sv] = true;
        int v = sv;
        
        for(int  i = 1 ; i <= n;i++ ){
            
            if(!visited[i] && i!=sv){
                if(edges[sv][i] > 0){
                minWt = min(minWt , edges[sv][i]);
                    v = dfs(edges , n , i , visited , minWt);      
                }
              
            }
        }
        return v;
        
    }
    
    vector<vector<int>> solve(int n,int p,vector<int> a,vector<int> b,vector<int> d)
    {
        // code here
        int**edges = new  int*[n+1];
        for(int i = 1 ; i<=n ; i++){
            edges[i] = new int[n+1];
            for(int j = 1 ; j <= n ; j++){
                edges[i][j] = 0;
            }
        }
        
        int*parent = new int[n+1];
        for(int i = 1;i<=n ;i++){
            parent[i]= -1;
        }
        
        for(int i = 0;i<p ;i++){
            int s=a[i];
            int e=b[i];
            int dis=d[i];
            edges[s][e] =  dis;    
            parent[e] = s; 
        }
        
        bool*visited = new bool[n+1];
        for(int i = 0 ; i <=n ; i++){
            visited[i]  = false;
        }
        vector<vector<int>> ans;
        for(int i =  1 ; i<=n ;i++){
            if(!visited[i] && parent[i] == -1){
                int minWt = INT_MAX;
                int endNode=i;
                endNode=dfs(edges ,n,i,visited , minWt);
                vector<int> vec;
                if(endNode == i){
                    continue;
                }
                vec.push_back(i);
                vec.push_back(endNode);
                vec.push_back(minWt);
                ans.push_back(vec);
            }
        }
        
        
        
        for(int i = 1 ;  i <=n;i++){
            delete [] edges[i];
        }
        delete [] parent;
        delete []  edges;
        delete [] visited;
        return ans;
    }
