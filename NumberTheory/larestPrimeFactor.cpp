#include<bits/stdc++.h>
using namespace std;

//this is used when we just have to handle  just one numbewr
long long int largestPrimeFactor(int N){
        // code here
        //we will just decremnent N and we wil only iteare till i > root(N)
        int i = 2 ;
        for( ;i <= sqrt(N) ; i++){
            while(N%i == 0){
                N/=i;
            }
        }
        return N==1 ? i-1 : N; 
        
    }


//this below mwethod is used when we have a nmber of queruie
// https://practice.geeksforgeeks.org/problems/largest-prime-factor2601/1
   void makeSeive(vector<bool>&seive , vector<int>& primes , int N){
            
        seive[0] = 0;
        seive[1] = 0;
        
        for(int i =2 ; i <= N ; i++){
            if(seive[i] == true){
                primes.push_back(i);
                for(int j = i*i ; j<=N ; j+=i){
                    seive[j] = false;
                }
            }
        }
        
    }
    
    long long int largestPrimeFactor_2(int N){
        // code here
        vector<bool> seive(N+1,true);
        vector<int> primes;
        makeSeive(seive , primes , N);
        long long int pfN = 1;
     
        for(int i = 0;i<primes.size() ;i++){
            if(N%primes[i] == 0){
                pfN = primes[i];
            }
        }
        
        if(pfN==1){
            pfN = N;
        }
        return pfN;
        
    }