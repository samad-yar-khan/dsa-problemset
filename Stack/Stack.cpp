#include<iostream>
using namespace std;

template <typename T>

class Stack{

    private:

        T* data;//array
        int capacity;//this capacity will double whenver the next_index exceeds or become sequal to the capacity
        int next_index;//where my next element goies


    public:

        Stack(){

            this->data = new T[5];
            this->capacity = 5;
            this->next_index=0;

        }


        Stack(int sizcapae){

            this->data = new T[capacity];
            this->capacity = capacity;
            this->next_index=0;

        }

        void push(T element){

            // if(this->capacity == next_index){
            //     cout<<"Stack Over Flow\n";
            //     return;
            // }

            //dynamic stack
            if(this->capacity == next_index){

                //take a array of doube the size
                T* newData = new T[2*capacity];
               
                // copy element
                for(int i = 0 ; i < capacity ; i++){
                    newData[i] = data[i];
                }

                //change capacity
                capacity=capacity*2;
                delete [] data;
                data = newData;
            }

            this->data[next_index] = element;
            next_index++;

        }

        bool isEmpty(){

            if(this->next_index == 0){
                return true;
            }else{
                return false;
            }

        }

        T pop(){
            if(this->next_index == 0){
                return -1;
                cout<<"Stack under flow\n";
            }

            T myTop = this->data[next_index-1];
            this->next_index--;
            return myTop;

        }

         T top(){

            if(this->next_index == 0){
                return -1;
                cout<<"Empty Stack\n";
            }

            T myTop = this->data[next_index-1];
            return myTop;
            
        }

        int size(){
            return this->next_index;
        }

        ~Stack(){
            delete [] data;
        }


};