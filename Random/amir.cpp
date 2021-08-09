#include<bits/stdc++.h>
using namespace std;

class Node {

public:
    char data;
    Node*left;
    Node*right;

    Node(char x){
        data = x;
        left = NULL ;
        right = NULL;
    }

    ~Node(){
        delete left;
        delete right;
    }

};


Node* arrToTree(char *arr , int i , int j ){
    if(i > j){
        return NULL;
    }

    int m = (i+j)/2;
    Node* root = new Node(arr[m]);
    root->left = arrToTree(arr , i , m-1);
    root->right = arrToTree(arr , m+1 , j);

    return root;
}

void pre(Node * r){

    if(r==NULL){
        return;
    }
    cout<<r->data;
    pre(r->left);
    pre(r->right);
}

void revArr(char * arr , int si , int ei)
{
    while(si < ei){
        swap(arr[si] , arr[ei]);
        si++;
        ei--;
    }
}

void updateArr(char*arr , int n){
    
    for(int i = 0 ; arr[i]!='\0' ; i++){
        revArr(arr , 0 , i-1);
        revArr(arr , 0 , n-1 );
        revArr(arr , n , i-1);
    }
}

int main (){
    char arr[] = "kjmrj*gvvnup";

    int n = 0;
    for(n ; arr[n]!='\0' ; n++);

    Node*r = arrToTree(arr ,0 , n-1);
    pre(r);
    cout<<"-";

    updateArr(arr , 4);
    r=arrToTree(arr ,0 , n-2 );
    pre(r);
    cout<<"-";

      updateArr(arr , 2);
    r=arrToTree(arr ,0 , n-1 );
    pre(r);
    cout<<"-";

      updateArr(arr , 1);
    r=arrToTree(arr ,0 , n-3);
    pre(r);
   
}