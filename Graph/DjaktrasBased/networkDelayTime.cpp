// https://leetcode.com/problems/network-delay-time/submissions/
#include<bits/stdc++.h>
using namespace std;

//we need to know the time reqd for the signal to reach the end of the line
//so wee first fo bfs and see if its even possible to raech all the sinaals or not
//after that we know that signal will be sent alo g a path which ahs min time delay
//so using djakstras we will calculate thr mi  possible time req to go along to a specific nide
//after that wqe sent the max of these values because that the time when teh signal reaches the final station


int minTime (int**edges , int V , int k){
        //now our signal will take the shortest diatce and hence we need to calulate tht shorted time req for asignal to travel for k to all n vertices
        V++;
       int*distances = new int[V];
      bool*visited = new bool[V];
    for(int i = 1; i < V ; i++){
        distances[i] = INT_MAX;
        visited[i] = false;
    }
    
    
    distances[k] = 0 ;//sv has distance 0;
    for(int i = 1 ; i < V ; i++){

        int minDistance = INT_MAX;
        int closestNode = -1;
        for(int j = 1; j< V ;j++){
            if(!visited[j] && minDistance > distances[j]){
                closestNode=j;
                minDistance=distances[j];
            }
        }

        //go to all unvisted neioghbours of our ndoe and se eif gfoing to the neigbour via us would be much m more beneficial or not
        visited[closestNode] = true;
        for(int j = 1 ; j < V ; j++){
           
            if(visited[j]){
                continue;
            }
            
            if(edges[closestNode][j]!=-1){
                 int D = distances[closestNode] + edges[closestNode][j];
                if(D<=distances[j]){
                    distances[j] = D;
                }
            }
           

        }

    }
        int ans = INT_MIN;
        
        for(int i = 1 ; i < V ; i++){
            ans = max(ans , distances[i]);
        }
        return ans;
        
    }
    
    bool isPossible(int**edges , int n , int k ){
        
        queue<int> pendingNodes ;
        bool*vis = new bool [n+1];
        for(int i = 1 ; i <= n ; i++){
            vis[i] = false;
        }
        
        pendingNodes.push(k);
        
        while(!pendingNodes.empty()){
            
            int topNode = pendingNodes.front();
            pendingNodes.pop();
            
            vis[topNode] = true;
            for(int i = 1 ; i <= n  ;i++){
                if(!vis[i] && edges[topNode][i] !=-1){
                    pendingNodes.push(i);
                }
            }
            
        }

        
        for(int i = 1 ; i<= n ; i++){
            if(!vis[i]){
                return false;
            }
        }
        delete [] vis;
        return true;
        
    }
    
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        int**edges =  new int*[n+1];
        for(int i = 0 ; i <= n ; i++){
            edges[i] = new int[n+1];
            for(int j= 0 ;j<=n ; j++){
                edges[i][j] = -1 ;
            }
        }
        
        for(int i = 0 ;i < times.size() ;i++)
        {
            int u = times[i][0];
            int v = times[i][1];
            int t = times[i][2];
            
            edges[u][v] = t;
        }
        
        
        bool possible = isPossible(edges ,n ,k );
        if(!possible){
            return -1;
        }
        
        int ans =minTime(edges,n,k);
        
        for(int i = 0 ; i <= n ; i++){
           delete [] edges[i] ;
        }
        delete [] edges;
        return ans;
    }