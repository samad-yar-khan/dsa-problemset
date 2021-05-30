#include "StackLL.cpp"

int  main(){

    Stack<int> s;

    for(int i = 0 ; i < 9 ; i++){

        s.push(i);
        cout<<"\nsize:"<<s.getSize();
    }

    for(int i = 0 ; i < 9 ; i++){

        cout<<s.pop()<<"\n";
    }

}
