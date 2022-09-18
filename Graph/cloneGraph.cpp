#include<bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/clone-graph/submissions/
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


 Node* cl(Node* n, vector<Node*>&add, vector<bool>&vis){
        if(n==NULL){
            return n;
        }
        Node* nn=NULL;
        if(add[n->val] == NULL){
            nn = new Node(n->val);
            add[nn->val]=nn;
        }else{
            nn = add[n->val] ;
        }
        vis[nn->val] = true;
        for(int i = 0 ;i<n->neighbors.size();i++){
            Node* neighbour = n->neighbors[i]; 
            if(add[neighbour->val] == NULL){
                Node* nbn = new Node(neighbour->val);
                nn->neighbors.push_back(nbn);
                add[neighbour->val] = nbn;
            }else{
                nn->neighbors.push_back(add[neighbour->val]);
            }
            if(!vis[neighbour->val]){
                vis[neighbour->val] = true;
                add[neighbour->val]= cl(neighbour,add,vis); 
            }
        }
        return nn;
    }
    
    Node* cloneGraph(Node* node) {
        if(node == NULL){
            return node;
        }
        vector<Node*> ad(101,NULL);
        vector<bool>v(101,false);
        ad[node->val] = cl(node,ad,v);
        return ad[node->val];
    }