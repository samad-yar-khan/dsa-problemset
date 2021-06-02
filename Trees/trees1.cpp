#include<iostream>
using namespace std;
#include "TreeNode.h"


TreeNode<int> * input()
{

    int data = 0;
    int numChildren = 0;

    cout<<"Enter data \n";
    cin>>data;
    cout<<"Number of childen of "<<data<<"\n";
    cin>>numChildren;

    TreeNode<int> *myNode = new TreeNode<int>(data);

    for(int i = 0 ; i <numChildren; i++){
        TreeNode<int>*child = input();
        myNode->children.push_back(child);
    }

    return myNode;

}

void printTree(TreeNode<int> * root){
    if(root == NULL){
        return;
    }

    cout<<root->data<<" : ";

    for(int i = 0 ; i < root->children.size() ; i++){
        cout<<root->children[i]->data<<" ";
    }

    cout<<"\n";

    for(int i = 0 ; i < root->children.size() ; i++){
        printTree(root->children[i]);
    }

}

int main(){

    TreeNode<int> * root = input();
    printTree(root);

    delete root;
}

/*
0 3 
1 3
3 0 
4 0 
5 0 
2 2 
6 0
7 0
3 1 
8 0

*/