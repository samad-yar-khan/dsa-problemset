#include "TreeNode.h"
#include <queue>

bool isPresent(TreeNode<int>* root, int x){

    if(root == NULL){
        return false;
    }

    queue<TreeNode<int> *> pendingNodes;

    pendingNodes.push(root);

    while(!pendingNodes.empty()){

        TreeNode<int>* myNode = pendingNodes.front();
        pendingNodes.pop();

        if(myNode->data == x){
            return true;
        }

        for(int i = 0 ; i < myNode->children.size() ; i++){
            pendingNodes.push(myNode->children[i]);
        }


    }

    return false;

}
