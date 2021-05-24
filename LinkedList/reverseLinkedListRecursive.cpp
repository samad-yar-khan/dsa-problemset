#include<iostream>
using  namespace std;
#include "linkedList.cpp"

Node* reverseRecursive(Node*head){

    //edge case
    if(head == NULL){
        return head;
    }

    //bc//only ne elemnt in ll no need to reversr
    if(head->next==NULL)
    {
        return head;
    }

    //ih

    //we will let recusion reverse the smaller LL  and return us the head of thee smaller LL
    //now we detatch or elemnt from 
    //we have HEAD-1->2->3->4->5->NULL
    //we dteatch this Our Node-1- SMmallHead->2->3->4->5->NULL
    //rec will get me NewHead-5->4->3->2
    //i just irate to my tail ie 2 and return head of this ie NewHEad
    

    Node* myNode = head;
    Node* smallHead = head->next;
    //detach
    myNode->next = NULL;

    Node* newHead = reverseRecursive(smallHead);

    //now itearte to the end and link our new lls tail to our node


    //is
    Node*temp = newHead ;
    while(temp->next!=NULL){

        temp = temp->next;

    }

    temp->next = myNode;

    return newHead;

}

//optimise to o(N)
//to skip the reduncancy of iterating to tail each time we wll return both head and tail of linked list
pair<Node* , Node*> reverseRecOptimised(Node* head){

    ///edge case
    if(head == NULL){
        pair<Node*,Node*> ans(head,head);
        return ans;
    }

    //bc
    if(head->next == NULL){
        pair<Node*,Node*> ans(head,head);
        return ans;
    }

    //ih
    Node*ourNode = head;
    Node*smallHead = head->next;
    //detach
    head->next = NULL;

    pair<Node*,Node*> reversedLL = reverseRecOptimised(smallHead);

    //now we attatch tha tail to our node and make our node the new tail
    //is

    reversedLL.second->next = ourNode;
    reversedLL.second = reversedLL.second->next;

    return reversedLL ;


}




int main(){

    Node*head;
    cin>>head;
    cout<<head;
    pair<Node*,Node*> ans = reverseRecOptimised(head);
    cout<<ans.first;
}