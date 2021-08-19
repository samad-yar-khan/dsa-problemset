#include<bits/stdc++.h>
#define ll long long 
using namespace std;

int minStops(pair<int , int>* stops , int L , int  P , int N){

    //bc
    if(L<=P){
        return 0;
    }
    if(N<=0){
        return INT_MAX;
    }
    if(P<0){
        return INT_MAX;
    }

    //check if we can  even reach the next stop or not
    int distanceToNearest = L-stops[0].first;
    if(P<distanceToNearest){
        return INT_MAX;
    }

    int case1 = INT_MAX;
    int case2 = INT_MAX;
    
    ///reach stop and refill next stop
    case1=minStops(stops+1 , stops[0].first , P + stops[0].second - distanceToNearest, N-1 ) +1;
    //dont stop and refill ar nettx tsop
    case2 = minStops(stops+1 , stops[0].first , P -distanceToNearest, N-1 );

    return min(case1 , case2);

}

bool comp(pair<int , int> a , pair<int , int> b){
    return a.first>b.first;
}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll T=0;
    cin>>T;

    while(T--){

        int N = 0 ;
        cin>>N;
        pair<int,int>*stops =  new pair<int ,int>[N];
        for(int i = 0 ; i < N ; i++){

            int distanceFromTown = 0 ;;
            int fuel=0;
            cin>>distanceFromTown>>fuel;

            pair<int , int> stop(distanceFromTown , fuel);
            stops[i] = stop;
        }


        int L=0;
        int P=0;
        cin>>L>>P;

        sort(stops , stops+N , comp);
        cout<<minStops(stops , L , P , N);
        
        delete [] stops;
    }
    return 0;
}