#include<iostream>
using namespace std;
#include  "linkedList.cpp"



Node *swapNodes(Node *head, int i, int j)
{
	//Write your code here
    if(i == j){
        return head;
    }
    
    int I = min(i,j);
    int J = max(i,j);

    if(I == 0){

        if(J-I == 1){
            Node*temp = head;
            Node*newHead = head->next;
            temp->next = newHead->next;
            newHead->next = temp;

            return newHead;
        }else{

            Node*temp = head;
        
            int itr = 0 ;
            while(itr < I-1 ){
                temp = temp ->next;
                itr++;
            }

            Node* jN = temp->next;
            Node*restLL = jN->next;
            jN->next = head->next;
            head->next = restLL;
            head = jN;
            return head;


        }

    }else{

         if(J-I == 1){
            Node*temp = head;
            
            int itr = 0 ;
            while(itr < I-1 ){
                temp = temp ->next;
                itr++;
            }
            Node* currT= temp;
            Node*myI = temp->next;
            Node*myJ = temp->next->next;

            Node* restLL = myJ->next;

            currT->next = myJ;
            myJ->next = myI;
            myI->next = restLL;
            return head;
         

        }else{

            Node*fN = head;
            Node*sN = head;
            
            int itr = 0 ;
            while(itr < I-1){
                fN = fN ->next;
                itr++;
            }

            int itr2=0;
            while(itr2 < J-1){
                sN = sN->next;
                itr2++;
            }

            Node*firstNode = fN->next;
            Node*secondNode = sN->next;

            Node* LLmid = firstNode->next;
            Node*LLafter = secondNode->next;

            fN->next = secondNode;
            secondNode->next = LLmid;
            
            sN->next = firstNode;
            firstNode->next = LLafter;

            return head;

        }

    }
    
    
}