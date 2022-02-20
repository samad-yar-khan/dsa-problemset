#include<bits/stdc++.h>
using namespace std;


//https://practice.geeksforgeeks.org/problems/longest-consecutive-sequence-in-binary-tree/1/#
struct Node
{
	int data;
	Node *left, *right;
};

 int solve(Node* root , int cl){
            
        if(root == NULL)
        {
            return cl;
        }
        
        int a1 = INT_MIN ,a2 =INT_MIN;
        bool nc = true;
        if(root->left){
            nc = false;
            if(root->left->data - root->data == 1){
                a1= solve(root->left,cl+1);
            }else{
                a1= solve(root->left,0);
            }
            
        }
         if(root->right){
            nc = false;                
            if(root->right->data - root->data == 1){
                a2= solve(root->right,cl+1);
            }else{
                a2= solve(root->right,0);
            }
            
        }
        
        return nc?cl+1:max(max(a1,a2),cl+1);
        
    }
    
    int longestConsecutive(Node* root)
    {
         //Code here
         int ans=solve(root,0);
         return ans==1 ? -1 : ans;
    }