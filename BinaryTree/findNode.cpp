#include "bt1.cpp"

bool isNodePresent(BinaryTreeNode<int>* root , int x){
    
    if(root == NULL){
        return false;
    }

    if(root->data == x){
        return true;
    }

    return isNodePresent(root->left , x) || isNodePresent(root->right , x);


}

int main(){

}