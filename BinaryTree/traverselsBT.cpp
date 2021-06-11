#include "bt1.cpp"

void preOrder(BinaryTreeNode<int> *root){

    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";

    preOrder(root->left);
    preOrder(root->right);


}


void postOrder(BinaryTreeNode<int> *root){

    if(root==NULL){
        return;
    }

    //print children first 
    postOrder(root->left);
    postOrder(root->right);

    //print parent
    cout<<root->data<<" ";

}


void inOrder(BinaryTreeNode<int> *root){

    if(root==NULL){
        return;
    }

    inOrder(root->left);
    cout<<root->data<<" ";
    inOrder(root->right);    
}