#include<bits/stdc++.h>
using namespace std;

//https://practice.geeksforgeeks.org/problems/duplicate-subtree-in-binary-tree/1#

/*

Duplicate subtree in Binary Tree 
Medium Accuracy: 44.66% Submissions: 22225 Points: 4
Given a binary tree, find out whether it contains a duplicate sub-tree of size two or more, or not.


Example 1 :

Input : 
               1
             /   \ 
           2       3
         /   \       \    
        4     5       2     
                     /  \    
                    4    5
Output : 1
Explanation : 
    2     
  /   \    
 4     5
is the duplicate sub-tree.
Example 2 :

Input : 
               1
             /   \ 
           2       3
Output: 0
Explanation: There is no duplicate sub-tree 
in the given binary tree.

Your Task:  
You don't need to read input or print anything. Your task is to complete the function dupSub() which takes root of the tree as the only arguement and returns 1 if the binary tree contains a duplicate sub-tree of size two or more, else 0.
Note: Two same leaf nodes are not considered as subtree as size of a leaf node is one.


Constraints:
1 ≤ length of string ≤ 100

*/

struct Node
{
  char data;
  struct Node* left;
  struct Node* right;
};

    //will calculate till what value is tree similoar
    int numSameNodes(Node* root , Node * dup){
        if(root ==  NULL || dup == NULL){
            return 0 ; //no match
        }
        
        if(root->data != dup->data || root == dup){
            return 0;
        }
        
        int left = numSameNodes( root->left ,  dup->left);
        int right = numSameNodes( root->right ,  dup->right);
        
        return left+ right +1;
    }
    
    // will go through the whol tree and try to find a tree matching with our node
    int check(Node* myNode , Node* root){
        
        if(myNode == NULL || root == NULL){
            return 0;
        }
        
        if(myNode->data == root->data && root!=  myNode){
            int matchingNodes = numSameNodes(myNode , root );
            if(matchingNodes > 2){
                return 1;
            }
        }
        
        int leftA = check(myNode , root->left);
        int rightA = check(myNode , root->right);
        
        return max(leftA , rightA);
    
        
    }
    
    int dupSub(Node *root) {
         // code here
         if(root==NULL){
             return 0;
         }
         queue<Node*> pendingNodes ;
         pendingNodes.push(root);
         //we ned to chekc if a subtree starting from each ndoe exists or not 
        while(!pendingNodes.empty()){
            Node* top = pendingNodes.front();
            pendingNodes.pop();
            
            if(top->left!=NULL){
                pendingNodes.push(top->left);
            }
            if(top->right != NULL){
                pendingNodes.push(top->right);
            }
            
            int checked  = check(top , root);
            if(checked == 1){
                return 1;
            }
            
        }
        return 0;
        
         
    }