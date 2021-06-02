#include<iostream>
#include<stack>
#include<string.h>
using namespace std;



bool checkRedundantBrackets(char *input) {
    	
    int i = 0 ;
    
    stack<char> st;
    
    
    while(input[i] != '\0'){
        
        if(input[i] == ')'){    

            if(st.empty()){
                return true;
            }

            int j {0};
            while(st.top() != '('){
                st.pop();
                j++;
            }
            
            st.pop();
            if(j<=1){
                return true;
            }

        }else{
            st.push(input[i]);
        }

        i++;
    }
    
    return false;
  
    
}


int main(){

    char*c = new char[100];
    cin>>c; 

    cout<<checkRedundantBrackets(c);

    delete []c ;

}






