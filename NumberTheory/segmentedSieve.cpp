#include<bits/stdc++.h>
#define ll long long
using namespace std;
//https://www.spoj.com/problems/PRIME1/
//making the prime seive
void makeSeive(vector<bool>&seive , int range , vector<int>& primes ){

    seive[0] = 0 ;//np
    seive[1] = 0 ;//np
    seive[2] = 1 ;//pr

    for(long long i=2 ; i <= range ; i++){
        if(seive[i]){
            primes.push_back(i);
            for(long long j = i*i ; j <= range ; j+=i){
                seive.at(j)=false;
            }
        }
    }
}

void getPrimesInRange(ll n , ll m , vector<int>& primes){

    vector<bool> vec(m-n+1 , true);

    for(long long i = 0 ; i < primes.size() ; i++){
       
        if(primes[i]*primes[i] > m ){
            break;
        }

        long long start = (n/primes[i])*primes[i];

        if( n<=primes[i] && primes[i]<=m ){
            start = 2*primes[i];
        }

        for(long long j  = start ; j <= m ; j+=primes[i] ){
           if(j-n<0){
               continue;
           }
            vec.at(j-n) = false;

        }

        if(n == 1){
            vec[0] = false;
        }

    }
    for(int i =0;i<vec.size() ; i++){
        if(vec[i]){
            cout<<i+n<<"\n";
        }
    }
    cout<<"\n";

}

int main(){
  
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r" , stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    vector<bool >seive(100001, true);    
    vector<int> primes;
    makeSeive(seive , 100000, primes);

    // for(int i =0 ;i < primes.size() ; i++){
    //     cout<<primes[i]<<"\n";
    // }
    int T = 0;cin>>T;

    while(T--){

        ll n = 0 , m = 0;
        cin>>n>>m;

        getPrimesInRange(n,m,primes);

    }
  

}