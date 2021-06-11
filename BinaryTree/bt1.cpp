#include<iostream>
using namespace std;
#include <queue>
#include "BinaryTree.h"

void printBinaryTree(BinaryTreeNode<int>* root){

    if(root == NULL)
    {
        return;
    }

    cout<<root->data<<" : ";
    if(root->left!=NULL){
        cout<<"L "<<root->left->data<<" ";
    }else{
        cout<<"L __ ";
    }

     if(root->right!=NULL){
        cout<<"R "<<root->right->data<<" ";
    }else{
        cout<<"R __";
    }

    cout<<"\n";

    printBinaryTree(root->left);
    printBinaryTree(root->right);


}

BinaryTreeNode<int> * takeInputInorder(){

    int data = 0 ;
    cin>>data ;
    if(data == -1){
        return NULL;
    }

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(data);
     BinaryTreeNode<int>* left = takeInputInorder();
     BinaryTreeNode<int>* right  = takeInputInorder();

     root->left = left;
    root->right = right;

    return root;

}

void printLevelwise(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }

    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty()){

        BinaryTreeNode<int>* myNode = pendingNodes.front();
        pendingNodes.pop();

       cout<<myNode->data<<" : ";
        if(myNode->left!=NULL){
            cout<<"L "<<myNode->left->data<<" ";
            pendingNodes.push(myNode->left);
        }else{
            cout<<"L __ ";
        }

        if(myNode->right!=NULL){
            cout<<"R "<<myNode->right->data<<" ";
            pendingNodes.push(myNode->right);
        }else{
            cout<<"R __";
        }
         cout<<"\n";
    }
}

BinaryTreeNode<int> * takeInputLevelwise(){

    int rootData = 0;
    cin>>rootData;
    if(rootData == -1){
        return NULL;
    }

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue< BinaryTreeNode<int>* > pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty())
    {

        BinaryTreeNode<int>* myNode = pendingNodes.front();
        pendingNodes.pop();

        int left = 0 , right=  0 ;

        cout<<"Enter left child of "<<myNode->data<<" : ";
        cin>>left;
        cout<<"\n";
         cout<<"Enter right child of "<<myNode->data<<" : ";
        cin>>right;

        BinaryTreeNode<int>* leftNode = NULL ;
        BinaryTreeNode<int>*  rightNode= NULL;


        if(left != -1){
            leftNode = new BinaryTreeNode<int>(left);
            myNode->left = leftNode;
            pendingNodes.push(leftNode);
        }

        if(right != -1){
            rightNode = new BinaryTreeNode<int>(right);
            myNode->right = rightNode;
            pendingNodes.push(rightNode);
        }
       

    }

    return root;
}


int main(){

    BinaryTreeNode<int> * root = takeInputLevelwise();

    printLevelwise(root);


    delete root ;
}



/*
1
2
3
-1 
-1
4
-1
-1
5
6 
-1
-1 
7
-1 
-1
*/