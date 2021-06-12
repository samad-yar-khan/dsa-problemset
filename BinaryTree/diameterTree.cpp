#include "bt1.cpp"

pair<int , int>diameterH(BinaryTreeNode<int>*root){

    //bc
    if(root == NULL){
        pair<int , int> bcAns(-1,-1);        
        return bcAns;
    }

    if(root->left == NULL && root->right == NULL){
        pair<int , int> bcAns(0,0);        
        return bcAns;
    }

    //ih
    pair<int , int> leftAns = diameterH(root->left);        
    pair<int , int> rightAns = diameterH(root->left);    

    int lh = leftAns.first + 1;
    int rh = rightAns.first + 1;

    int maxHeight = max(lh , rh);
    int ourDiameter = lh+rh;

    pair<int , int> ourAns(maxHeight , max(ourDiameter , max(leftAns.second , rightAns.second)));

    return ourAns;
    

}