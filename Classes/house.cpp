#include<bits/stdc++.h>
using namespace std;

int a=0;
class house{

    public:
        char*houseName;
        static int h;
    private:
        int houseId;
    public :

    //once we have a constructor in place the inbuild one won work
    house(int id){
        // houseName = new char[10];
        houseId = id;
       
        // cout<<"C\n";
    }

    house(house const& h){
        this->houseId=h.houseId;
        delete [] this->houseName;
        int len = strlen(h.houseName);
        this->houseName = new char[len];
        strcpy(this->houseName,h.houseName);
    }

    //setter
    int setHouseID(int hId){
        if(hId>=0){
            this->houseId=hId;
            return hId;
        }
        return 0;
    }
    int getHouseId(){
        return this->houseId;
    }
    void printAdress(){
        cout<<this<<"\n";
    }
    static void hh(){
        cout<<h<<"\n";
    }
    //distruicor
    ~house(){
        delete [] this->houseName;
        // cout<<"D"<<this->houseId<<"\n";
    }

};




int main(){
    // vector<house>houses(10);
    house a(1);
     char name[] = "nameyar";
    a.houseName=name;
    // a.printAdress();
    cout<<"\n";
    // cout<<&a;
    //shallow
    //only the firtsv pointer is coppied
    house b(a);//inbuuilt copy c
   
    // b.houseName=name;
    cout<<a.houseName<<"\n";
    cout<<b.houseName<<"\n";
    house::h=1;
    a.houseName[0] = 'A';
    cout<<b.houseName;
    house::hh();
}
