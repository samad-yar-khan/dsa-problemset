#include<bits/stdc++.h>
using namespace std;


//https://practice.geeksforgeeks.org/problems/count-numbers-in-range5305/1#
//so we need to calc the  number with e3 divisors
//the numvber with 3 drives are those number which are the squares of prime numebrs
// so we make a seive and we calculate the number of number in L to R which are the perfect squares of primes factors in our primes array


 void getPrimes(vector<bool>& seive , vector<int>& primes){
            
        seive[0]=false;
        seive[1] = false;
        for(long long i = 2 ;i <= 100000 ;i++){
            if(seive[i]){
                primes.push_back(i);
                for(long long j=i*i ; j <=100000 ; j+=i){
                    seive[j] = false;
                }
            }
        }
        
    }
    
    int count3DivNums(long long L, long long R) {
        // code here
        vector<bool> seive(100001,true);
        vector<int> primes;
        long long sp = sqrt(L);
        getPrimes(seive , primes);
        int ind = lower_bound(primes.begin() , primes.end() , sp) - primes.begin();
        int ans =0;
        for(long long i = ind ; i < primes.size()  && primes[i]*primes[i] <= R ; i++){
            if(primes[i]*primes[i]<=R && primes[i]*primes[i] >= L){
                ans ++;
            }
        }
        return ans;
        

    }