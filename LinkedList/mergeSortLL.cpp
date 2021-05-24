#include<iostream>
using namespace std;
#include "linkedList.cpp"

Node* getMidNode(Node* head){

    if(head== NULL){
        return head;
    }

    Node*slow = head;
    Node*fast = head->next;
    
    while (fast!=NULL && fast->next!=NULL){

        slow = slow->next;
        fast = fast->next->next;
    }

    return slow ;
    
}

Node* mergeSorted(Node*head1 , Node*head2 ){

    if(head1==NULL || head2== NULL){
        return head1==NULL?head1:head2;
    }

    Node*h1 = head1;
    Node*h2 = head2;

    Node*mergedHead;
    Node*mergedTail;

    if(h1->data <= h2->data ){

        mergedHead = h1;
        mergedTail = h1;
        h1 = h1->next;

    }else{
        mergedHead = h2;
        mergedTail = h2;
        h2 = h2->next;
    }

    while (h1!=NULL && h2!=NULL)
    {
        /* code */
        if(h1->data <= h2->data ){
            mergedTail->next = h1;//atatch tail
            mergedTail = mergedTail->next;//make new tail
            h1 = h1->next;//go ahead in the ll as nodes been attatched
        }else{
             mergedTail->next = h2;
            mergedTail = mergedTail->next;
            h2 = h2->next;
        }
    }


    if(h1!=NULL){
        mergedTail->next = h1;
    }

    if(h2!=NULL){
        mergedTail->next = h2;
    }

    return mergedHead;

}

Node* mergeSort(Node*head){
    
    //bc
    if(head==NULL || head->next == NULL){
        return head;
    }

    //ih devide the ll into two halves
    //and call merges sort on both
    Node*h1 = head;
    Node*middleNode = getMidNode(head); 
    
    Node*h2 = middleNode->next;//head o secon half

    middleNode->next = NULL;//detttach

    h1 = mergeSort(h1);
    h2 = mergeSort(h2);

    //h1 and h2 are sorted so ww will now combine them and return orted lll
    Node* newHead = mergeSorted(h1, h2);

    return newHead;


}


int main(){

    Node*head ;
    cin>>head;
    head = mergeSort(head);
    cout<<head;

}