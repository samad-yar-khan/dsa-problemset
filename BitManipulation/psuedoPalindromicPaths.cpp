#include<bits/stdc++.h>
using namespace std;

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };


//   https://leetcode.com/problems/pseudo-palindromic-paths-in-a-binary-tree/

/*
A path will have a palindromic permutation if the frequency of all the numbers along that path is even or we only have one element with odd freuquency.

example 1 : 1 1 2 1 3 2 3 1 , all numbers occer even number of times and hence can be places evenly on both sides to make a palindrome => 1 2 3 1 1 2 3 1

example 2 : 1 1 2 3 2 3 3 . here 3 has an odd frequency, rest of the numbers have even frequencies. One 3, can be put in the middle and the rest of the numbers can be distributed on both sides to make a palindrome => 1 2 3 3 3 2 1

In any case where more than one elemet has odd frequency, we cant form a palindrome . example -> 1 1 2 1 2 2 .

Solution
While going down a path, we can store the even or odd parity of frequency of each number => (1 to 9) in the form of bits inside an intigers.
We inititally set a number num to 0. If we come across a number x, we take the xor of num and (1<<x), this will let us know the parity of frequency of number x while going down a path.
When we reach a leaf node, we can only form a palindrome if num is zero (all numers have even frequency) of num has only 1 set bit (only one number with odd frequency).
*/
 int pseudoPalindromicPaths (TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        queue<pair<int,TreeNode*>> pn;
        pn.push({(1<<root->val),root});
        int ans =0;
        while(pn.size()){
            pair<int,TreeNode*>tn = pn.front();
            pn.pop();
            int num = tn.first;
            TreeNode* node = tn.second;
            if(node->left == NULL && node->right == NULL ){
                int bc = __builtin_popcount(num);
                if(bc == 0 || bc == 1){
                    ans++;
                }
            }
            if(node->left){
                pn.push({((1 << (node->left->val))^num),node->left});
            }
            if(node->right){
                pn.push({((1 << (node->right->val))^num),node->right});
            }
        }
        return ans;
    }
