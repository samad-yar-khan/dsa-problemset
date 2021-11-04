#include<bits/stdc++.h>
using namespace std;

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
    
    long long int largestPrimeFactor(int N){
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