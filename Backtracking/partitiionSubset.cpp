#include<iostream>
#include<string>
#include<vector>
using namespace std;

int helper(int s1 , int s2 , int n , int *arr , int i ){

    //base case
    if(i ==n){
        if(s1==s2){
            return 1;
        }else{
            return 0;
        }
    }

    //is
    
    int try1 = helper(s1 + arr[i]  , s2 , n , arr , i+1);
    if(try1 == 1){
        return 1;
    }

    int try2 = helper(s1 , s2+arr[i] , n , arr , i+1 );
    return try2;

}
