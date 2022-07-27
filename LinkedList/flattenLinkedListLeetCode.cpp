#include<bits/stdc++.h>
using namespace std;

class Node{
    public :
    Node* prev;
    Node *next;
    Node* child; 
};
//https://leetcode.com/problems/flatten-a-multilevel-doubly-linked-list/submissions/

pair<Node*,Node*> solve(Node*head){
        if(head == NULL){
            return {NULL,NULL};
        }
        if(head->next == NULL && head->child== NULL){
            return {head,head};
        }
        pair<Node*,Node*>c = solve(head->child);
        pair<Node*,Node*>n = solve(head->next);
        pair<Node*,Node*>ans(NULL,NULL);
        if(c.first){
            c.first->prev = head;
            head->next = c.first;
            head->child = NULL;
            if(n.first){
                c.second->next = n.first;
                n.first->prev = c.second;
                ans.first = head;
                ans.second = n.second;
            }else{
                ans.first = head;
                ans.second = c.second;
            }
        }else{
            if(n.first){
                n.first->prev = head;
                head->next = n.first;
                ans.first = head;
                ans.second = n.second;
            }
        }
        return ans;
        
    }
    
    Node* flatten(Node* head) {
        return solve(head).first;
    }