#include<bits/stdc++.h>
using namespace std;


//https://leetcode.com/problems/lexicographically-smallest-equivalent-string/
/*
    form a graph and performa  bfs in lexiographicordet to assign samallest node value to all node
*/
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        
        vector<vector<int>>g(26,vector<int>(26,0));
        int n = s1.length();
        for(int i =0;i<n;i++){
            int a = s1[i] - 'a';
            int b = s2[i] - 'a';
            g[a][b] = 1;
            g[b][a] = 1;
        }
        vector<int>f(26,0);
        for(int i =0;i<26;i++)f[i]=i;
        
    
        queue<int>pn;
        vector<bool>vis(26,0);
        for(int i =0;i<26;i++){
            if(!vis[i]){
                pn.push(i);
                vis[i] = true;
                while(pn.size()){
                    int t = pn.front();
                    pn.pop();
                    f[t] = i;
                    for(int j =0;j<26;j++){
                        if(g[t][j] && !vis[j]){
                            vis[j] = true;
                            pn.push(j);
                        }
                    }
                }
            }
        }
        for(int i =0;i<baseStr.length();i++){
            int c = baseStr[i] -'a';
            baseStr[i] = char(f[c]+'a');
        }
        return baseStr;
    }


/*
    The space can be further optimised by using union find algorithm , here we alsows put the lower elemnt as the parent of the largerelemnt an form a parent array

*/

 int findParent(int a,vector<int>&p){    
        while(p[a]!=a){
            a=p[a];
        }
        return a;
    }

    void add_union(int a, int b, vector<int>&p){
        int pa = findParent(a,p);
        int pb = findParent(b,p);
        
        p[max(pa,pb)] = min(pa,pb);
    }
    
    string smallestEquivalentString_optimized(string s1, string s2, string baseStr) {
        int n = s1.length();
        int m = baseStr.length();
        vector<int>parent(26,0);
        for(int i =0;i<26;i++)parent[i] = i;
        for(int i =0;i<n;i++){
            add_union(s1[i]-'a',s2[i]-'a',parent);
        }
        for(int i=0;i<m;i++){
            baseStr[i] = char(findParent(baseStr[i]-'a',parent) + 'a');
        }
        return baseStr;
    }