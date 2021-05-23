#include<iostream>
using  namespace std;
#include "linkedList.cpp"

Node* sortedMerge(Node* head1, Node* head2)  
{  
    // code here

    Node* h1 =head1;
    Node* h2 = head2;

    Node* head = NULL;
    Node*tail = NULL;

    if(h1->data <= h2->data){
        head = h1;
        tail = head;
        h1=h1->next;
    }else{
        head=h2;
        tail = head;
        h2=h2->next;
    }

    while(h1!=NULL && h2!=NULL){

        if(h1->data <= h2->data){
            tail->next = h1;
            h1=h1->next;
            tail = tail->next;
        }else{
            tail->next = h2;
            h2=h2->next;
            tail = tail->next;
        }

    }

    while(h1!=NULL){
         tail->next = h1;
        h1=h1->next;
        tail = tail->next;
    }

    while(h2!=NULL){
         tail->next = h2;
        h2=h2->next;
        tail = tail->next;
    }

    return head;

}  

int main(){

    Node*head1;
    Node*head2;
    cin>>head1>>head2;

    Node*mergeHead = sortedMerge(head1 , head2);

    cout<<mergeHead<<"\n";
    return 0;

}



