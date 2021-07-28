#include<iostream>
#include<vector>
using namespace std;

 vector<int> factorial(int N){
        // code here
        vector<int> fact;
        fact.push_back(1);
        for(int i = 1 ; i <= N ; i++){
            
            long long carry = 0;
             int number = i;
            
            for(long long j = 0 ; j < fact.size() ; j++){
                
                int newNum = (number*fact[j]) + carry;
                carry = newNum/10;
                fact[j] = newNum%10;
                
            } 
        
            while(carry!=0){
                fact.push_back(carry%10);
                carry/=10;
            }
            
        }
        
        long long i = 0 , j = fact.size() -1 ;
        while(i < j){
            swap(fact.at(i) , fact.at(j));
            i++;j--;
        }
        
        return fact;
        
    }
    int main(){
        vector<int> f= factorial(100);
        for(int i = 0 ; i < f.size() ; i++){
            cout<<f[i];
        }
    }