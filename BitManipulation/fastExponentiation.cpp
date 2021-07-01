#include <iostream>
#define ll long long
#define modVal 1000000007
using namespace std;


ll exp(ll m , ll n){    //m^n

    ll number = m ;
    ll power = n ;
    ll answer = 1;

    while( power > 0){
        if((power & 1 ) > 0){
            answer *= number ;
            answer%=modVal;
        } 
        //square the number 
        number*=number;
        number%=modVal;
        //right shift power
        power = power>>1;
    }
    return answer;
}

int main(){

    ll T{0};
    cin>>T;

    while(T--){
        ll m = 0 , n = 0 ;
        cin>>m>>n;
        cout<<exp(m,n)<<"\n";
    }
   


}
