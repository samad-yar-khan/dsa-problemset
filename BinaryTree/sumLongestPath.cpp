#include<iostream>
using namespace std;

//https://practice.geeksforgeeks.org/problems/sum-of-the-longest-bloodline-of-a-tree/1
//tree node
/*
Sum of the Longest Bloodline of a Tree (Sum of nodes on the longest path from root to leaf node) 
Easy Accuracy: 49.91% Submissions: 15637 Points: 2
Given a binary tree of size N. Your task is to complete the function sumOfLongRootToLeafPath(), that find the sum of all nodes on the longest path from root to leaf node.
If two or more paths compete for the longest path, then the path having maximum sum of nodes is being considered.

Example 1:

Input: 
        4        
       / \       
      2   5      
     / \ / \     
    7  1 2  3    
      /
     6
Output: 13
Explanation:
        4        
       / \       
      2   5      
     / \ / \     
    7  1 2  3 
      /
     6

The highlighted nodes (4, 2, 1, 6) above are 
part of the longest root to leaf path having
sum = (4 + 2 + 1 + 6) = 13
Example 2:

Input: 
          1
        /   \
       2     3
      / \   / \
     4   5 6   7
Output: 11
Your Task:
You don't need to read input or print anything. Your task is to complete the function sumOfLongRootToLeafPath() which takes root node of the tree as input parameter and returns an integer denoting the sum of the longest root to leaf path of the tree. If the tree is empty, return 0.

Expected Time Complexity: O(N)
Expected Auxiliary Space: O(N)

Constraints:
1 <= Number of nodes <= 104
1 <= Data of a node <= 104
*/

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;

    Node(int x)
    {
        data = x;
        left = NULL;
        right = NULL;
    }
};

    pair<int , int> helper(Node* root){
        
        //base case
        if(root == NULL){
            pair<int , int> ans(0,0);
            return ans;
        }
        
        //ih
        pair<int , int> leftAns = helper(root->left);
        pair<int , int> rightAns = helper(root->right);
        
        if(leftAns.first > rightAns.first){
            
            leftAns.first=leftAns.first+1;
            leftAns.second+=root->data;
            return leftAns;
            
        }else if(leftAns.first < rightAns.first){
            rightAns.first=rightAns.first+1;
            rightAns.second+=root->data;
            return rightAns;
        }
            int maxSum = max(leftAns.second , rightAns.second) + root->data;
            int ht = leftAns.first+1;
              pair<int , int> ans(ht,maxSum);
              return ans;
        
        
    }
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        //code here
        return helper(root).second;
    }