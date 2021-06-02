
#include<iostream>
#include <queue>
#include "TreeNode.h"
using namespace std;

//bfs input
//this is levelwise input
TreeNode<int> * input(){

    int data = 0 ;
    cout<<"Enter data \n";
    cin>>data;
    TreeNode<int>* root = new TreeNode<int>(data);

    queue<TreeNode<int> *> nodeQueue;
    nodeQueue.push(root);

    while (!nodeQueue.empty())
    {
        
        TreeNode<int> *ourNode = nodeQueue.front();
        nodeQueue.pop();
        cout<<"Enter number of children of "<<ourNode->data<<" ";
        int numChild = 0;
        cin>>numChild;
        cout<<"Enter children of "<<ourNode->data<<" ";
        for(int i = 0 ; i < numChild ; i++){
            int a;
            cin>>a;
             TreeNode<int> * newNode = new TreeNode<int>(a);
             ourNode->children.push_back(newNode);
             nodeQueue.push(newNode);
        }

    }

    return root;
    

}

//output iin dfs manner
//level order print wise of tree

void printTree(TreeNode<int> * root){
    if(root == NULL){
        return;
    }

    queue<TreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty()){

        TreeNode<int>* myNode = pendingNodes.front();
        pendingNodes.pop();
        cout<<myNode->data<<" : ";
        for(int i = 0 ; i < myNode->children.size() ; i++){
            cout<<myNode->children[i]->data<<" ";
            pendingNodes.push(myNode->children[i]);
        }
        cout<<"\n";

    }
}

int main(){

    TreeNode<int> * root = input();
    printTree(root);

    delete root;
}
