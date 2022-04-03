#include <bits/stdc++.h>
using namespace std;

// a bipartite graph is one which nodes can be broken down into two groups, the members of the same group will have the connections with the members iof the second group but will have no connections with members of the same group

// so we use graph coloring , where we consider one set of nodes as red and other as blue, now all red nodes can only have blue neighboirs and all blue nodes  con only have  red neighbours

// we perform BFS , color the uncolored nodes accordingly and see if a node has neighbour of the same color , then it cant be a bipartite graph, else , it will be a bipartite graph

// https://leetcode.com/submissions/detail/672805523/

bool bfscoloring(vector<vector<int>> &g, vector<bool> &vis, vector<int> &color, int root)
{

    queue<int> pn;
    pn.push(root);
    while (!pn.empty())
    {
        int tn = pn.front();
        pn.pop();
        vis[tn] = true;
        for (int i = 0; i < g[tn].size(); i++)
        {
            if (color[g[tn][i]] == 0)
            {
                if (color[tn] == 1)
                {
                    color[g[tn][i]] = 2;
                }
                else
                {
                    color[g[tn][i]] = 1;
                }
            }
            else
            {
                if (color[g[tn][i]] == color[tn])
                {
                    return false;
                }
            }

            if (!vis[g[tn][i]])
            {
                pn.push(g[tn][i]);
                vis[g[tn][i]] = true;
            }
        }
    }
    return true;
}

bool isBipartite(vector<vector<int>> &graph)
{
    vector<bool> vis(graph.size() + 1, 0);
    vector<int> color(graph.size() + 1, 0);

    for (int i = 0; i < graph.size(); i++)
    {
        if (!vis[i])
        {
            color[i] = 1;
            bool isBi = bfscoloring(graph, vis, color, i);
            if (!isBi)
            {
                return false;
            }
        }
    }
    return true;
}