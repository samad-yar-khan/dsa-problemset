/*
Code: Construct BST from a Sorted Array
Send Feedback
Given a sorted integer array A of size n, which contains all unique elements. You need to construct a balanced BST from this input array. Return the root of constructed BST.
Note: If array size is even, take first mid as root.
Input format:
The first line of input contains an integer, which denotes the value of n. The following line contains n space separated integers, that denote the values of array.
Output Format:
The first and only line of output contains values of BST nodes, printed in pre order traversal.
Constraints:
Time Limit: 1 second
Sample Input 1:
7
1 2 3 4 5 6 7
Sample Output 1:
4 2 1 3 6 5 7 

*/

#include "bt1.cpp"

BinaryTreeNode<int>* constructTree_h(int* i , int si , int ei){
    
	if(si>ei){
        return NULL;
    }
    
    int mid = (si+ei)/2;
    
    BinaryTreeNode<int>*l = constructTree_h(i , si , mid-1);
     BinaryTreeNode<int>*r = constructTree_h(i , mid+1 , ei);
    
    BinaryTreeNode<int>* myNode = new BinaryTreeNode<int> (i[mid]);
    myNode->left = l;
    myNode->right = r;
    
    return myNode;
    
    
    
}

BinaryTreeNode<int>* constructTree(int *input, int n) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
	//base
    return constructTree_h(input ,0 , n-1);


    
}