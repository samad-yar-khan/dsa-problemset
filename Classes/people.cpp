#include<bits/stdc++.h>
using namespace std;


class people{
    
    public:
    static int numPeople;
    char* name;
    int age ;
    const int rating;
    public:
    
    people(char* name ,int  age,int rating):rating(rating){
        this->name = new char[strlen(name)+1];
        strcpy(this->name , name);
        this->age = age;
        numPeople++;
    }
    //copy constructor

    people(people const  & p1):rating(p1.rating){
        this->age = age;
        this->name = new char[strlen(p1.name)+1];
        strcpy(this->name , name);
        numPeople++;
    }

    void setDetails(char* name, int age){
        this->name = name;
        this->age = age;
    }

    void getDetails () const{
        cout<<this->name<<" "<<this->age<<" "<<this->rating<<"\n";
        
    }
    ~people(){
        delete [] this->name;
        numPeople--;
    }
    static int getPeople(){
        return numPeople;
    }
};

int people::numPeople=0;

int main(){
    char name[]={"name"};
    int age = 1;
    people p1 = people(name ,age,21);
    people p2(name , age,21);
   
    p1.setDetails(name ,age);
    p1.getDetails();
    p1.name[2]='0';
    p2.getDetails();
    const people p3(name ,age,2);
    p3.getDetails();
    cout<<people::numPeople<<"\n";
    cout<<people::getPeople()<<"\n";
    return 0;
}