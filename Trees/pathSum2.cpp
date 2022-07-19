#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/path-sum-ii/

//in my old approahc i was copying everything, but we are only calling dfs on eotehr lefta nd roghta nd we can 
//only go down a single path, so , ve can use only one vector, and pop out elemnts while returning
//this optimises space aswlll as time

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

    vector<vector<int>>ans;
    vector<int>vec;
    void sol(TreeNode* root, int targetSum){
        if(root==NULL){
            return;
        }
        if(root->left == NULL && root->right == NULL){
            if(root->val == targetSum){
                vec.push_back(root->val);
                ans.push_back(vec);
                vec.pop_back();
            }
            return;
        }
        
        vec.push_back(root->val);
        sol(root->left,targetSum - root->val);
        sol(root->right,targetSum - root->val);
        vec.pop_back();
        
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {

        sol(root,targetSum);
        return ans;
    }