//https://practice.geeksforgeeks.org/problems/flattening-a-linked-list/1

/* Node structure  used in the program */
#include<iostream>
using namespace std;

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};


/*  Function which returns the  root of 
    the flattened linked list. */

//the logic here is that we take two colums at a time and merge them in colm
//so we do merge two sorted linked list , but at each itearton whole merged ll will be in col1 and followed by head
//and col2 will be the next parellel linked list to be merged into col1 

    
Node *flatten(Node *root)
{
   // Your code here
   Node*head =  root;
   Node*tail= root;
   Node*c2=root->next;
   Node*c1=root;
   Node*col1 = root ;
   Node* col2 = root->next;
   while(col2!=NULL){
       
       if(col1->data < col2->data){
           head=col1;
          tail = col1;
           col1=col1->bottom;
       }else{
           head = col2;
           tail=col2;
           col2 = col2->bottom;
       }
       
        
        while(col1!=NULL&&col2!=NULL){
            
            if(col1->data < col2->data){
                
                tail->bottom = col1;
                col1=col1->bottom;
                tail = tail->bottom;
                
            }else{
                tail->bottom = col2;
                col2=col2->bottom;
                tail = tail->bottom;
            }
        }
        
        if(col1!=NULL){
            tail->bottom = col1;
        }
        if(col2!=NULL){
            tail->bottom = col2;
        }
        
       tail = head;
       col2=c2->next;
       c2=c2->next;
       col1 = head;
   }
   
   Node*temp = head;
   temp->next = NULL;
   //all linked list items are now made in bottom fashion
//   1
//   |
//   3
//   |
//   5
//   |
//   9
//   |
//   NULL
//   while(temp!=NULL){
//       Node*prev = temp;
//       if(temp->bottom!=NULL){
//          temp->next = temp->bottom;     
//       }
      
//       prev->bottom = NULL ;
//       temp = temp->next;
//   }
   return head;
}


