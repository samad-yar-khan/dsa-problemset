
#include "bt1.cpp"

void mirrorBinaryTree(BinaryTreeNode<int>* root){
    if(root== NULL){
        return;
    }

    //mirror sub trees
    mirrorBinaryTree(root->left);
    mirrorBinaryTree(root->right);

    BinaryTreeNode<int>* t = root->left;
    root->left = root->right;
    root->right = t;

    return;

}