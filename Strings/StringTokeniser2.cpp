#include<iostream>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
using namespace std;

char* myStrtok(char* str , char delim){

    static char* input =  NULL;
    //incase the input str is not NULL
    if(str!= NULL){
        input = str;
    }

    //base case 
    if(input==NULL){
        return NULL;
    }
    
    char* output = new char[strlen(input) +1];
    int i = 0 ; // help us iterate 
    for( ; input[i] != '\0' ; i++){

        if(input[i] != delim){
            //copy to op
            output[i] = input[i];

        }else{

            //delimator milte hi finish the sring and break
            output[i] = '\0';
            input = input+i+1; //moved ptr ahead
           return output;
        }
    }

    //corner case 
    //we are in the last token
    //in this case output array will have the right charaters , but wont have null char at the end
    //so put null char at end as
    output[i] = '\0';
    input = NULL ; // hamara string khatam hogya 
    return output;

}
//

int main(){
     char s[100]  = "Hey what up !";
    char delim =  ' ';
    vector <char*> subs;
    char *ptr = myStrtok(s,' ');
   
   //strtok stores  the left over string in its own static storage 
    while(ptr != NULL){

        cout<<ptr<<"\n";
        ptr = myStrtok(NULL , ' ');
       
    }

}