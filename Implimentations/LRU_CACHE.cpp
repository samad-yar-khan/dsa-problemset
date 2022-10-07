#include <bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/lru-cache/
/*
Primary Requirements :
    - We have a capacity for the LRU Cache - n
    - When we add an element, it will be the last recently used, 
    - If a keys value is fetched :
        - if key is available in the LRU cache, then we return its value and it becomes last recently uses
        - if key is not present, then we return -1
    - If or lru cache is full, and we try to add a new key value pair, the least recently used key value pair will be  deleted  and we add the new node

Solution 
    - context : Watch strivers vid

*/

class node{
    
    public :
    
    int key;
    int value;
    node* prev;
    node* next;
    
    node(int key, int value, node*prev, node* next){
       this->key = key;
       this->value = value;
       this->prev = prev;
       this->next = next;
    }

};

class LRUCache {
    
    int capacity;
    node* head;
    node* tail;
    unordered_map<int,node*>mp;
    int currSize;
    
    void add_node(int key, int val){
        node* curr = new node(key,val,NULL,NULL);
        node* temp = this->head->next;
        this->head->next = curr;
        curr->prev = this->head;
        curr->next = temp;
        temp->prev = curr;
    }
    
    void delete_node(node*curr){
        node*p = curr->prev;
        node*n = curr->next;
        p->next = n;
        n->prev = p;
        curr->prev = NULL;
        curr->next = NULL;
        
        delete curr;
    }
    
    void remove_from_map(int key){
        this->mp.erase(key);
    }
    
    void add_to_map(int key, node* node_ad){
        mp.insert({key,node_ad});
    }
    
public:
    
    LRUCache(int capacity) {
        this->capacity = capacity;
        this->head = new node(-1,-1,NULL,NULL);
        this->tail = new node(-1,-1,NULL,NULL);
        head->next = tail;
        tail->prev = head;
        this->currSize = 0;
    }
    
    int get(int key) {
        if(mp.count(key) == 0){
            return -1;
        }
        node* n = mp[key];
        int value = n->value;
        delete_node(n);
        remove_from_map(key);
        add_node(key,value);
        add_to_map(key,head->next);
        return value;
    }
    
    void put(int key, int value) {
        
        if(mp.count(key) != 0){
            node* n= mp[key];
            delete_node(n);
            remove_from_map(key);
            add_node(key,value);
            add_to_map(key,head->next);
        }else{
            if(currSize >= capacity){
                node* n = tail->prev;
                remove_from_map(n->key);
                delete_node(n);
                currSize--;
            }
            add_node(key,value);
            add_to_map(key,head->next);  
            currSize++;
        }
        
    }
};
