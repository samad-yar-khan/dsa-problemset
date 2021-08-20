#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll T=0;
    cin>>T;
    while(T--){

        int m = 0 ;
        int n = 0;
        int numPoints = 0 ;
        cin>>m>>n>>numPoints;
        pair<int , int>*points = new pair<int , int>[numPoints];
        for(int i = 0 ; i < numPoints ; i++){
            int  a=0;
            int b =0;
            cin>>a>>b;
            pair <int, int>point(a,b);
            points[i] = point;
        }
        
        

    }

}

