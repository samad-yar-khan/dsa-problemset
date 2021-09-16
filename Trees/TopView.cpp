#include<bits/stdc++.h>
using namespace std;


//so the logic is that we need to print the node at eahcx , but wemust print them in bfs fashion 
// multiple nodesd have same x cordinate from the root but we consider the elemnet which is above or has a lower lepth
//thats why we create  treeNode class  as WRAPPER


class Node{

    public :

        int data;
        Node* left;
        Node* right;

};

 class TreeNode{
        
        public:
            
            Node*node;
            
            int y;
            int x;
            
        TreeNode(Node*node , int x , int y){
            this->node = node;
            
            this->x = x ;
            this->y = y ;
        }
        
    };
    
    vector<int> topView(Node *root)
    {
        //Your code here
        queue<TreeNode*> pn;
        TreeNode*t = new TreeNode(root,0,0);
        pn.push(t);
        map< int , TreeNode* > map_;
        
        while(pn.size()>0){
            TreeNode*t = pn.front();
            
            pn.pop();
            if(t->node==NULL){
                continue ;
            }
            int x = t->x;
            int y = t->y;
            
            if(map_.count(x) <= 0){
                map_[x] = t;
            }else{
                
                int existingY = map_[x]->y;
                if(y<existingY){
                    map_[x] = t;
                }
            }
            
            TreeNode*left = new TreeNode(t->node->left , x-1 ,y+1);
            TreeNode*right = new TreeNode(t->node->right , x+1 ,y+1);
            
            pn.push(left);
            pn.push(right);
    
        }
        vector<int> ans;
        for(map<int,TreeNode*>::iterator itr = map_.begin() ; itr!= map_.end() ; itr++){
            ans.push_back(itr->second->node->data);
        }
        return ans;
        
        
    }