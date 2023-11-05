#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/
    struct TreeNode {
        int val;
        TreeNode *left;
        TreeNode *right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    pair<int,pair<int,int>> sol(TreeNode* root){
        if(root == NULL){
            return {0,{0,0}};
        }
        
        pair<int,pair<int,int>>l = sol(root->left);
        pair<int,pair<int,int>>r = sol(root->right);
        pair<int,pair<int,int>>ans = {0,{0,0}};
        
        ans.second.first = l.second.first+r.second.first + root->val;
        ans.second.second = l.second.second+r.second.second + 1;
        
        int is_node_average = (root->val == ans.second.first/ans.second.second);
        
        ans.first = l.first + r.first + is_node_average;
        
        return ans;
        
    }
    
    int averageOfSubtree(TreeNode* root) {
        return sol(root).first;
    }


