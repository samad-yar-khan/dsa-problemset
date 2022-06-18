#include<bits/stdc++.h>
using namespace std;

//https://www.codingninjas.com/codestudio/problems/minimum-time-in-wormhole-network_630527?leftPanelTab=0
 class Wormhole
    {
    public:
        int startX, startY, endX, endY, cost;
    };

int minTimeInWormholeNetwork(int n, int sx, int sy, int dx, int dy, Wormhole* w)
{
    // Write your Code here    
    int vertices = 2 + 2*n;
    vector<vector<int>>g(vertices,vector<int>(vertices,0));
    vector<int>x(2+2*n);
    vector<int>y(2+2*n);
    vector<bool>vis(2+2*n);
    int curr =0;
    x[curr] = sx;//s=0;
    y[curr++]=sy;
    vector<int>dd(n);
    for(int i =0;i<n;i++){
        x[curr]=w[i].startX;
        y[curr++]=w[i].startY;
        dd[i]=w[i].cost;
        x[curr]=w[i].endX;
        y[curr++]=w[i].endY;
    }
    x[curr] = dx;//d=1
    y[curr++] = dy;
    for(int i =0;i<vertices;i++){
        for(int j =i+1;j<vertices;j++){
            int d=abs(x[i]-x[j]) + abs(y[i]-y[j]);
            g[i][j] = d;
            g[j][i] = d;
        }      
    }
    int i=1;int k=0;
    while(i<vertices && i+1 < vertices && k<n){
        g[i][i+1] =dd[k];
        g[i+1][i] =dd[k];
        i+=2;;
        k++;
    }
    
    vector<int>D(vertices,INT_MAX);
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pn;
    D[0] = 0;
    pn.push({0,0});
    while(pn.size()){
        
        pair<int,int>t=pn.top();pn.pop();
        int node = t.second;
        int wt = t.first;
        if(vis[node]){
            continue;
        }
        vis[node]=true;
        for(int i =0;i<vertices;i++){
            if(i!=node){
                int newWt = D[node] + g[node][i];
                if(newWt < D[i]){
                    D[i] = newWt;
                    pn.push({D[i],i});
                }
            }
        }   
    }
    return D[vertices-1];
}