#include<bits/stdc++.h>
using namespace std;

//https://binarysearch.com/problems/Longest-Arithmetic-Sequence-Tree-Path

  class Tree {
      public:
          int val;
          Tree *left;
          Tree *right;
  };
 
int s2(Tree* root, int d , int cl ){
    if(root == NULL){
        return cl;
    }   
    int ans1 = INT_MIN , ans2 = INT_MIN; 
    bool noChild = true;
    if(root->left != NULL){
        noChild=false;
        int D = root->left->val - root->val;
       
        if(d==D){
            ans1 = s2(root->left , d , cl+1);
        }else{
            ans1 = s2(root->left , D , 1);
        }
    }

     if(root->right != NULL){
           noChild=false;
        int D = root->right->val - root->val;
        
        if(d==D){
            ans2 = s2(root->right , d , cl+1);
        }else{
            ans2 = s2(root->right , D , 1);
        }
    }
    int Ans = noChild ? cl+1 : (max(max(ans1,ans2),cl+1));
    return Ans;

}

int solve(Tree* root) {
    return s2(root,INT_MAX, 0);
}