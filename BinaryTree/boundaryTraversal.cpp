#include<bits/stdc++.h>
using namespace std;

//https://practice.geeksforgeeks.org/problems/boundary-traversal-of-binary-tree/1#g

class Node
{
public:
    int data;
    Node* left, * right;
}; 

    
    void dfs (Node* root , queue<int>&leafs){
        if(root==NULL){
            return;
        }
        
        if(root->left == NULL && root->right == NULL){
            leafs.push(root->data);
        }
        dfs(root->left,leafs);
        dfs(root->right,leafs);
    }

    vector <int> boundary(Node *root)
    {
        //Your code here
        //left nodes
        
        Node*curr = root->left;
        
        queue<int>left;
        
        while(curr!=NULL ){
            if(curr->left==NULL && curr->right == NULL){
                break;
            }
            left.push(curr->data);
            if(curr->left == NULL){
                curr = curr->right;
            }else{
                curr = curr->left;
            }
        }
        
        curr = root->right;
        stack<int> right;
        while(curr!=NULL && !(curr->left==NULL && curr->right==NULL)){
            
            right.push(curr->data);
            if(curr->right == NULL){
                curr = curr->left;
            }else{
                curr = curr->right;
            }
        }
        
        curr = root;
        queue<Node*> pn;
        pn.push(curr);
        queue<int>leafs;
        
        dfs(root,leafs);
        
        vector<int> ans;
        ans.push_back( root->data);
        while(left.size() >0){
            ans.push_back( left.front());left.pop();
        }
        while(leafs.size() >0){
            // cout<<leafs.front()<<" ";
           ans.push_back( leafs.front())
           ;
           leafs.pop();
        }
    while(right.size() >0){
            ans.push_back( right.top());right.pop();
        }
        return ans;
    }
