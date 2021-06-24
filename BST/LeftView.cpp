#include "bt1.cpp"
#include<vector>
#include <queue>


//https://practice.geeksforgeeks.org/problems/left-view-of-binary-tree/1

vector<int> leftView( BinaryTreeNode<int> *root){

    vector<int> ans;
    queue< BinaryTreeNode<int> *> pendingNodes ;
    pendingNodes.push(NULL);
    pendingNodes.push(root);
    
    //the   logic is that the Null marks the end of levele and we shpould intern another   null in the ququq to mark another leve
    ///right afte rthe null lies the first element of thhe level which will be vveiwed from the left

    while (!pendingNodes.empty())
    {   

        BinaryTreeNode<int> * top = pendingNodes.front();
        pendingNodes.pop();
        if(top == NULL){

            if(pendingNodes.empty() || pendingNodes.front() == NULL){
                break;
            }else{
                pendingNodes.push(NULL);
                top = pendingNodes.front();
                pendingNodes.pop();
                ans.push_back(top->data);

                if(top->left != NULL){
                    pendingNodes.push(top->left);
                }

                if(top->right != NULL){
                    pendingNodes.push(top->right);
                }
            }

        }else{
             if(top->left != NULL){
                    pendingNodes.push(top->left);
                }

                if(top->right != NULL){
                    pendingNodes.push(top->right);
                }
        }

    }

    return ans;
    


}