#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/submissions/

 
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

 static bool c(const pair<TreeNode*,pair<int,int>>&a,const pair<TreeNode*,pair<int,int>>&b){
        if(b.second.second != a.second.second){
            return a.second.second < b.second.second;
        }
        if(b.second.first != a.second.first){
           return a.second.first < b.second.first;  
        } 
        return a.first->val < b.first->val;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<pair<TreeNode*,pair<int,int>>>nodes;
        queue<pair<TreeNode*,pair<int,int>>>pn;
        pn.push(make_pair(root,make_pair(0,0)));
        while(!pn.empty()){
            pair<TreeNode*,pair<int,int>>t = pn.front();
            pn.pop();
            nodes.push_back(t);
            if(t.first->left){
                pn.push(make_pair(t.first->left,make_pair(t.second.first + 1, t.second.second -1)));
            }
            if(t.first->right){
                pn.push(make_pair(t.first->right,make_pair(t.second.first + 1, t.second.second +1)));
            }
        }
        sort(nodes.begin(),nodes.end(),c);
        vector<vector<int>>ans;
        int i =0;
        while(i<nodes.size()){
            int j = i;
            vector<int>curr;
            while(j<nodes.size() && nodes[j].second.second == nodes[i].second.second){
                curr.push_back(nodes[j].first->val);
                j++;
            }
            i=j;
            ans.push_back(curr);
        }
        return ans;
    }