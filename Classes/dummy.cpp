#include<bits/stdc++.h>
using namespace std;


class A{
    public :
        int x ;
        A(int a){cout<<a<<"\n";}
};

class B:virtual public A{
    public :
        int y ;
        B():A(1){cout<<"B\n";}

        void sikeC();
};

//abstract 
class C:virtual public A{
    private :
        int c;
    public :
        int z ;
        C():A(2){cout<<"C\n";}

        virtual void p(){
            cout<<'a';
        };//pure virual
    friend void B::sikeC();
};

void B::sikeC(){
    C cc;
    cc.c=1;
    cout<<cc.c<<"\n";
}

class D: public C, public B{

    public :
        int z;
        D():A(3){cout<<"D\n";}
        void p(){
            cout<<'d';
        }


};

int main(){
    D d1;
    cout<<"\n";
    C*c=&d1;
    c->p();

    B bb;
    bb.sikeC();
}