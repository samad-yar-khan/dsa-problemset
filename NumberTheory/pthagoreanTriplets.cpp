#include<bits/stdc++.h>
#define ll long long
using namespace std;


//https://www.youtube.com/watch?v=z0swLlWk9is&ab_channel=Pepcoding
//https://codeforces.com/problemset/problem/707/C


void pythaogoreanTrip(ll n){

    if(n<=2){
        cout<<-1<<"\n";
        return;
    }

    if(n%2){    
        ll a = (n*n)/2;
        ll b = (n*n)/2 + 1;
        if( a*a + n*n == b*b){
            cout<<a<<" "<<b<<"\n";
        }else{
            cout<<-1<<"\n";
        }
    }else{
        ll a = (n*n)/4 -1 ;
        ll b = (n*n)/4 + 1;
        if( a*a + n*n == b*b){
            cout<<a<<" "<<b<<"\n";
        }else{
            cout<<-1<<"\n";
        }
    }
    return;

}

int main(){

    ll n =0;
    cin>>n;
    
    pythaogoreanTrip(n);

}