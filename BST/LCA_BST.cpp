#include "bt1.cpp"
int getLCA(BinaryTreeNode<int>* root , int val1 , int val2){
   	//if no lcca is found
    if(root == NULL){
        return -1;
    }
    
    //if i am eitehr of those two  values , i ll be the lca
    if(root ->data == val1 || root->data == val2){
        return root->data;
    }
    	
    //if those values are less than root
    if(val1<root->data && val2<root->data){
        return getLCA(root->left , val1 , val2);
    }else if(val2 > root->data  && val1 > root->data){ //if values are more than root
        return getLCA(root->right , val1 , val2);
    }else { //if one value is in th left and one belongs to the riht , then i im on a diversion and i ma the lca
        return root->data;
    }
}

