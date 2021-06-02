#include "trees2.cpp"
#include<iostream>
using namespace std;

int height(TreeNode<int>* root) {

    if(root == NULL){
        return 0;
    }   

    int maxH = 0 ;

    for(int i = 0 ; i < root->children.size() ; i++){
        
        maxH = max(height(root->children[i]) , maxH);
    }

    return maxH + 1;


}


int main(){

    TreeNode<int>* root =  input();
    int treeHeight =  height( root) ;
    cout<<"H : "<<treeHeight<<"\n";





}
