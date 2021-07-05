#include<iostream>
//https://practice.geeksforgeeks.org/problems/diagonal-traversal-of-binary-tree/1
using namespace std;
#include "BinaryTree.h"
#include<queue>
#include<vector>

/* logic is thatt our first diagonal is the right diagoanal , 
so it mean in a tree like

            8
         /     \
        3      10
      /   \      \
     1     6     14
         /   \   /
        4     7 13

        we push the parellel line
        8 10 14 in a queue , now in each subsequnt iteration
        we just fill the queue with the left parell line from our node 
        8 will push 3 6 7 in the queue 
        10 ddoesnt have a left
        14 left line only has 13 
        so 3 6 7 13 should be in a parelleel line

*/

void fillDiagonal ( BinaryTreeNode<int>*  root ,  queue< BinaryTreeNode<int> * > &pendingNodes){
    if(root == NULL){
        return ;
    }

    while(root !=NULL){
        pendingNodes.push(root);
        root=root->right;
    }

}

vector<int> diagonal(BinaryTreeNode<int> *root)
{   

    queue< BinaryTreeNode<int> * > pendingNodes;
    vector< int > ans;


    if(root == NULL){
        return ans;
    }

    fillDiagonal(root , pendingNodes);

    while(!pendingNodes.empty()){

        BinaryTreeNode<int>  * myNode = pendingNodes.front();
        pendingNodes.pop();

        fillDiagonal(myNode->left , pendingNodes);

        ans.push_back(myNode->data);

    }
    



}
