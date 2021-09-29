#include<bits/stdc++.h>
using namespace std;
#define ll long long int
//if we have to checka prime number is more than 10^7 and less than 10^14
//now we need tio 
bool isPrime(ll n , int *arr ){
    cout<<n<<"\n";
    if(n<=1){
        return false;
    }
    if(n==2){
        return true;
    }
    
    if(n < 1000001){
        return arr[n];
    }

    for(int i = 2 ; i*i < n ; i++){
        if(n%i == 0){
            return false;
        }
    }

    return true;

}

void prime_seive(int *arr ){

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

    //now we mark mulriples 
    //bit onlu marks mulriple  of peimes and starting from theri squares
    //2 ke multiples even hia , wo already marks hogye
    for(int i = 3 ; i<= 100000 ; i++){
        if(arr[i] == 0){
            continue;
        }
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
    // prime_seive(arr);
   
    cout<<isPrime(n,arr)<<"\n";

   
    return 0;
}