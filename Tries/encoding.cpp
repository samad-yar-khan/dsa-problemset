#include<bits/stdc++.h>
using namespace std;


class TrieNode{

    public :

        char data ;
        bool terminal;
        int count;
        unordered_map<char , TrieNode*> childred;

        TrieNode(char data ){
            this->data =data; 
            terminal = false;
            count=0;
        }
        
};


class Trie{

    public :

       TrieNode * root ;
       int cnt ;

        Trie(){
            root = new TrieNode('\0');
            cnt = 0 ;
        }

        void insert2(TrieNode*t , char*str){
            if(str[0] == '\0'){
                return;
            }

            if(strlen(str) ==1 ){
                t->terminal=true;
                t->count++;
            }

            char x=str[0];
   
        }

        void insert( Trie,char *str){

            if(str[0] == '\0')
            {
                return;
            }
        }
};
