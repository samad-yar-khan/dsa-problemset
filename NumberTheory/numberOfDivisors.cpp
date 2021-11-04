#include<bits/stdc++.h>
using namespace std;


void countDivisors(int N){

    //wenuse the same logic as finding factors
    //we find all factors of a number 
    //then we us ethe pnc
    /*
        36 = 2^2 * 3^2 
        so we can choose 02s , 1-2s , 2-2s, and 0-3s,1-3s,2-3s
        so ans = 9

    */  

   int i = 2;

   int totalDivisors = 1 ;

   for( ; i < sqrt(N) ; i++ ){
       if(N%i==0){
           int count =0;
           while(N%i == 0){
               count++;
               N/=i;
           }
           totalDivisors*=(count+1);
       } 
   }


    if(i!=1){
        totalDivisors*=2;//because this means that even that out number is a prime itself
        //hence we add its power aswell
    }

    cout<<totalDivisors<<"\n";

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

  

    int T = 0;
    cin>>T;
    while(T--){

        int N =0;
        cin>>N;

        countDivisors(N);

    }
    
  
}

