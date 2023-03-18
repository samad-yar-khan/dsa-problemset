#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/design-browser-history/

class DLL{
    
    public:
    
    string val;
    DLL* next;
    DLL* prev;
    
    DLL(string val, DLL*p=NULL, DLL*n=NULL){
        this->val = val;
        this->prev = p;
        this->next = n;
    }
    
    ~DLL(){
        if(this->next){
            delete this->next;    
        }
    }
      
};

class BrowserHistory {

private: 
    
    DLL* curr;
    
public:
    BrowserHistory(string homepage) {
        this->curr = new DLL(homepage);
    }
    
    void visit(string url) {
        if(this->curr && this->curr->next){
             delete this->curr->next;   
        }
        curr->next = new DLL(url,curr);
        curr=curr->next;
    }
    
    string back(int steps) {
        while(curr!=NULL && curr->prev!=NULL && steps>0){
            curr=curr->prev;
            steps--;
        }
        return curr->val;
    }
    
    string forward(int steps) {
        while(curr!=NULL && curr->next!=NULL && steps>0){
            curr=curr->next;
            steps--;
        }
        return curr->val;
    }
};
