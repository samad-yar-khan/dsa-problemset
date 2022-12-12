#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/binary-tree-maximum-path-sum/ 

class TreeNode{

    public:

    TreeNode* left;
    TreeNode* right;
    int val;

    TreeNode(int x){
        val = x;
        left = NULL;
        right = NULL;
    }

    TreeNode(){
        val = 0;
        left=NULL;
        right=NULL;
    }

    TreeNode(int val, TreeNode*left, TreeNode*right){
        this->left = left;
        this->right = right;
        this->val = val;
    }

};

    pair<int,int> maxPathSol(TreeNode* root){
        if(root== NULL){
            return make_pair(-5000,INT_MIN + 1);
        }
        
        pair<int,int> la = maxPathSol(root->left);
        pair<int,int> ra = maxPathSol(root->right);
        
        int maxContPath = max(root->val,max(la.first + root->val, ra.first + root->val));
        int maxPath = max(max(la.first, ra.first),max(maxContPath, max(la.first + root->val + ra.first,max(la.second, ra.second))));
        return make_pair(maxContPath,maxPath);
        
    }
    
    
    int maxPathSum(TreeNode* root) {
        if(root == NULL) return 0;
        
        return maxPathSol(root).second;
    }