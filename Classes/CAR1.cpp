#include<bits/stdc++.h>
using namespace std;


class vehicle{
    public : 
        int wheels;
    protected :
        int cost ;
    private :
        int id;

    public :
        vehicle(int id , int cost , int wheels){
            this->id = id;
            this->cost = cost;
            this->wheels = wheels;
        }
};

class car : public vehicle{
    public:
        int color;
        
    protected :
        int number;
    public :
        car(int color ,int number):vehicle(0,199,4){
            this->color = color;
            this->number = number;
        }

};

class honda : public car{
    public:
        int seats;
        honda(int seats , int color , int number):car(color , number){
            this->seats = seats;
        }
};
int main(){
    honda h(4 , 1,2);
    cout<<h.wheels;
}