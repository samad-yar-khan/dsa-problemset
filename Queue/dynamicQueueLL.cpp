#include <iostream>
using namespace std;

template <typename T>

class Node
{
public:
	T data;
	Node<T>*next;

	Node(){
		this->data = 0;
		this->next = NULL;
	}

	Node(T data)
	{
		this->data = data;
		this->next = NULL;
	}

    ~Node(){

        delete(this->next);

    }
};


template <typename V>

class Queue{

    private :

        Node<V>* head;
        Node<V>* tail;
        int size;
    
    public :

        Queue(){
            head = NULL;
            tail = NULL;
            size = 0 ;
        }

        ~Queue(){
            delete head;
        }

        void enque(V data){

            Node<V>*newNode = new  Node<V>;
            newNode->data = data;

            if(head == NULL){
                head = newNode;
                tail = newNode;
            }else{
                tail->next = newNode;
                tail = tail->next;
            }

            size++;


        }

        V front(){

            if(size == 0 || head == NULL){
                cout<<"Empty queeu\n";    
                return 0;
            }
            
            return head->data;

        }   

        V deque(){
              if(head == NULL || size == 0){
                cout<<"Empty queeu\n";    
                return 0;
            }

            V data = head->data ;
            Node<V>* headNode = head;
            head=head->next;
            headNode->next = NULL;
            delete headNode;
            
        
            size--;
            return data;

        }

        int getSize(){
            return size;
        }

        bool isEmpty(){
            return size == 0 ;
        }


};

