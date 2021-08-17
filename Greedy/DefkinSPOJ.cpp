#include<bits/stdc++.h>
#define ll long long
using namespace std;
//https://www.spoj.com/problems/DEFKIN/
/*
    while solving the problem we must keep in mind that 
    area = delX * delY

    here delX xan be all undefended strips of x 
    here delY can be all undefended strips of y
    whenr we see the pic an delX and delYs we see that
    any delX can be combined with any delY to get the area of an undefended region
    now this can be maximised  by taking the max of delX and delY and multiply them to get a product
    

*/


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll T=0;
    cin>>T;
    while(T--){

        ll n = 0 , m =0 , p =0;
        cin>>n>>m>>p;

        int*x = new int [p+2];
        int*y = new int [p+2];
        x[0] = 0;
        y[0] = 0;
        for(int i = 1 ;i <= p ; i++){
            cin>>x[i];
            cin>>y[i];
        } 
        x[p+1] = n+1;
        y[p+1] = m+1;

        int delX = INT_MIN;
        int delY = INT_MIN;
        sort(x,x+p+2);
        sort(y,y+p+2);

        for(int i = 0 ; i <=p ; i++){
            delX = max(x[i+1]-x[i] -1  , delX);
            delY = max(delY , y[i+1] -y[i] -1);
        }

        ll ans = delX*delY;
        cout<<ans<<"\n";
        
    }

}

