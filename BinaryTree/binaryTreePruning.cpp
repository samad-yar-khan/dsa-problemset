 #include<bits/stdc++.h> 
 using namespace std;

//https://leetcode.com/problems/binary-tree-pruning/submissions/

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  }; 
   
   
    pair<TreeNode*,bool> solve(TreeNode*root){
        if(root == NULL){
            return {root,false};
        }
        pair<TreeNode*,bool>l = solve(root->left);
        pair<TreeNode*,bool>r = solve(root->right);
        
        bool gotOne = root->val == 1 || l.second || r.second;
        if(!l.second){
            root->left = NULL;
        }
        if(!r.second){
            root->right = NULL;
        }
        return {root,gotOne};
    }
    TreeNode* pruneTree(TreeNode* root) {
        pair<TreeNode*,bool> ans = solve(root);
        if(!ans.second){
            return NULL;
        }
        return ans.first;
    }