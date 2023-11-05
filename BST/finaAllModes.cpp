#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-mode-in-binary-search-tree/
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

    /*
    Inorder to achieve a O(1) Space Complexity and O(1) Time complexity Solution, we shall find the modes in two passes.
    In the first pass we will find the max freuquency of recurring elements in the Tree. This is achieval using inorder traversal and maintaining global variables for curr val and freuecies because inorder traversal traverses the tree like a sorted list.
    In the second pass we use the same logic to keep track of curr elemenst frequency and add our element to the modes array if the elements frequency is equal to max frequecy.
    */
    
    int curr_val =0;
    int curr_val_frequency= 0;
    int max_frequency = 0;
    
    void handle_frequency_for_curr_value(int val){

        if(curr_val == val){
            curr_val_frequency +=1;
        }else{
            curr_val = val;
            curr_val_frequency =1;
        }
    }
    
    void inorder_find_mode_frequency(TreeNode* root) {
        if(!root){
            return;
        }
        inorder_find_mode_frequency(root->left);
        
        handle_frequency_for_curr_value(root->val);
        
        max_frequency = max(curr_val_frequency, max_frequency);
        
        inorder_find_mode_frequency(root->right);
    }
    
    void inorder_populate_modes(TreeNode* root, vector<int>&modes) {
         if(!root){
             return;
         }
        inorder_populate_modes(root->left, modes);
        
        handle_frequency_for_curr_value(root->val);
        
        if(curr_val_frequency == max_frequency){
            modes.push_back(root->val);
        }
        
        inorder_populate_modes(root->right, modes);
    }
    
    void initialise_values(){
        curr_val = 0;
        curr_val_frequency = 0;
    }
   
    vector<int> findMode(TreeNode* root) {
        
        initialise_values();
        inorder_find_mode_frequency(root);
        
        vector<int> modes;
        
        initialise_values();
        inorder_populate_modes(root, modes);
        
        return modes;
    }