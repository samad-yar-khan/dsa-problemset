#include<iostream>
using namespace std;

template <typename T>

class Node{

    public:

        T data;
        Node<T>* next;


    Node(){
        data = 0;
        next = NULL;
    }

    ~Node(){
        delete next;
    }

};

template <typename V>

class Stack{

    private :

        Node<V>* head;
        int size;

    public :

        Stack(){
            head = NULL;
            size = 0;
        }

        void push(V data){

            Node<V>* newNode = new Node<V>;

            newNode->data = data;
            newNode->next = head;
            head = newNode;
            size++;

        }

        V pop(){

            if(size == 0){
                cout<<"Empty stack\n";
                return 0;
            }

            V data = head->data ;
            Node<V>* nextNode = head->next;
            head->next = NULL;

            delete head;
            head = nextNode;
            size--;
            return data;
        }   

        V top(){

            if(size == 0){
                cout<<"Empty stack\n";
                return 0;
            }

            V data = head->data ;
            return data;
        }   

        bool isEmpty(){
            return (size==0);
        }

        int getSize(){
            return this->size;
        }

        ~Stack(){
            delete head;
        }


};