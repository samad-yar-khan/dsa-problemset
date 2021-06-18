/*
Code: BST to Sorted LL
Send Feedback
Given a BST, convert it into a sorted linked list. You have to return the head of LL.
Input format:
The first and only line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.   
Output Format:
The first and only line of output prints the elements of sorted linked list.
Constraints:
Time Limit: 1 second
Sample Input 1:
8 5 10 2 6 -1 -1 -1 -1 -1 7 -1 -1
Sample Output 1:
2 5 6 7 8 10
*/

#include "bt1.cpp"
template <typename G>
 class Node{
    public:
    G data;
    Node<G> *next;
    
    Node(G data){
        this -> data = data;
        this -> next = NULL;
    }
 };


pair<Node<int>*,Node<int>*> help(BinaryTreeNode<int>* root){

    if(root==NULL){
         pair<Node<int>* , Node<int>*> ans(NULL , NULL);

         return ans;

    }

    pair<Node<int>* , Node<int>*> leftLL =  help(root->left);
    pair<Node<int>* , Node<int>*> rightLL =  help(root->right);

    Node<int>* myNode = new Node<int>(root->data);

    Node<int>*myHead = NULL;
    Node<int>*myTail =  NULL;

    if(leftLL.second == NULL){
        myHead = myNode;
        myTail = myNode;
    }else{
        myHead = leftLL.first;
        leftLL.second->next = myNode;
        myTail = myNode;
    }

    if(rightLL.first != NULL){
        myTail->next = rightLL.first;
        myTail = rightLL.second;
    }

    pair<Node<int>*, Node<int>*> myAns (myHead , myTail);
    return myAns;



}

 Node<int>* constructBST(BinaryTreeNode<int>* root) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    return help(root).first;
    
}