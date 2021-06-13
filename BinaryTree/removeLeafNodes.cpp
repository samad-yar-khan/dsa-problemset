#include "bt1.cpp"

BinaryTreeNode<int>* removeLeafNodes(BinaryTreeNode<int> *root) {

    //edgecase
    if(root == NULL){
        return root;
    }

    //is
    // check if ours is leaf

    if(root->left == NULL && root->right == NULL){
        delete root;
        return NULL;;
    }

    //ih
    // else we remove leafes from left and right sub trees

    //ih
    root->left = removeLeafNodes(root->left);
    root->right = removeLeafNodes(root->right);
    return root;



}