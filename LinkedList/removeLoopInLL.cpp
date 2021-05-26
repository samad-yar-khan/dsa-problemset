    #include<iostream>
    using namespace std;
    #include "linkedList.cpp"

    //https://practice.geeksforgeeks.org/problems/remove-loop-in-linked-list/1#
//     Remove loop in Linked List 
// Medium Accuracy: 47.96% Submissions: 100k+ Points: 4
// You are given a linked list of N nodes. Remove the loop from the linked list, if present. 
// Note: X is the position of the node to which the last node is connected to. If it is 0, then there is no loop.

// Example 1:

// Input:
// N = 3
// value[] = {1,3,4}
// X = 2
// Output: 1
// Explanation: The link list looks like
// 1 -> 3 -> 4
//      ^    |
//      |____|    
// A loop is present. If you remove it 
// successfully, the answer will be 1. 
// â€‹
// Example 2:

// Input:
// N = 4
// value[] = {1,8,3,4}
// X = 0
// Output: 1
// Explanation: The Linked list does not 
// contains any loop. 
    
    Node* findIntersection(Node* head)
    {
        
        Node*s = head;
        Node*f = head->next ;
        
        while(f!=NULL && f->next!=NULL){
            s=s->next;
            f=f->next->next;
            
            if(f==s){
                return f;
            }
            
        }
    
        
        return NULL;
    }
    
    void removeLoop(Node* head)
    {
        // code here
        // just remove the loop without losing any nodesif
        if(head==NULL || head->next == NULL){
            return ;
        }        
        
        Node*i = findIntersection(head);
        
        if(i == NULL){
            return;
        }
        
        Node*p1 = i;
        Node*p2 = head;
    
        while(i->next != p2){
            i=i->next;
            p2=p2->next;
        }
        i->next = NULL;
        
        return ;;
        
    }