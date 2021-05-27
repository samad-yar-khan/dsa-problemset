#include<iostream>
using namespace std;
#include "linkedList.cpp"

void rearrangeEvenOdd(Node *head){

    Node*et{NULL};
    Node*eh{NULL};
    Node*oh{NULL};
    Node*ot{NULL};

    Node* temp = head;

    while(temp != NULL){
        
        int val = temp->data;
        bool isEven = (val%2 == 0);

        if(isEven){
            //add to my even ll
            if(eh==NULL){
                eh = temp;
                et = eh;
                temp = temp->next;
                et->next = NULL;
            }else{
                et->next = temp;
                temp=temp->next;
                et = et->next;
                et->next=NULL;
            }

        }else{
             if(oh==NULL){
                oh = temp;
                ot = oh;
                temp = temp->next;
                ot->next = NULL;
            }else{
                ot->next = temp;
                temp=temp->next;
                ot=ot->next;
                ot->next=NULL;
            }
        }
   
    }
    
    if(oh==NULL){
        return eh;
    }

    ot->next = eh;
	return oh;
}

