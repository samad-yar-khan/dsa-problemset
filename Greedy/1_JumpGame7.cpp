#include <bits/stdc++.h>
using namespace std;


bool helper(string s , int minJ , int maxJ , int ourIndex , int*arr){

    int len = s.length();
    
    if(ourIndex == len-1 ){   
        return true ;
    }
    if(s.at(ourIndex) == '1' || ourIndex >= len ){
        arr[ourIndex] = 0;
        return false; //not a path
    }

    if(arr[ourIndex] != -1){
        return arr[ourIndex];
    }


    //ih
    bool ans = false;
    for(int i = ourIndex+minJ ; i <= ourIndex+maxJ && i<len ; i++){

        if(s.at(i) == '0'){
            ans = ans||helper(s , minJ , maxJ , i , arr);            
        }else{
            arr[i] = 0;
        }

        if(ans){     
            arr[i] = 1;
            break;
        }

    }

    arr[ourIndex] = ans;
    return ans;


}

bool  canReach(string s, int minJump, int maxJump){

    int*arr =new int[s.length()];
    for(int i = 0 ; i < s.length() ; i++){
        arr[i] = -1;
    }
    bool ans =  helper(s , minJump , maxJump , 0 , arr);

    delete [] arr;
    return ans;

}


int main(){


    int T{0};
    cin>>T;

    while(T--){
        string s{""};
        cin>>s;

        int m{0},M{0};
        cin>>m>>M;

        cout<<"\n"<<canReach(s,m,M)<<"\n";     
    }
   

 

}