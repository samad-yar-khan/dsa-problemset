#include "dynamicQueueLL.cpp"

int main(){

    Queue<int> q;

    // for(int i = 0 ; i < 5 ; i++){
    //     q.enque(i);
    // }

    // q.deque();
    // q.deque();

    // for(int i = 0 ; i < 10 ; i++){
    //     q.enque(i*10);
    // }
    // cout<<"Size "<<q.

    // for(int i = 0 ; i < q.getSize() ; i++){
    //     cout<<q.front()<<"\n";
    //     q.deque();
    // }

    for(int i = 0 ; i < 8 ; i++){
        q.enque(i);
        cout<<"size"<<q.getSize()<<"\n";
    }

    cout<<q.getSize()<<"\n";

    int s =q.getSize();

    for(int i = 0 ; i <s-4 ; i++){
       
       cout<<"DEQUE : "<<q.deque()<<"\n";
    }

     for(int i = 0 ; i < 8 ; i++){
        q.enque(i);
    }

s =q.getSize();
    for(int i = 0 ; i <s ; i++){
       
       cout<<q.deque()<<"\n";
    }

}