#include<bits/stdc++.h>
using namespace std;


//https://leetcode.com/problems/find-closest-node-to-given-two-nodes/
 void dfs(vector<int>&edges, int s, vector<int>&dis){
        queue<pair<int,int>> pn;
        pn.push({s,0});
        int c =s;
        int dd=0;
        while(dis[c]==-1){
            
            dis[c] = dd;
            dd++;
            int next = edges[c];
            if(next == -1){
                break;
            }
            c = next;

        }

    } 
    
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int>dis1(n, -1);
        vector<int>dis2(n, -1);
        dfs(edges,node1,dis1);
        dfs(edges,node2,dis2);
        int ans = INT_MAX;
        int ind = -1;
        for(int i =0;i<n;i++){
            if(dis1[i]!=-1 && dis2[i]!=-1 and max(dis1[i],dis2[i])<ans){
                ans = max(dis1[i],dis2[i]);
                ind =i;
            }
        }
        return ans == INT_MAX?-1:ind;
        
    }