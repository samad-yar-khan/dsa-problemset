#include<iostream>
using namespace std;

class Vehicle{

    private:
        string id;
        int milage ;
    
    public:

        int wheels ;
        int seats ;
        string color ;

    //param constrcutor
    Vehicle( int wheels , int seats , string color ){
        this->wheels = wheels ;
        this->seats = seats ;
        this->color = color;
    }

    //deafaultt cons
    Vehicle(){
        this->wheels = 2;
        this->seats = 2;
        this->color = "RED";
    }   

    //setter 
    void setId(string id , string pass){
        if(pass == "p"){
            this->id = id;
            cout<<"ID updated :"<<this->id;
        }else{
            cout<<"WRONG ID!\n";
        }

    }

    void setMil(int mil , string pass){
        if(pass == "p"){
            this->milage = mil;
            cout<<"ID milage :"<<this->milage;
        }else{
            cout<<"WRONG ppass!\n";
        }

    }

    void getProps(){
        cout<<"wheels : "<<this->wheels<<'\n';
        cout<<"milage : "<<this->milage<<'\n';
        cout<<"id : "<<this->id<<'\n';
        cout<<"color : "<<this->color<<'\n';
        cout<<"seats : "<<this->seats<<'\n';
    }

    ~Vehicle(){//destroructor is a function which is called internally whneve rwe want go dlete an opbketc and del;;coate its memory

        cout<<"Deallocated !\n";
    }

    Vehicle(Vehicle V){
        
    }


};

int main(){
    Vehicle V1;
    //V1.Vehicle();
    V1.getProps();
    string id = {"!@#11" };
    V1.setId(id  ,  "p");
    V1.getProps();
    cout<<"==v2==\n";
    Vehicle* V2 = new Vehicle(V1); //vopy constructopre
    (*V2).getProps();
    delete V2;

    Vehicle V3;
    V3 = *V2; //copy assoigne,mnt operator
    cout<<"V3\n";
    V3.getProps();

    Vehicle V4 = V3;//copy assigmnmemnt X ->  V4.Vehicle(V3) 


}