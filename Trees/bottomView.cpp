    #include<bits/stdc++.h>
    using namespace std;

    class Node{
        
        public :

            int data;
            Node*left;
            Node*right;

    };

//if nodes are at the same horijzontal distance fro,m roor , we print the borrom one and the one that come son the righrt
//hnece use bfs
    vector <int> bottomView(Node *root) {
        // Your Code Here
        
        int neg[100000]={-1};
        int pos[100000]={-1};
        
        queue<pair<int , Node*>> pn;
        pn.push(make_pair(0,root));
        int m=0;
        int M=0;
        
        while(!pn.empty()){
            
            pair<int , Node* > topE = pn.front();
            pn.pop();
            int bh=topE.first;
            Node* node = topE.second;
            if(node == NULL){
                continue;
            }
            if(bh>=0){
                pos[bh] = node->data;
            }else{
                neg[-bh] = node->data;
            }
            
            pn.push(make_pair(bh-1,node->left));
            pn.push(make_pair(bh+1,node->right));
            m=min(bh,m);
            M=max(bh,M);
            
        }
        
        
        vector<int> ans;
        pair<int , int>r(m,M);
        for(int i = -1*r.first ; i>0;i--){
            ans.push_back(neg[i]);
        }
        for(int i = 0;i<= r.second; i++){
            ans.push_back(pos[i]);
        }
        
        return ans;
    }