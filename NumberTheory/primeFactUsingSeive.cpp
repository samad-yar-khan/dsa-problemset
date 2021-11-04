#include<bits/stdc++.h>
using namespace std;

void getPrimeFactors(int N , vector<int>& primes){

    vector<int> factors;

    for(int i = 0 ; i< primes.size() && N>1;i++){
        while(N%primes[i] == 0){
            factors.push_back(primes[i]);
            N/=primes[i];
        }
    }
    cout<<"{ ";
    for(int i = 0 ;i < factors.size() ; i++){
        cout<<factors[i]<<" ";
    }
    cout<<"} ";
    cout<<"\n";

}

void makeSeive(vector<bool>& seive, vector<int>& primes){

    seive[0] = false;
    seive[1] = false;

    for(long long i = 2 ; i < 100000 ; i++)
    {
        if(seive[i]){
            primes.push_back(i);
            for(long long j = i*i ; j <= 100000 ; j+=i){
                seive[j] = false;
            }
        }
    }
 
}

//comlexity of building sieve = nloglogn;
//complexity of calculationg factors of each eleemnet n is log(n)
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r" , stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    vector<bool> seive(100001, true);
    vector<int> primes;

    makeSeive(seive,primes);

    int T = 0;
    cin>>T;
    while(T--){

        int N =0;
        cin>>N;

        getPrimeFactors(N,primes);

    }
    
  
}

