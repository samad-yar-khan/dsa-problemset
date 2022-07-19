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
 //https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/
    /*
        we divide the problem into parts
        we only have to combine the paths till LCA
        if you are are adda node and you only find asource in left or eifht, you should add Up to thq ququq
        if you find destination , you push the node which it come from , L or Righr,  but we put thi is a stack as we sant to go to it and not come from it
        so the path reversal is requred. 
        then we combine the paths till LCA
    */
    queue<char>ss;
    stack<char>sd;
    pair<bool,bool>sol(TreeNode* root, int &s, int &d){
        if(root == NULL){
            return make_pair(false,false);
        }
        pair<bool,bool>left = sol(root->left,s,d);
        pair<bool,bool>right = sol(root->right,s,d);
        bool sourcef=false,desf = false;
        if(left.first){
            sourcef=true;
            if(!left.second){
                ss.push('U');
            }
        }
        if(right.first){
            sourcef=true;
            if(!right.second){
                ss.push('U');
            }
        }
         if(left.second){
            desf=true;
            if(!left.first){
                sd.push('L');       
            }
        }
        if(right.second){
            desf=true;
             if(!right.first){
                sd.push('R');
             }  
        }
        if(root->val == s){
            sourcef=true;
        }
        if(root->val == d){
            desf=true;
        }
        return make_pair(sourcef,desf);
    }
    string getDirections(TreeNode* r, int s, int d) {
        sol(r,s,d);
        string ans="";
        while(ss.size()){
            ans+=(ss.front());
            ss.pop();
        }
         while(sd.size()){
            ans+=(sd.top());
            sd.pop();
        }
        return ans;
    }