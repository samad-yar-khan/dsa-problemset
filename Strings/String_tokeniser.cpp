#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
using namespace std;


int main(){

    char s[100]  = "Hey whats up !";
    char delim[100] = " ";
    vector <char*> subs;
    char *ptr = strtok(s," ");
   
   //strtok stores  the left over string in its own static storage 
    while(ptr != NULL){

        cout<<ptr<<"\n";
        ptr = strtok(NULL , " ");
       
    }

   

}