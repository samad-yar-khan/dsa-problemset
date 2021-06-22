/*
Preorder to Postorder 
Medium Accuracy: 65.92% Submissions: 7564 Points: 4
Given an array arr[] of N nodes representing preorder traversal of BST. The task is to print its postorder traversal.

Example 1:

Input:
N = 5
arr[]  = {40,30,35,80,100}
Output: 35 30 100 80 40
Explanation: PreOrder: 40 30 35 80 100
InOrder: 30 35 40 80 100
Therefore, the BST will be:
              40
           /      \
         30       80
           \        \   
           35      100
Hence, the postOrder traversal will
be: 35 30 100 80 40
Example 2:

Input:
N = 8
arr[]  = {40,30,32,35,80,90,100,120}
Output: 35 32 30 120 100 90 80 40
Your Task:
You need to complete the given function and return the root of the tree. The driver code will then use this root to print the post order traversal.

Expected Time Complexity: O(N).
Expected Auxiliary Space: O(N).

Constraints:
1 <= N <= 103
1 <= arr[i] <= 104
*/

#include "bt1.cpp"
BinaryTreeNode<int>* constructTree(int pre[], int size)
{
    //code here
    if(size <= 0){
        return NULL;
    }
    
    if(size== 1){
        BinaryTreeNode<int>*newNode = new BinaryTreeNode<int>;
        newNode->data = pre[0];
        return newNode;
    }
    
    int i = 1 ;
    while(i < size && pre[i] <= pre[0]){
        i++;
    }
    
    int rightSize = size - i;
    int leftSize = size- rightSize -1;
    
    
    BinaryTreeNode<int>* leftTree = constructTree(pre+1, leftSize);
    BinaryTreeNode<int>* rightTree =  constructTree(pre+i , rightSize);
    
    //is
      BinaryTreeNode<int>*newNode = new BinaryTreeNode<int>;
        newNode->data = pre[0];
      newNode->left = leftTree;
      newNode->right = rightTree;
      return newNode;
}
