

#include<iostream>
using namespace std;
#include<queue>
#include "./BinaryTree.h"
class BST {

    private :
        BinaryTreeNode<int> * root;
    public :

    //contrutor and ditrucore
    BST(){
        root = NULL;
    }
    ~BST(){
        delete root;
    }
    
    BinaryTreeNode<int>*insert_helper(int data, BinaryTreeNode<int>* root){

        //bc
        if(root == NULL){
            BinaryTreeNode<int>* myNode = new BinaryTreeNode<int>(data);
            return myNode;
        }

        if(root->data >= data){
            BinaryTreeNode<int>* newLeft = insert_helper(data , root->left);
            root->left = newLeft;
            return root;
        }else{
            BinaryTreeNode<int>* newRight = insert_helper(data , root->right);
            root->right = newRight;
            return root;
        }

    }

    BinaryTreeNode<int>*insert(int data){

        root =  insert_helper(data , root);

    }

    bool search_helper(int data , BinaryTreeNode<int>* root){
        
        if(root==NULL){
            return false ;
        }

        if(root->data == data){
            return true;
        }

        return (data <= root->data) ? search_helper(data , root->left) : search_helper(data , root->right);
    }

    bool search(int data){
        return search_helper(data , root);
    }

    void print_helper(BinaryTreeNode<int>* root){

        if(root == NULL){
            return;
        }

        cout<<root->data<<":";
        if(root->left!=NULL)
        {
            cout<<"L:"<<root->left->data<<",";
        }
        if(root->right!=NULL)
        {
            cout<<"R:"<<root->right->data;
        }

        cout<<"\n";

        print_helper(root->left);
        print_helper(root->right);


    }
    void print(){
        print_helper(root);
    }


    BinaryTreeNode<int>* delete_helpter(int data , BinaryTreeNode<int>* root){

        if(root==NULL){
            return NULL;
        }

        if(root->data == data){

            //case1
            if(root->left == NULL && root->right==NULL){
                delete root ;
                return NULL;
            }else if(root->left == NULL && root->right!=NULL){
                BinaryTreeNode<int>* rightSubTree = root->right;
                root->right =NULL;
                delete root;
                return rightSubTree;
            }else if(root->left != NULL && root->right == NULL){
                 BinaryTreeNode<int>* leftSubTree = root->left;
                root->left =NULL;
                delete root;
                return leftSubTree;
            }else{

                // find minimum noode of the left subtree
                BinaryTreeNode<int>*minNode = root->right;
                while(minNode->left!=NULL){
                    minNode=minNode->left;
                }
               root->data = minNode->data,
            root->right = delete_helpter(minNode->data , root->right);
    
            }

        }else if (root->data < data)
        {
            root->left = delete_helpter(data , root->left);
        }else{
            
            root->right = delete_helpter(data , root->right);
        }

        return root;

    }

    void  remove(int data){
        root = delete_helpter(data , root);
        return;
    }

};

// class BST {
// 	// Complete this cl    private : 

//     BinaryTreeNode<int>* root; //our bst willl internally work on a BT strcuture 


//     bool has_data (int k , BinaryTreeNode<int>* node){
//      if(node == NULL){
//         return false;
//      }   

//      if(node->data == k){
//         return true;
//      }else if(node->data > k){
//          return  has_data(k , node->left);
//      }else {
//          return has_data (k , node->right);
//      }
//     }

//     BinaryTreeNode<int>* insert_node (BinaryTreeNode<int>* node,int k){

//         if(node==NULL){
//             BinaryTreeNode<int> * newnode = new BinaryTreeNode<int> (k);
//             return newnode;
//         }

//         if(k<node->data){
//             BinaryTreeNode<int>* left = insert_node(node->left , k);
//             node ->left=left;
//             return node;
//         }else{
//             BinaryTreeNode<int>* right = insert_node(node->right,k);
//             node->right = right ;
//             return node;
//         }
        
//     }


//     BinaryTreeNode<int>* deleteData (BinaryTreeNode<int>* node , int k){

//         if(node==NULL){
//             return node;
//         }

//         if(node->data == k){
//             if(node->left ==NULL && node->right ==NULL){
//                 delete node;
//                 return NULL;
//             }

//            if(node->left == NULL && node->right !=NULL){
//                BinaryTreeNode<int>* newhead = node->right;
//                node->right = NULL;
//                delete node;
//                return newhead;
//            } 

//            if(node->left != NULL && node->right ==NULL){
//                BinaryTreeNode<int>* newhead = node->left;
//                node->left = NULL;
//                delete node;
//                return newhead;
//            } 
		
//             BinaryTreeNode<int>* temp = node->right;
            
//             while(temp->left!=NULL){
//                 temp=temp->left;
//             }
            
//             node->data = temp->data;
//             node->right = deleteData(node->right,temp->data);
            
//             return node;
            
//          }else if(node->data >k){
//              node->left = deleteData(node->left,k);
//              return node;
//          }else {
//              node->right = deleteData(node->right,k);
//              return node;
//          }
//     }

//     void printTree(BinaryTreeNode<int> * node){
//         if(node==NULL){
//         return;
//     }
    
//     // queue <BinaryTreeNode<int> *> pending_nodes;
//     // pending_nodes.push(node);
    
//     // while(pending_nodes.size()!=0){
//         BinaryTreeNode<int> * front = node;
      
        
//         cout<<front->data<<":";
        
//         if(front->left!=NULL){
//             cout<<"L:"<<front->left->data<<",";
//             // pending_nodes.push(front->left);
//         }
        
//         if(front->right!=NULL){
//             cout<<"R:"<<front->right->data;
//             // pending_nodes.push(front->right);
//         }
//         cout<<endl;
    
//         printTree(node->left);
//         printTree(node->right);
        
//     }

//     public:


//     //constructor
//     BST() {
//         root=NULL;
//     }

//     //destructor
//     ~BST (){
//         delete root; //BT already deleetd roor recursively we jsut use delete
//     }

//     //
//     bool hasData (int k){
//         return has_data (k,root);
//     }

//     void insert (int k){
//         BinaryTreeNode<int>* newroot= insert_node(root,k);
//         root = newroot;
//         return;
//     }

//     void deleteData (int k){
//         root = deleteData(root,k);
//         return;
//     }

//     void printTree(){
//         printTree(root);
//     }

    
// };
