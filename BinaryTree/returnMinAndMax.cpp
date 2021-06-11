#include <climits>
#include "bt1.cpp"

pair<int,int>getMinAndMax(BinaryTreeNode<int>* root){

    if(root == NULL){
        pair<int , int> ans(INT_MAX , INT_MIN);
        return ans;
    }

    //ih
    pair<int , int> ans1 =  getMinAndMax(root->left);
    pair<int , int> ans2 =  getMinAndMax(root->right);

    int myMin = min(root->data , min(ans1.first , ans2.first));
    int myMax = max(root->data , max(ans2.second , ans1.second));

    pair <int , int>myAns(myMin , myMax);
    return myAns;


}