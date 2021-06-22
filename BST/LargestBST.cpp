#include "bt1.cpp"
#include <climits>


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