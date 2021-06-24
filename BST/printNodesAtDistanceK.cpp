#include "bt1.cpp"
#include <climits>


/*
logic 1 
we store all nodes from the node to roott aswell as kkeep a trakc of which subtree the node came from 
using this we cal the print on alternate subtree at depth k-i-1 , and i is the diatnce of the node froom original node
*/
void print(BinaryTreeNode<int> *root , int k){
    if(root== NULL || k < 0){
        return;
    }
    
    if(k== 0){
        cout<<root->data<<"\n";
    	return;
    }
    
    print(root->left,k-1);
    print(root->right , k-1);
    
}

vector<pair<BinaryTreeNode<int> *,char>> helper(BinaryTreeNode<int> *root , int n){
    vector<pair<BinaryTreeNode<int> * , char>> ans;
    if(root == NULL ){
        
        return ans;
    }
    
    if(n == root->data){
        pair<BinaryTreeNode<int> *,char> myNode(root,'\0');
        ans.push_back(myNode);
        return ans;
    }

    //ih
     vector<pair<BinaryTreeNode<int> * , char>> ansLeft = helper(root->left , n);
     vector<pair<BinaryTreeNode<int> * , char>> ansRight = helper(root->right , n);

    //is
     if(ansLeft.size() > 0){
         pair<BinaryTreeNode<int> *,char> myNode(root,'L');
         ansLeft.push_back(myNode);
         return  ansLeft;
     }else if(ansRight.size() > 0){
         pair<BinaryTreeNode<int> *,char> myNode(root,'R');
         ansRight.push_back(myNode);
         return ansRight;
     }else{
         return ans;
     }

}

void nodesAtDistanceK(BinaryTreeNode<int> *root, int node, int k){
	
   vector<pair<BinaryTreeNode<int> * , char>> ans = helper(root , node);
   for(int i = 0 ; i < ans.size() ; i++){
        if(k ==  i ){
            cout<<ans[i].first->data<<"\n";
            break;
        }else if(k == 0){
            cout<<ans[i].first->data<<"\n";
            break;
        }else{
            if(ans[i].second == 'R'){
                   print(ans[i].first->left , k-1-i);
               }else if(ans[i].second == 'L'){

                   print(ans[i].first->right , k-1-i);
               }else{
                   print(ans[i].first->left , k-1-i);
                   print(ans[i].first->right , k-1-i);
               }
        }   
   }    
}


/*
method 2 with
logic 
base case : if root is nulll we couldnt find the req node and we return -1
is1 : if our root is teh req node , then we print all children at distance k-1 from root 
    this is handled by our print func
    now we return k-1 , signifying that we have found node and k-1 is the distnace of the node nee dt be printed 
ih : if we didnt find the node , then we , just call the helper on left and right subtree
    1)if we found the node is eother of the subttree and distance of the node to be printed is 0 we print our node 
    2)if we found node in left subtree and we are at a distance k from the node , then we call print on the right subree and ask em to print all nodes at depth k-1 and we return k-1 aswell
    3)similair case with right subtree


*/
int helper_find(BinaryTreeNode<int> *root, int node, int k){
//base case
    if(root == NULL){
        return -1;
    }
//is
    if(root->data  == node){
        print(root->left , k-1);
        print(root->right , k-1);
        return k-1 ; //1 less than distance
    }

    int leftD = helper_find(root->left , node , k);
    int rightD = helper_find(root->right , node,k);

    if(leftD == 0 || rightD==0 ){
        cout<<root->data<<"\n";
        return -1;
    }else if(leftD > 0){
        print(root->right , leftD -1);
        return leftD -1;
    }else if(rightD > 0){
        print(root->left , rightD -1);
        return rightD -1;
    }else{
        return -1;
    }

}

void nodesAtDistanceK_method2(BinaryTreeNode<int> *root, int node, int k){
	
   helper_find(root , node , k);
}