
#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
#include "BinaryTree.h"

/*
Pair Sum Binary Tree
Send Feedback
Given a binary tree and an integer S, print all the pair of nodes whose sum equals S.
Note:
1. Assume the given binary tree contains all unique elements.
2. In a pair, print the smaller element first. Order of different pairs doesn't matter.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have a left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
The following line of input contains an integer, that denotes the value of S.
Output Format :
Print each pair in a new line, as described in the task. 
Constraints:
Time Limit: 1 second
Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
15
Sample Output 1:
5 10
6 9
*/

void pairSum(BinaryTreeNode<int>* root , int sum){

    if(root ==NULL){
        return ;
    }

    queue<BinaryTreeNode<int> *>pendingNodes;
    pendingNodes.push(root);

    vector<int> vecNodes;

    while(!pendingNodes.empty()){
        BinaryTreeNode<int>* myNode = pendingNodes.front();
        pendingNodes.pop();

        vecNodes.push_back(myNode->data);

        if(myNode->left!=NULL){
            pendingNodes.push(myNode->left);
        }

        if(myNode->right!=NULL){
            pendingNodes.push(myNode->right);
        }
    }

    sort(vecNodes.begin() , vecNodes.end());

    int i = 0 , j = vecNodes.size() -1 ;
    while(i < j){

        if(vecNodes.at(i) + vecNodes.at(j) == sum){

            cout<<vecNodes.at(i)<<" "<<vecNodes.at(j)<<'\n';
            i++;j--;

        }else if(vecNodes.at(i) + vecNodes.at(j) > sum){
            j--;
        }else{
            i++;
        }
    }
}