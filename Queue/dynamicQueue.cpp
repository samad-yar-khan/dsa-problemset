#include<iostream>
using namespace std;

template <typename T>

class Queue{

    private:

        T* data;
        int front_index;
        int next_index;
        int size;
        int capacity;

    public :

        Queue(){
            data = new T[5];
            size = 0;
            capacity = 5;
            front_index=-1;
            next_index=0;
        }


         Queue(int s){
            data = new T[s];
            size = 0;
            capacity = s;
            front_index=-1;
            next_index=0;
        }

        ~Queue(){
            delete [] data;
        }

        void enque(T data_element){
            
            if(size == capacity){
                
               
               T* newQ = new T[capacity*2];

               //now we copy al those elemnt to this queue
               for(int i = 0 ; i < capacity ; i++){
                   newQ[i] = data[(front_index+i)%capacity];
               }

               front_index = 0 ;
               next_index= capacity;
               capacity=2*capacity;
               delete [] data;
               data = newQ;

           
            }

            if(size == 0 || front_index == -1){
                front_index = next_index;
            }

            data[next_index] = data_element;
            next_index = (next_index+1)%capacity;
            
            size++;
        }

        T front(){
            if(size == 0 || front_index==-1 ){
                cout<<"Queue is empty !";
                return 0;
            }

            return data[front_index];
        }

        T deque(){

            if(size == 0){
                cout<<"empty queue\n";
                return 0;
            }

            T my_data =  data[front_index];
            front_index = (front_index+1)%capacity;
            size--;
            return my_data;

        }

        int getSize(){
            return size;
        }

        bool isEmpty(){
            return size == 0;
        }
};