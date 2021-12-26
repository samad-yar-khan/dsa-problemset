#include<bits/stdc++.h>
using namespace std;


class people{

    string name;
    int age ;

    public:
    
    people(string name ,int  age){
        this->name = name;
        this->age = age;
    }
    void setDetails(string name, int age){
        this->name = name;
        this->age = age;
    }

    void getDetails(){
        cout<<this->name<<" "<<this->age<<"\n";
        
    }
};


int main(){
 string name="name";
    int age = 1;
    people p1 = people(name ,age);
    people p2(name , age);
   
    p1.setDetails(name ,age);
    p1.getDetails();
    return 0;
}