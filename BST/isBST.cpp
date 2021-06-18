#include "bt1.cpp"
#include<climits>


//method 1 
class triplet{

    public :

    int Min ;
    int Max  ;
    bool isBST ;

    triplet(){
        Min = INT_MAX;
        Max = INT_MIN;
        isBST = true;
    }

    triplet(int Min , int Max , bool isBST){
        this->Min = Min;
        this->Max = Max;
        this->isBST = isBST;
    }

};

triplet isBST_Helper(BinaryTreeNode<int>* root ){
    
    if(root == NULL){
        triplet ans;
        return ans;
    }

    triplet ans1 = isBST_Helper(root->left);
    triplet ans2 = isBST_Helper(root->right);

    triplet myAns;
    myAns.isBST = ans1.isBST&& ans2.isBST && ans1.Max < root->data &&  ans2.Min>root->data;
    myAns.Min =min(root->data , min(ans1.Min , ans2.Min));
    myAns.Max = max(root->data , max(ans1.Max , ans2.Max));

    return myAns;

}

//method 2 
// ..instead of creating a class , know that elembt to the left of roor should be smaller and to the right shouldhe bbe bigger 
//so we setup a range for eahh node

bool isBstHelper(BinaryTreeNode<int>*  root , int minVal , int maxVal){

    //bc
    if(root == NULL){
        return true;
    }

    //is
    if(root->data < minVal || root->data >maxVal){
        return false;
    }

    //ih 
    return isBstHelper(root->left , minVal, root->data) && isBstHelper(root->right , root->data , maxVal);

}
