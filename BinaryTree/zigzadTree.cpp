#include "bt1.cpp"
#include<stack>
void zigZagOrder(BinaryTreeNode<int>* root){

    stack<BinaryTreeNode<int>*> oddStack;
    stack<BinaryTreeNode<int>*> evenStack;

    if(root==NULL){
        return;
    }

    int iterationCount = 1;

    ///logicc . in or orger we know the element wer put reverse, so the  giev the right ans 
    //in evene we print reversed , so we need to input reversed
    oddStack.push(root);
    while(!oddStack.empty()||!evenStack.empty()){

        if(iterationCount%2!=0){

            while (!oddStack.empty())
            {   
                BinaryTreeNode<int>* topNode = oddStack.top();
                oddStack.pop();
                cout<<topNode->data<<" ";
        
                if(topNode->left!=NULL){
                    evenStack.push(topNode->left);
                }

                
                if(topNode->right!=NULL){
                    evenStack.push(topNode->right);
                }
            }
            
            cout<<"\n";
           

        }else{
               while (!evenStack.empty()){   
                BinaryTreeNode<int>* topNode = evenStack.top();
                evenStack.pop();
                cout<<topNode->data<<" ";
                        
                if(topNode->right!=NULL){
                    oddStack.push(topNode->right);
                }
                
                if(topNode->left!=NULL){
                    oddStack.push(topNode->left);
                }
            }
            
            cout<<"\n";
        }
        
         iterationCount++;

    }

    return;


}