#include<bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int k = 0;
        ListNode*t = head;
        while(k<n && t!=NULL){
            t=t->next;
            k++;
        }
        
        ListNode*curr = NULL;
        while(t!=NULL){
            t=t->next ;
            if(curr == NULL){
                curr = head;
            }else{
                curr = curr->next;   
            }
        }
        if(curr == NULL){
            head=head->next;
        }else{
            if(curr && curr->next){
                curr->next = curr->next->next;
            }
        }
        return head;
    }