#include "bt1.cpp"
#include <climits>

/*
Largest BST
Send Feedback
Given a Binary tree, find the largest BST subtree. That is, you need to find the BST with maximum height in the given binary tree. You have to return the height of largest BST.
Input format :
The first line of input contains data of the nodes of the tree in level order form. The data of the nodes of the tree is separated by space. If any node does not have left or right child, take -1 in its place. Since -1 is used as an indication whether the left or right nodes exist, therefore, it will not be a part of the data of any node.
Output format:
The first and only line of output contains the height of the largest BST.
Constraints:
Time Limit: 1 second
Sample Input 1:
5 10 6 2 3 -1 -1 -1 -1 -1 9 -1 -1
Sample Output 1:
2
*/

#include<climits>

class ans {

    public:
    int ht;
    bool isBST;
    int Min ;
    int Max;

    ans(){
        Min= INT_MAX;
        Max = INT_MIN;  
        isBST = true;
        ht = 0;
    }
};

ans largestBST(BinaryTreeNode<int>* root){

    
//bc
    if(root == NULL){
        ans myAns ;
        return myAns;
    }

//ih
    ans left = largestBST(root->left);
    ans right = largestBST(root->right);

    bool isBST = true;
    int myMin=INT_MAX ;
    int myMax = INT_MIN;
    int ht = 1;
//is

    myMin = min(root->data , min(left.Min , right.Min));
    myMax = max(root->data , max(left.Max , right.Max));
    isBST = (root->data > left.Max && root->data < right.Min && left.isBST && right.isBST);
    if(isBST){
        ht = max(left.ht , right.ht) + 1;
    }else{
        ht = max(left.ht , right.ht );
    }

    ans myAns;
    myAns.ht = ht;
    myAns.Min = myMin;
    myAns.Max = myMax;
    myAns.isBST = isBST;
	
    return myAns;

}

int largestBSTSubtree(BinaryTreeNode<int> *root) {

    return largestBST(root).ht;
    // Write your code here
}

BinaryTreeNode<int>* takeInput() {
    int rootData;
    
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
       
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        
        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << largestBSTSubtree(root);
    delete root;
}