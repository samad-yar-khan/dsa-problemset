#include<bits/stdc++.h>
#define ll long long
using namespace std;


class Tree{

    public:

        int val;
        Tree* left;
        Tree* right ;

    Tree(){
        val = 0;
        left = NULL;
        right= NULL;
    }

    ~Tree(){
        delete  this->left;
        delete this->right;
    }

};

void helper(Tree* root, vector<string>&ans, string path){

    if(root == NULL){
        return;
    }

    int num = root->val;
    bool n = false;
    if(num <0){
        num*=-1;
        n = true;
    }
    
    string myAdd = to_string(num);
    if(n)
    {
        string neg{"-"};
        myAdd = neg+ myAdd;
    } 
    if(root->left == NULL && root->right==NULL){
        path+=myAdd;
        ans.push_back(path);
        return;
    }
    string arrow{"->"};
    myAdd+=arrow;
    path+=myAdd;
    if(root->left!=NULL){
        helper(root->left , ans ,path );
    }
    if(root->right!=NULL){
        helper(root->right , ans ,path );
    }

}



vector<string> treePaths(Tree* root){
    vector<string> vec;
    if(root == NULL){
     
        return vec;
    }
    string s{""};
    helper(root , vec , s);
    return vec;
}



Tree * input(){

    int rootData = 0;
    cin>>rootData;
    if(rootData == -1){
        return NULL;
    }

    Tree* root = new Tree;
    root->val = rootData;
    queue< Tree* > pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty())
    {

        Tree* myNode = pendingNodes.front();
        pendingNodes.pop();

        int left = 0 , right=  0 ;

        
        cin>>left;
        
         
        cin>>right;

       Tree* leftNode = NULL ;
       Tree*  rightNode= NULL;


        if(left != -1){
            leftNode = new Tree;
            leftNode->val = left;
            myNode->left = leftNode;
            pendingNodes.push(leftNode);
        }

        if(right != -1){
            rightNode = new Tree;
            rightNode->val = right;
            myNode->right = rightNode;
            pendingNodes.push(rightNode);
        }
       

    }

    return root;
}

int main(){
  
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r" , stdin);
        freopen("../output.txt", "w", stdout);
    #endif

  

    // for(int i =0 ;i < primes.size() ; i++){
    //     cout<<primes[i]<<"\n";
    // }
    int T = 0;cin>>T;

    while(T--){

        Tree* node = input();
        vector<string> ans = treePaths(node);
        for(auto s:ans){
            cout<<s<<" , ";
        }
        cout<<'\n';
        delete node;
      
    }
  

}