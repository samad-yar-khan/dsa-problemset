#include "TreeNode.h"

void printPostOrder(TreeNode<int>* root) {

    if(root == NULL){
        return ;
    }

    for(int i = 0;i<root->children.size() ; i++){
        printPostOrder(root->children[i]);
    }

    cout<<root->data<<" ";

}