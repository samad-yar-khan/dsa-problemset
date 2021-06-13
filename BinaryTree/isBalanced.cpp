#include "bt1.cpp"

/*
Check Balanced
Send Feedback
Given a binary tree, check if it is balanced. Return true if given binary tree is balanced, false otherwise.
Balanced Binary Tree:
A empty binary tree or binary tree with zero nodes is always balanced. For a non empty binary tree to be balanced, following conditions must be met:
1. The left and right subtrees must be balanced.
2. |hL - hR| <= 1, where hL is the height or depth of left subtree and hR is the height or depth of right subtree.    
Input format:
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have a left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
Output format
The first and only line of output contains true or false.
Constraints
Time Limit: 1 second
Sample Input 1 :
5 6 10 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1 :
false
Sample Input 2 :
1 2 3 -1 -1 -1 -1
Sample Output 2 :
true
*/

int height(BinaryTreeNode<int> * root){

    //bc
    if(root == NULL){
        return 0;
    }

    return max(height(root->left) , height(root->right))  + 1;

}
//O(n*h)
//besr case for balanced tree = O(nlogn)
//for non balanced tree = O(n2);
bool isBalanced(BinaryTreeNode<int>* root){

    //empty tree is balnced
    if(root == NULL){
        return true;
    }

    //h1
    int hLeft = height(root->left);
    int hRight = height(root->right);
    bool balancedLeft = isBalanced(root->left);
    bool balancedRight = isBalanced(root->right);

    //is
    return (hLeft == hRight)&&balancedLeft&&balancedRight;


}

//optimised approach
//complexity O(n)
pair<int,bool> checkBalanced(BinaryTreeNode<int>* root){

    //bc
    if(root == NULL){
        //the intiger her erefers to the tree ht ,
        //the boolin the pair refers to to balnced
        pair<int ,bool> baseAns(0 , true);
        return baseAns;
    }

    //ih
    //we asume we get the righta ans here
    //call rec on left and rigght subtrees
    pair<int,bool> leftAns = checkBalanced(root->left);
    pair<int,bool> rightAns = checkBalanced(root->right);

    //is
    //we return max ht +1 and ans will be true if htss are equal and both  trees themselves are balnced
    pair<int,bool> ourAns(max(leftAns.first,rightAns.first) + 1 , (leftAns.first == rightAns.first) && leftAns.second && rightAns.second);



}