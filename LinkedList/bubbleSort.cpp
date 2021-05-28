#include<iostream>
using namespace std;
#include "linkedList.cpp"

//basis misstake which iw as dong was taht on conition ehre we had to swithcn , instad
//of changing prev to my next and keeping curr same , i was keeping shift currr and moving foerads
//jab node swap karenge tto curr same rakho 
//previous ko next bando bas

Node* bubbleSort(Node* head){

    int l = 0;
 
    Node* t = head;
    while(t!=NULL){
        t=t->next;
        l++;
    }
    
      if(l<=1){
        return head;
    }
    
    Node *h = head;
    for(int i = 0 ; i < l-1 ; i++){
        Node* prev = NULL;
        Node* curr = h;
        Node* next = NULL;
        for(int j = 0 ; j < l-1-i  ; j++){
            
            next = curr->next;
            if(curr->data > next->data){
            
                if(prev == NULL){

                    Node*restLL = next->next;
                    next->next = curr;
                    curr->next = restLL;

                    h = next;

                    prev = next;
             
        

                }else{

                    Node*restLL = next->next;
                    next->next = curr;
                    curr->next = restLL;

                    prev->next = next;

                    prev = next;
                
                }

            }else{
                prev = curr ;
                curr =  curr->next;
            }

        }
    }


    return h;

}