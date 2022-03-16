#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/submissions/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//return 5 values from each node

  class TreeNode {
      public:
     int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class mc{

    public:

        int m;
        int M;
        int cs;
        int maxSum;
        bool isBST;

        mc(){
            m = INT_MAX;
            M = INT_MIN;
            cs = 0;
            maxSum = INT_MIN;
            isBST=true;
        }

};

mc sol(TreeNode* root){

    if(root ==  NULL){
        mc mc1;
        return mc1;
    }

    mc l = sol(root->left);
    mc r = sol(root->right);

    int maxSum = max(l.maxSum , r.maxSum);
    bool isBST = l.isBST && r.isBST && (l.M < root->val ) &&  r.m > root->val;
    int minEl = min(min(l.m , r.m),root->val);
    int maxEl = max(max(l.M , r.M),root->val);
    int cs = l.cs + r.cs + root->val;
    if(isBST && cs > maxSum){
        maxSum = cs;
    }
    mc ans;
    ans.m = minEl;
    ans.M = maxEl;
    ans.cs = cs;
    ans.isBST = isBST;
    ans.maxSum = maxSum;
    // cout<<root->val<<" ";
    return ans;



}
    int maxSumBST(TreeNode* root) {
        int ans = sol(root).maxSum;
        return ans<0?0:ans;
    }