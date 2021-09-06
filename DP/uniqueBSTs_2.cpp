#include<bits/stdc++.h>
using namespace std;
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
  
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
//  https://leetcode.com/problems/unique-binary-search-trees-ii/

  vector<TreeNode*> solve(int myNode , int endNode , vector<vector<vector<TreeNode*>>>dp){
        //edge case
        if(myNode > endNode){
            TreeNode*ans = NULL;
            vector<TreeNode*>allTrees ;
            allTrees.push_back(ans);
            return allTrees;
        }
        //base case
        if(myNode == endNode){
            TreeNode*ans = new TreeNode(myNode , NULL , NULL);
            vector<TreeNode*>allTrees ;
            allTrees.push_back(ans);
            return allTrees;
        }
        
        if(dp[myNode][endNode][0]!=NULL){
            return dp[myNode][endNode];
        }
        vector<TreeNode*>allTrees ;
        for(int i = myNode ; i<= endNode ; i++){
            vector<TreeNode*>left = solve(myNode , i-1 ,dp);
            vector<TreeNode*>right = solve(i+1 , endNode ,dp);
            for(int j = 0 ; j <left.size() ;j++){
                for(int k = 0 ; k < right.size() ;k++){
                    TreeNode* AuxTree = new TreeNode(i,left.at(j),right.at(k));
                    allTrees.push_back(AuxTree);
                }
            }
        }
        dp[myNode][endNode] = allTrees;
        return allTrees;
    }
    
    vector<TreeNode*> generateTrees(int n) {
        
        vector<vector<vector<TreeNode*>>>dp(n+1, vector<vector<TreeNode*>>(n+1, vector<TreeNode*>(1,NULL)) );
        
        return solve(1,n,dp);
    }