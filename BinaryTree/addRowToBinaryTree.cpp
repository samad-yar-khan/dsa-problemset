#include<bits/stdc++.h>
#include "Tree.h"
using namespace std;

// https://leetcode.com/problems/add-one-row-to-tree/

 TreeNode* solve(TreeNode* root, int val, int d, int cd){
        
        if(root==NULL){
            return NULL;
        }

        if(d-1 != cd){
            root->left = solve(root->left, val,d,cd+1);
            root->right = solve(root->right,val, d,cd+1);
        }else{
            
            TreeNode* l = new TreeNode(val,root->left,NULL);
            TreeNode* r = new TreeNode(val,NULL,root->right);
            root->left = l;
            root->right = r;
        }
        return root;
        
    }
    
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* t = new TreeNode(val,root,NULL);
            return t;
        }

        return solve(root, val, depth, 1);
    }