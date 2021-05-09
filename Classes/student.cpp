#include<iostream>
#include<string>
#include<cstring>
using  namespace std;


class student {

    public : 

        int age;
        char* name ;
        const int rollNumber;
    private :

        int marks ;

    public:
    
    //default constructor
    // student(){
    //     (*this).age = 0;
    //     (*this).marks = 0 ;
    // }

    //parametrirsed construtor
    student(int age , char* name , int rollnumber) : rollNumber(rollNumber){

        this->age = age ;
        this->name = new char[strlen(name) + 1];//now this is our own array
        strcpy(this->name , name);

    }
    //copy construtor
    student(student const & s) : rollNumber(s.rollNumber){
     
        this->age = s.age ;
        this->name = new char[strlen(s.name) + 1];//now this is our own array
        strcpy(this->name , s.name);


    }


    //setters
    void set_marks (int marks){

        (*this).marks = marks;

    }

    //getters

    void getDetails (){
        cout<<"Name : "<<(*this).name<<"\n";
        cout<<"age : "<<(*this).age<<"\n";
        cout<<"marks : "<<(*this).marks<<"\n";
        cout<<"roll : "<<(*this).rollNumber<<"\n";

        cout<<this<<"\n";
    }

    ~student()
    {
        delete [] this->name;
    }


};


int main(){

    char name[] = "Samad"; //108
    student S1(11 ,name , 3000);
    S1.getDetails();

    // student *s2 = new student(12 ,name);

    // cout<<(*s2).name<<"\n"; //108
    // cout<<s2->name<<"\n"; 

    // name[1] = 'o';
    // cout<<S1.name<<"\n";//108

  
    // cout<<(*s2).name<<"\n";

    student S2(S1);
    S2.getDetails();
    strcpy(S2.name , "samerr");

    cout<<S1.name<<"\n";//even this coes out to be sameer due to shallow copy of our  deafu;t copy constructor , sp we change this

    cout<<S2.name<<"\n";//even this coes out to be sameer due to shallow copy of our  deafu;t copy constructor , sp we change this


    // s2->set_marks(100);
    // s2->getDetails();

    // (*s2).set_marks(200);
    // (*s2).getDetails();


    


    return 0;
}