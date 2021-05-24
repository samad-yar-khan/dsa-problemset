#include<iostream>
#include "linkedList.cpp"
using namespace std;

//here we find the kth index element frokm end without finding the length
//in the prev medthos we iteated once to find the llegth
//the we iterated n-k times to ggt to our elemnt
//but using the point runner technique we use a fats pointer and a slow pointer 
//and itetate through the ll only once 
//hence optimissing our code

int getNthFromLast(struct Node *head, int n)
{
    Node*fast = head ;
    Node*slow = head ;
    
    //suppose oyr linked list of length N 
    //so we take our fast node n node ahead
    
    int K = n;
    while(K > 0 && fast!=NULL){
        fast = fast->next;
        K--;
    }
    
    //edge case we have exhausted the LL but k isnt exhausted
    if(fast == NULL && K>0){
        return -1;
    }
    
    //now we will move both fast and slow pts ahead smilustanously 
    //and we stop when our fast becomes NULL
    //at this pont ppur slow pointer reaches the kth node from the end
    //explaiataion we initiially moved K nodes ahead ith fast
    //no as both are moving ,
    //by the time our fast reaches the end , it will have to traverse N-K noes , 
    //and alog with fast , slow will also traverse N-K nodes from teh start ,
    //that means ist left with K nodes from the end 
    //and thats what we need
    //so in this method we only needed to traverse thorugh the ll once without finding the length
    
    while(fast!=NULL){
        fast=fast->next;
        slow = slow->next;
    }   
    
    return slow->data;
    
}