#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/trim-a-binary-search-tree/



  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
TreeNode *trimBST(TreeNode *root, int lo, int hi)
{
    if (root == NULL)
    {
        return NULL;
    }

    if (root->val <= hi && root->val >= lo)
    {
        TreeNode *leftT = trimBST(root->left, lo, hi);
        TreeNode *rightT = trimBST(root->right, lo, hi);
        root->left = leftT;
        root->right = rightT;
        return root;
    }

    if (root->val < lo)
    {
        return trimBST(root->right, lo, hi);
    }

    return trimBST(root->left, lo, hi);
}