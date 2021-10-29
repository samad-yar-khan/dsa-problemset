#include<bits/stdc++.h>
using namespace std;
#define ll long long int
//if we have to checka prime number is more than 10^7 and less than 10^14
//now we need tio 
bool isPrime(ll n , int *arr , vector<int>&primes){
    
    if( n <= 100000){
        return arr[n];
    }

    for(int i = 0 ; primes[i]*(long long int)primes[i] < n ;i++){
        if(n%primes[i] == 0){
            return false;
        }
    }
    return true;

}

void prime_seive(int * arr, vector<int>&primes ){

    //0 means non preime and 1 means prime
    //set all to prime except  even nos and on3
    arr[0] = 0;
    arr[1] = 0;
    arr[2] = 1;
    for(int i =3 ; i<=10000; i+=1){
        if(i%2==0){
            arr[i] = 0;
        }else{
            arr[i] = 1;
        }
    }

   
    primes.push_back(2);
    //now we mark mulriples 
    //bit onlu marks mulriple  of peimes and starting from theri squares
    //2 ke multiples even hia , wo already marks hogye
    
    for(int i = 3 ; i<= 100000 ; i++){
        if(arr[i] == 0){
            continue;
        }
        primes.push_back(i);
        for(int j = i*i ; j <= 100000 ; j+=i){
            arr[j] = 0;
        }

    }

    return;

}


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    // #ifndef ONLINE_JUDGE
    //     freopen("../input.txt", "r" , stdin);
    //     freopen("../output.txt", "w", stdout);
    // #endif

    ll n=0;
    cin>>n;

    int arr[100000];
   
   vector<int> primes;
    prime_seive(arr,primes);
    cout<<isPrime(n,arr,primes)<<"\n";

   
    return 0;
}