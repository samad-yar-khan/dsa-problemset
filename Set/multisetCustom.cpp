#include<bits./stdc++.h>
using namespace std;

class students{

    public :

        float marks ;
        const string rollNumber ;
        const string name;
    //inirialiser list
    students( float marks_feeded , string name_feeded  , string roll_number):rollNumber(roll_number) , name(name_feeded){

        marks =marks_feeded;
    }

    //copmparator 
    //just like the pq we need to make a class and overoadl the () operator


};

class compareByMarks{
    public :

    bool operator ()(students a , students b){
        return a.marks>b.marks;
    }
};

class compareByName{
    public :

    bool operator ()(students a , students b){
        return a.name<b.name;
    }
};



int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r" , stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    int numStudents = 0 ;
    cin>>numStudents;
    multiset<students , compareByMarks> marksList;
    multiset<students , compareByName> rollList;

    while(numStudents--){
        string name ;
        cin>>name;
        // cin>>name;
        string rollNumber ;
        // getline(cin , rollNumber);
        cin>>rollNumber;
        float marks;
        cin>>marks ;
        students s(marks,name , rollNumber);
        marksList.insert(s);
        rollList.insert(s);
    }   

    //marks wise sorted List
    cout<<"ShortList\n";
    for(multiset<students>::iterator itr = marksList.begin(); itr != marksList.end() ; itr++)
    {   
        cout<<itr->name<<" "<<itr->rollNumber<<" "<<itr->marks<<"\n";
    }

    //added a new students
    string n{"Om Patahak"};
    string rn {"2019COEFOD"};
    float gpa{100};

    students oneAboveALL(gpa , n , rn);
    marksList.insert(oneAboveALL);
    rollList.insert(oneAboveALL);
     cout<<"\n New ShortList\n";
    for(multiset<students>::iterator itr = marksList.begin(); itr != marksList.end() ; itr++)
    {   
        cout<<itr->name<<" "<<itr->rollNumber<<" "<<itr->marks<<"\n";
    }

    //all studnets 
    cout<<"\n\n all studnets \n";
      for(multiset<students>::iterator itr = rollList.begin(); itr != rollList.end() ; itr++)
    {   
        cout<<itr->name<<" "<<itr->rollNumber<<" "<<itr->marks<<"\n";
    }


    return 0;

}

/*
5

Samad
2019UIC3595
80.6

Abubakar
2019UEC3595
79

Saransh
2019UIC3595
88.9


Dhruv 
2019UIC3605
55


pareek 
2019UIC3601
87

*/