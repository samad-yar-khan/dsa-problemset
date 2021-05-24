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

    if(h1!=NULL){
         tail->next = h1;
    }

    if(h2!=NULL){
        tail->next = h2;
    }

    return head;

}  

Node* mergeRecursive(Node*head1 , Node*head2){

    //bcc
    if(head1==NULL){
        return head2;
    }
    if(head2 == NULL){
        return head1;
    }

    //we need to woek on our node and choose the smlller out of the two head 
    Node*ourNode = NULL;

    Node*h1;
    Node*h2;
    h1 = head1;
    h2 = head2;

    if(h1->data <= h2->data ){
        ourNode = h1;
        h1=h1->next;
    }else{
        ourNode = h2;
        h2=h2->next;
    }

    //now we will exct recuson to return to us the merged ll

    Node*newHead = mergeRecursive(h1,h2);

    //our node shoul be at head
    ourNode->next = newHead;
    newHead = ourNode;
    return newHead;


}

int main(){

    Node*head1;
    Node*head2;
    cin>>head1>>head2;

    Node*mergeHead = mergeRecursive(head1 , head2);

    cout<<mergeHead<<"\n";
    return 0;

}



