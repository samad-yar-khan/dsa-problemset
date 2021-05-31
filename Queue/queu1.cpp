#include "staticQueue.cpp"

int main(){

    Queue<int> q;

    q.enque(1);
    q.enque(2);
    q.enque(3);
    q.enque(4);
    q.enque(5);

    cout<<q.deque()<<"\n";
    cout<<q.deque()<<"\n";
    cout<<q.deque()<<"\n";

    q.enque(1);
    q.enque(2);
    q.enque(3);
     q.enque(1);
    q.enque(2);
    q.enque(3);

    cout<<q.deque()<<"\n";
    cout<<q.deque()<<"\n";
    cout<<q.deque()<<"\n";
     cout<<q.deque()<<"\n";
    cout<<q.deque()<<"\n";
    cout<<q.deque()<<"\n";

    cout<<"size "<<q.getSize()<<"\n";


}