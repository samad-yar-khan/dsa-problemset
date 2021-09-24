#include<bits/stdc++.h>
using namespace std;

//for a single number
bool isPrime(int n){

    if(n<=1){
        return false;
    }
    if(n==2){
        return true;
    }

    for(int i = 2 ; i*i < n ; i++){
        if(n%i == 0){
            return false;
        }
    }

    return true;

}

//desigining the prime seive for a rannge

//for prime sieve our concept lies in marking multiples og primes
//we start from2 and mark all multiple of 2 as npon prime
//we start from 3 and mark all muliple of 3 an non prime
//similoairty we iterarte from 2,n and everytime we visitr a numbrer marked as prime , we set al; it multiples  to non prime
//some optimisayion 
//-> if we come across a non prime , just skip
//-> we can matrks all even nos as non prime befor hand
//when we start marking for all multiple of a prime number pi , we should consider markeing only those who come after pi^2 because the smallewr multiple will already be marked by smaller primes 
//ex at 5 , we may try to mark , 10 , 15 , 20 ,25
//but 10 would have been mmaked by 2 , 15 by 3 , 20 by 4 , hence we should start fro m 25 
//the overall complexuty of prie sive is O(nlog(log(n)))

void prime_seive(int *arr , int n){

    //0 means non preime and 1 means prime
    //set all to prime except  even nos and on3
    arr[0] = 0;
    arr[1] = 0;
    arr[2] = 1;
    for(int i =3 ; i<=n ; i+=1){
        if(i%2==0){
            arr[i] = 0;
        }else{
            arr[i] = 1;
        }
    }

    //now we mark mulriples 
    //bit onlu marks mulriple  of peimes and starting from theri squares
    //2 ke multiples even hia , wo already marks hogye
    for(int i = 3 ; i<= n ; i++){
        if(arr[i] == 0){
            continue;
        }
        for(int j = i*i ; j <= n ; j+=i){
            arr[j] = 0;
        }

    }

    return;

}


int main(){

    int n = 0;
    cin>>n;
    int *arr = new int [n+1];
    
    prime_seive(arr , n);
    for(int i =1;i<=n ;i++){
        if(arr[i]){
            cout<<i<<"\n";
        }
    }

    delete [] arr;

}
