/*
Code: Construct Tree from Preorder and Inorder
Send Feedback
For a given preorder and inorder traversal of a Binary Tree of type integer stored in an array/list, create the binary tree using the given two arrays/lists. You just need to construct the tree and return the root.
Note:
Assume that the Binary Tree contains only unique elements. 
Input Format:
The first line of input contains an integer N denoting the size of the list/array. It can also be said that N is the total number of nodes the binary tree would have.

The second line of input contains N integers, all separated by a single space. It represents the preorder-traversal of the binary tree.

The third line of input contains N integers, all separated by a single space. It represents the inorder-traversal of the binary tree.
Output Format:
The given input tree will be printed in a level order fashion where each level will be printed on a new line. 
Elements on every level will be printed in a linear fashion. A single space will separate them.
Constraints:
1 <= N <= 10^4
Where N is the total number of nodes in the binary tree.

Time Limit: 1 sec
Sample Input 1:
7
1 2 4 5 3 6 7 
4 2 5 1 6 3 7 
Sample Output 1:
1 
2 3 
4 5 6 7 
Sample Input 2:
6
5 6 2 3 9 10 
2 6 3 9 5 10 
Sample Output 2:
5 
6 10 
2 3 
9 
*/

#include "bt1.cpp"

BinaryTreeNode<int>* buildTree(int *preorder, int preLenght, int *inorder, int inLength){

    //edge case
    if(preLenght==0 || inLength ==0){
        return NULL;
    }


    //base case
    if(preLenght == 1 || inLength == 1){
        //only one node
        BinaryTreeNode<int>* myNode = new BinaryTreeNode<int>(preorder[0]);

    }

    //is 
    // our first elemnt in pre shoudl be in the middle of inorder 
    //using this we can identify left and right sub trees
    int myRootData = preorder[0];
    int myRootIndex = 0;
    while(myRootData!=inorder[myRootIndex]){
        myRootIndex++;//we find the root node in order to create  diversin
    }

    int lengthLeft = myRootIndex;
    int lenRight = preLenght - lengthLeft -1;
    
    BinaryTreeNode<int>* rootNode = new BinaryTreeNode<int>(myRootData);

    //ih
    //nuild and attach left and right sub trees
    rootNode->left = buildTree(preorder + 1 , lengthLeft , inorder , lengthLeft);
    rootNode->right = buildTree(preorder + lengthLeft + 1 , lenRight , inorder+lengthLeft+1 , lenRight);

    return rootNode;




}