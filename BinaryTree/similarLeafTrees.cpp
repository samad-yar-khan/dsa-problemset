#include <bits/stdc++.h>
using namespace std;
#include "Tree.h"

// https://leetcode.com/problems/leaf-similar-trees/

    void fillLeafSeq(TreeNode* r, vector<int>&v){
        if(!r){
            return;
        }
        if(r->left == NULL && r->right == NULL){
            v.push_back(r->val);
        }
        fillLeafSeq(r->left,v);
        fillLeafSeq(r->right,v);
    }
    
    bool leafSimilar2(TreeNode* root1, TreeNode* root2) {
        vector<int>l,r;
        fillLeafSeq(root1, l);
        fillLeafSeq(root2, r);
        return l == r;
    }
    
    
    int getFirstLeaf(stack<TreeNode*>&s){
        while(s.size()){
            TreeNode*t = s.top();s.pop();
            TreeNode*l = t->left;
            TreeNode*r = t->right;
            
            if(l == NULL && r == NULL){
                return t->val;
            }
            if(r!=NULL){
                s.push(r);
            }
            if(l!=NULL){
                s.push(l);
            }
        }
        return -1;
    }
    
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        stack<TreeNode*>s1, s2;
        s1.push(root1);
        s2.push(root2);
        while(s1.size() && s2.size()){
            if(getFirstLeaf(s1)!=getFirstLeaf(s2)){
                return false;
            }
        }
        return s1.empty() && s2.empty();
    }