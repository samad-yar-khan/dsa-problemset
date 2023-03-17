#include<bits/stdc++.h>
using namespace std;

class TrieNode{
    
    public:
        char val;
        vector<TrieNode*>children;
        bool end;
    
    TrieNode(char val){
        this->val = val;
        this->children = vector<TrieNode*>(26,NULL);
        this->end = false;
    }  
    
    bool is_end_node(){
        return this->end;
    }
    void set_end_node(){
        this->end = true;
    }
    
};

class Trie {
public:
    
    public:
        TrieNode*root;
    
    Trie() {
        this->root = new TrieNode('\0');
    }
    
    
    void _insert(string& word, int ind, TrieNode*curr){
        if(ind >= word.length()){
            curr->set_end_node();
            return;
        }
        int curr_char_ind = word[ind] - 'a';
        if(curr->children[curr_char_ind]==NULL){
            curr->children[curr_char_ind] = new TrieNode(word[ind]);
        }
        _insert(word, ind+1, curr->children[curr_char_ind]);
    }
    
    bool _search(string& word, int ind, TrieNode*curr, bool prefix = false){
        if(ind >= word.length()){
            return  prefix || curr->is_end_node();
        }
        int curr_char_ind = word[ind] - 'a';
        if(curr->children[curr_char_ind]==NULL){
            return false;
        }
        return _search(word, ind+1, curr->children[curr_char_ind], prefix);
    }
    
    void insert(string word) {
        _insert(word, 0, this->root);
    }
    
    bool search(string word) {
        return _search(word, 0, this->root);
    }
    
    bool startsWith(string prefix) {
        return _search(prefix,0,this->root,true);
    }
};