#include<bt1.cpp>
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