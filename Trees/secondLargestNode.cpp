

#include "TreeNode.h"
#include<iostream>
#include<vector>
using namespace std;
//this func returs the top 2 nodes outta 4
pair<TreeNode<int> * , TreeNode<int>  *>  largestPair(pair<TreeNode<int> * , TreeNode<int>  *>p1 , pair<TreeNode<int> * , TreeNode<int>  *>p2){

    pair<TreeNode<int> * , TreeNode<int>  *>  lpAns(NULL , NULL);

    vector<TreeNode<int> *> v;
    v.push_back(p1.first);
    v.push_back(p2.first);
    v.push_back(p2.second);
    v.push_back(p1.second);

    int ans1= INT_MIN;

    for(int i = 0 ; i < v.size() ; i++){
        if(v.at(i)!=NULL && v.at(i)->data > ans1 ){
            lpAns.first=v.at(i);
            ans1=lpAns.first->data;
        }
    }

    ans1= INT_MIN;

      for(int i = 0 ; i < v.size() ; i++){
        if(v.at(i)!=NULL && v.at(i)->data > ans1 && v.at(i) != lpAns.first ){
            lpAns.second=v.at(i);
            ans1=lpAns.second->data;
        }
    }

    return lpAns;
}

//this func will retrn the max and secodn max node
pair<TreeNode<int> * , TreeNode<int>  *> getSecondLargestNodeHelp (TreeNode<int> * root){

    if(root ==  NULL){
        pair<TreeNode <int> *, TreeNode <int> *> ans(NULL , NULL);
        return ans;
    }

    pair<TreeNode <int> *, TreeNode <int> *> ans(NULL , NULL);
    ans.first = root;  
    for(int i = 0 ; i < root->children.size() ; i++){
        
         pair<TreeNode <int> *, TreeNode <int> *> ansTemp (NULL , NULL);
         ansTemp = getSecondLargestNodeHelp(root->children[i]);
        ans = largestPair(ans , ansTemp);
    }
    return ans;
}

TreeNode<int> *getSecondLargestNode(TreeNode<int> * root){
    if(root == NULL){
        return NULL;
    }
    
    if(root->children.size() == 0){
        return NULL;
    }

     pair<TreeNode <int> *, TreeNode <int> *> ansTemp = getSecondLargestNodeHelp(root);
    if(ansTemp.first->data == ansTemp.second->data){
        return NULL;
    }else{
        return ansTemp.second;
    }

}