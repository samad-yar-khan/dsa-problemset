#include "bt1.cpp"

BinaryTreeNode<int>* buildTree(int *postorder, int postLenght, int *inorder, int inLength){

    //edge case
    if(postLenght == 0){
        return NULL;
    }

    //base case
    if(postLenght == 1){
        BinaryTreeNode <int>* myNode = new BinaryTreeNode<int>(postorder[0]);
        return myNode;
    }

    //is
    int myNodeData = postorder[postLenght-1];
    int index = 0 ;
    while(inorder[index] != myNodeData){
        index++;
    }

   int leftLength = index;
   int rightLength = inLength-leftLength-1;

   BinaryTreeNode<int>* root = new BinaryTreeNode<int>(myNodeData);
    root->left = buildTree(postorder ,leftLength , inorder , leftLength);
    root->right = buildTree(postorder + leftLength , rightLength , inorder + leftLength + 1 , rightLength );

    return root;

}