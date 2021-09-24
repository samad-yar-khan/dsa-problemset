#include<bits/stdc++.h>
using namespace std;
#define ll long long

//https://www.hackerrank.com/contests/launchpad-1-winter-challenge/challenges/prime-visits


void prime_sieve(int *arr , int n ){

    //makr all as prime except evebn noes 
    //sepecial cases
    arr[0] = 0;
    arr[1] = 2;
    arr[2] = 1;

    for(int i = 3 ; i <=n ; i++ ){
        //odd       
        if(i&1){
            arr[i] = 1;
        }else{
            arr[i] = 0;
        }
    }

    for(int i = 3 ;  i*i <=n ; i++)
    {
        if(arr[i] == 0){//non primes
            continue;
        }
        for(int j = i*i ; j <= n ; j+=i){
            arr[j] = 0;
        }
    }

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r" , stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    //N is 1000000 so we can marks all prime nos in 1 to 10000000 before hand
    int* primes=new int[1000001];
    prime_sieve(primes,1000000);

    //now we vcan maker a precompute array wehere we stor ther numer of prime numos till i
    int* numPrimes = new int [1000001];
    numPrimes[0] = 0 ;
    numPrimes[1]=0;
    int c=0;
    for(int i =2 ;i<=1000000; i++){
        if(primes[i]==1){
            c++;
        }
        numPrimes[i]=c;
    }

    int N=0;
    cin>>N;
    while (N--)
    {
       int p=0,q=0;
       cin>>p>>q;
       cout<<numPrimes[q]-numPrimes[p-1]<<"\n";
    }
    
    

    delete [] primes ;
    delete [] numPrimes;
}

