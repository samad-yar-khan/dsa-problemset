#include "bt1.cpp"

int height(BinaryTreeNode<int> * root){

    //bc
    if(root == NULL){
        return 0;
    }

    return max(height(root->left) , height(root->right))  + 1;

}