#include<bits/stdc++.h>
using namespace std;

class TrieNode{

    public :

        char data ;
        bool terminal;
        unordered_map<char , TrieNode*> childred;

        TrieNode(char data ){
            this->data =data; 
            terminal = false;
        }

};


class Trie{

    public :

       TrieNode * root ;
       int cnt ;

        Trie(){`
            root = new TrieNode('\0');
            cnt = 0 ;
        }

        void insert( Trie,char *str){

            

        }
};
