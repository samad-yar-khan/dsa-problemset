#include<bits/stdc++.h>
using namespace std;

template <typename T>

class BinaryTreeNode {

    public :
        T data ;
        BinaryTreeNode<T>* left;
        BinaryTreeNode<T>* right;

    BinaryTreeNode(){
        data = 0 ;
        left = NULL;
        right = NULL;
    }

    BinaryTreeNode(T data){
        this->data = data ;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode(){
        delete left ;
        delete right ;
    }

};

void printLevelwise(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }

    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty()){

        BinaryTreeNode<int>* myNode = pendingNodes.front();
        pendingNodes.pop();

       cout<<myNode->data<<" : ";
        if(myNode->left!=NULL){
            cout<<"L "<<myNode->left->data<<" ";
            pendingNodes.push(myNode->left);
        }else{
            cout<<"L __ ";
        }

        if(myNode->right!=NULL){
            cout<<"R "<<myNode->right->data<<" ";
            pendingNodes.push(myNode->right);
        }else{
            cout<<"R __";
        }
         cout<<"\n";
    }
}

BinaryTreeNode<int> * takeInputLevelwise(){

    int rootData = 0;
    cin>>rootData;
    if(rootData == -1){
        return NULL;
    }

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue< BinaryTreeNode<int>* > pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty())
    {

        BinaryTreeNode<int>* myNode = pendingNodes.front();
        pendingNodes.pop();

        int left = 0 , right=  0 ;

        cout<<"Enter left child of "<<myNode->data<<" : ";
        cin>>left;
        cout<<"\n";
         cout<<"Enter right child of "<<myNode->data<<" : ";
        cin>>right;

        BinaryTreeNode<int>* leftNode = NULL ;
        BinaryTreeNode<int>*  rightNode= NULL;


        if(left != -1){
            leftNode = new BinaryTreeNode<int>(left);
            myNode->left = leftNode;
            pendingNodes.push(leftNode);
        }

        if(right != -1){
            rightNode = new BinaryTreeNode<int>(right);
            myNode->right = rightNode;
            pendingNodes.push(rightNode);
        }
       

    }

    return root;
}

vector<int> solve(BinaryTreeNode<int>* root){
    vector<int> ans;
    vector<int>nums;
    if(root == NULL){
        ans;
    }

    queue<BinaryTreeNode<int>*> pendingNodes;
   
    pendingNodes.push(root);
    pendingNodes.push(NULL);
    int sum = 0;  
    int l = 0;
    int S_0= 0 ;
    int S_1= 1 ;
    int d = 0;
    while(!pendingNodes.empty()){

        BinaryTreeNode<int>* myNode = pendingNodes.front();
        pendingNodes.pop();

        if(myNode == NULL){
            l++;
         
            // nums.push_back(sum);
            if(l==1){
                S_0 = sum; 
                ans.push_back(0);
            }else if(l==2){
                S_1 = sum; 
                ans.push_back(0);
            }else{
                d = S_1 -S_0;
                ans.push_back()
            }
            sum = 0;
            if(pendingNodes.size()!=0){
                pendingNodes.push(NULL);
            }else{
                break;
            }
        }else
        {     
            sum+=myNode->data;
            if(myNode->left!=NULL){
                pendingNodes.push(myNode->left);
            }

            if(myNode->right!=NULL){  
                pendingNodes.push(myNode->right);
            }
        }

    }

  

    ans.push_back(0);
    if(nums.size()<=1 ){
        return ans;
    }
    int d = nums[1] - nums[0];

    ans.push_back(0);
    for(int i = 2 ; i < nums.size() ;i++){
        int d_ = (nums[i]-nums[i-1]);
        nums[i] +=d-d_;
        ans.push_back(d-d_);
    }

    return ans;
}   


int  main(){


    BinaryTreeNode<int>* root = takeInputLevelwise();

    vector<int> a=solve(root);
    for(auto i:a ){
        cout<<i<<" ";
    }


}
/*
1  11

 5
  2

-1
-1

 10
 -1

 50
 -1

-1
 -1

 -1
 */