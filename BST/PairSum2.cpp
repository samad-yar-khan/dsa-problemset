/*

Pair sum in a BST
Send Feedback
Given a binary search tree and an integer S, find pair of nodes in the BST which sum to S. You can use extra space of the order of O(log n).
Note:
1. Assume BST contains all unique elements.
2. In a pair, print the smaller element first.
Input Format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.   
The following line of input contains an integer, that denotes the value of S.
Output format:
You have to print each pair in a different line (pair elements separated by space). The order of different pairs, to be printed, does not matter.
Constraints:
Time Limit: 1 second   
Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
12
Sample Output 1:
2 10
5 7


the major part is that we do this in O(n) time and O(log(n)) space

https://practice.geeksforgeeks.org/problems/find-a-pair-with-given-target-in-bst/1#
*/


#include "bt1.cpp"
#include <stack>


int CountNodes(BinaryTreeNode<int> *root){

    if(root == NULL){
        return 0;
    }

    return CountNodes(root->left)  +  CountNodes(root->right) + 1;

}

void fillMin( BinaryTreeNode<int>* root , stack<BinaryTreeNode<int>*>&myStack , int&n){

        BinaryTreeNode<int> * node = root;
            while(node!=NULL){
              
            myStack.push(node);
            node=node->left;
           
        }

}

void fillMax( BinaryTreeNode<int>* root , stack<BinaryTreeNode<int>*>&myStack , int&n){

        BinaryTreeNode<int> * node = root;
            while(node!=NULL){
            myStack.push(node);
            node=node->right;
           
        }

}

void printNodesSumToS(BinaryTreeNode<int> *root, int s){


    stack< BinaryTreeNode<int>* > minNodes;
    stack <BinaryTreeNode <int> *> maxNodes;

    int nodes = CountNodes(root);
    int n = 0 ;
    
    BinaryTreeNode<int> * left = root;
    while(left!=NULL){
        minNodes.push(left);
        left=left->left;
       
    }
    BinaryTreeNode<int> * right = root; 
    while(right!=NULL)
    {
        maxNodes.push(right);
        right=right->right;
       
    }

    

//to stop the loop we keep track of how many node have been popped out ans used , this should not exceed n 

    while( n < nodes-1 && !minNodes.empty() && !maxNodes.empty())
    {

        BinaryTreeNode<int>* leftTop = minNodes.top();
     
        BinaryTreeNode<int>* rightTop = maxNodes.top();

        if(leftTop->data + rightTop->data == s){
            cout<<leftTop->data<<" "<<rightTop->data<<"\n";
            minNodes.pop();
            maxNodes.pop();
            n+=2;
            fillMin(leftTop->right, minNodes , n );
            fillMax(rightTop->left, maxNodes , n );
            
            
        }else if(leftTop->data + rightTop->data > s){
            maxNodes.pop();
            n++;
            fillMax(rightTop->left, maxNodes , n );
        }else{
            minNodes.pop();
            n++;
            fillMin(leftTop->right, minNodes , n );
        }
    
    }
    

}