#include<bits/stdc++.h>
#define ll long long 
using namespace std;


class comparePetrol {

    public:

    bool operator()(pair<int , int > a ,  pair<int , int> b){
        return a.second < b.second ;
    }

};

bool comp(pair<int , int> a , pair<int , int > b){
    return a.first>b.first;
}

int  minStops(pair<int , int>* stops  , int N , int X , int P){

    sort( stops , stops+N , comp );

    // for(int i = 0 ; i < N ; i++){
    //     cout<<stops[i].first<<" "<<stops[i].second<<"\n";
    // }
    priority_queue<pair<int , int > , vector<pair<int , int>> , comparePetrol > pendingStops ;
    int c = 0 ;
    int i = 0 ;
    int distanceLeft = X;
    int petrolLeft = P;
    while (distanceLeft >0)
    {
        if(petrolLeft >= distanceLeft){
            distanceLeft = 0 ;
            break;
        }

        while(i < N && distanceLeft-stops[i].first <= petrolLeft){//un stops ko push karo jaha tum ja pao
            pendingStops.push(stops[i++]);
        }
        if(pendingStops.size() == 0)
        {
            break;
        }

        pair<int , int > chosenStop = pendingStops.top();
        // cout<<chosenStop.first<<" "<<chosenStop.second<<"\n";
        pendingStops.pop();
        int disTraveled = distanceLeft-chosenStop.first;
        petrolLeft=petrolLeft-disTraveled+chosenStop.second;
        distanceLeft  = chosenStop.first;
        c++;
    
    }

    if(distanceLeft > 0){
        return -1;
    }

    return c;    

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll T=0;
    cin>>T;

    while(T--){

        int N = 0;
        cin>>N;

        pair<int,int>*stops = new pair<int,int> [N];

        for(int i = 0 ; i  < N ; i++){
            cin>>stops[i].first;
            cin>>stops[i].second;
        }

        int X = 0 ;
        cin>>X;
        int P = 0 ;
        cin>>P;

        cout<<minStops(stops , N , X , P)<<'\n';

        delete [] stops;
    }
    return 0;
}