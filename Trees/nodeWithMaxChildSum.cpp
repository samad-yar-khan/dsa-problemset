/*

Node with maximum child sum
Send Feedback
Given a generic tree, find and return the node for which sum of its data and data of all its child nodes is maximum. In the sum, data of the node and data of its immediate child nodes has to be taken.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space. 
Output format :
The first and only line of output contains the data of the node with maximum sum, as described in the task.
Constraints:
Time Limit: 1 sec
Sample Input 1 :
5 3 1 2 3 1 15 2 4 5 1 6 0 0 0 0
Sample Output 1 :
1

*/

#include<iostream>
#include "TreeNode.h"
using namespace std;
#include <queue>
#include <climits>

//bfs code / iterative
//lever order ans
TreeNode<int>* maxSumNode(TreeNode<int> * root){
    
    queue<TreeNode<int>*> pendingNode;

    int maxSum = INT_MIN;
    TreeNode<int>* maxNode = NULL;
    pendingNode.push(root);
    //push the node in queue 
    //and at each iteration , we check the top node + its chilren , 
    //compare with the max val
    //and then replace node if our sum us greater

    while(!pendingNode.empty()){

        TreeNode<int> *ourNode =   pendingNode.front();
        pendingNode.pop();

        int mySum = 0;
        mySum+=ourNode->data;

        for(int i = 0 ; i < ourNode->children.size() ; i++){
            mySum+=ourNode->children[i]->data;
            pendingNode.push(ourNode->children[i]);
        }

        if(mySum>maxSum){
            maxSum = mySum;
            maxNode = ourNode;
        }

    }
    
    return maxNode;
}


//recursive inorder ans
TreeNode<int>* maxSumNodeInorder(TreeNode<int> * root){
   
    return maxSumNodeHelper(root).first;
   
}



pair<TreeNode<int>*, int >maxSumNodeHelper(TreeNode<int>*root){

    //edge case
    if(root==NULL){
        pair<TreeNode<int>* , int > myAns(NULL , INT_MIN);
        return myAns;
    }

    int myAns = 0 ;
    TreeNode<int>* myNode = root ;
    myAns += root->data;

    for(int i = 0 ; i < root->children.size() ; i++){
        myAns +=root->children[i]->data;
    }

    pair<TreeNode<int>*, int > ans (root , myAns);

    for(int i = 0 ; i < root->children.size() ; i++){

        pair<TreeNode<int>* , int> smallAns = maxSumNodeHelper(root->children[i]);//will get ans for subtree
        
        if(smallAns.second > ans.second){
            ans = smallAns;
        }

    }

    return ans ;


}
