#include<bits/stdc++.h>
#define ll long long
using namespace std;

//making the prime seive
void seive(int arr[] , int range , vector<int>& primes ){

    arr[0] = 0 ;//np
    arr[1] = 0 ;//np
    arr[2] = 1 ;//pr

    for(int i=2 ; i <= range ; i++){
        if(arr[i] == 1){
            primes.push_back(i);
            for(int j = 2*i ; j <= range ; j+=i){
                arr[j]=0;
            }
        }
    }
}

void getPrimesInRange(ll n , ll m , vector<int>& primes){

    

}

int main(){
  
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r" , stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    int T =0;
    cin>>T;
    
    int primeSieve[100001] = {1};
    vector<int> primes;

    seive(primeSieve , 100000 , primes);

    while(T--){
        
        ll n=0,m=0;
        cin>>n>>m;  
        getPrimesInRange(n , m ,  primes);

    }

}