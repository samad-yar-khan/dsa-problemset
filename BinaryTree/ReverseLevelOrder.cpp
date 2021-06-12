
#include "bt1.cpp"
#include <vector>
#include<stack>
#include<queue>

vector<int> reverseLevelOrder(BinaryTreeNode<int> *root)
{
    // code here
    vector<int> vec;
    if(root == NULL){
        return vec;
    }
    
    queue<BinaryTreeNode<int>*> pendingNode;
    stack<BinaryTreeNode<int>*> nodes;
    pendingNode.push(root);
    while(!pendingNode.empty()){
        
        BinaryTreeNode<int> * myNode = pendingNode.front();
        pendingNode.pop();
        
        
        if(myNode->right != NULL){
            pendingNode.push(myNode->right);
        }
        if(myNode->left != NULL){
            pendingNode.push(myNode->left);
        }
        
        nodes.push(myNode);
        
    }
    
    while(!nodes.empty()){
        BinaryTreeNode<int>*nodeStack = nodes.top();
        vec.push_back(nodeStack->data);
        nodes.pop();
    }
    
    return vec;
    
    
}