#include<iostream>
using namespace std;
#include<cstring>
#include<vector>
#include<string>

class Human {

    private://access modifier
    char* bloodGroup;
    string birthDate; 
    int const id;
    static int total;

    public://access modifier
    char* name;

    //default constrcutor 
    // Human():id(abs(rand()*100)%10){
    //     bloodGroup= new char[100];
    //     birthDate="";
    //     name = new char[100];
    //     for(int i =0;i<100;i++){
    //         bloodGroup[i] =  '\0';
    //         name[i] = '\0';
    //     }
    //     //this will store the adress of the company
    //     //
    // }
    //initializer list for const vals
    Human(char* bloodGroup, char* name, string birthDate, int id):id(id){
        
        this->bloodGroup = new char(strlen(bloodGroup)+1);
        strcpy(this->bloodGroup,bloodGroup);
        this->name = new char(strlen(name)+1);
        strcpy(this->name,name);
        this->birthDate = birthDate;
        total++;
        //this will store the adress of the company
        //
    }
    //in shallow copy only the adress of the firts array, string index element is copied
    //in deep copy the new array/string is created and points to anew memory location
    //deep copy constructor 
    Human(Human const &h):id(h.id){
        this->bloodGroup = new char(strlen(h.bloodGroup)+1);
        strcpy(this->bloodGroup,h.bloodGroup);
        this->name = new char(strlen(h.name)+1);
        strcpy(this->name,h.name);
        this->birthDate = birthDate;
        
total++;
    }

    static int getTotalHuman(){
        return total;
    }

    //cosnt fucntions for const values
    void printDets() const{
        cout<<id<<"\n";
    }

};

//intialize static members
int Human::total=0;

int main(){
    char name[] = "name";
    char bg[] = "B+";
    string dob("23/12/1999");
    Human h(bg,name,dob,100);
    Human h2 = h;
    

    // cout<<h2.name<<"\n";
    // h2.name[0] = 'f';
    // cout<<h.name<<"\n";
    cout<<Human::getTotalHuman()<<"\n";
}
