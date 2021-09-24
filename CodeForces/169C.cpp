#include<bits/stdc++.h>
using namespace std;
#define ll long long 
const ll modVals = 10e9 + 7;


//the logic negine it was that , till we have more than one odd we cant have  apalindrom
//if we have evns , we make the remove the max frreq evenm chat
//else male the max freq odd char even

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
     #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r" , stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    int n =0 , q=0;
    cin>>n>>q;

    vector<ll> arr;
    for(int i =0;i < n ; i++){
        ll e=0;
        cin>>e;
        arr.push_back(e);
    }   
    pair<ll ,ll> init_p(0,0);
    vector<pair<ll , ll>> targets(n,init_p);

    for(int i =0;i< q; i++){
        int l=0,r=0;
        cin>>l>>r;
        l--;r--;
        targets[l].first++;
        targets[r].second--;
    }
    ll  c =0;
    vector<ll> hits(n,0);
   
    for(int i =0;i<n ;i++){
        c= (c  + targets[i].first ) ;
        hits[i]=c ;
        // indices.push({hits[i],i});
        c+=targets[i].second;
    }
    sort(hits.begin(),hits.end() , greater<ll>());
    sort(arr.begin() ,arr.end() , greater<ll>());
    ll maxSum =0;
    int i=0;
    while(i<targets.size()){
        maxSum = (maxSum  + (hits[i]*1ll*arr[i]) ) ;
        i++;
    }
    cout<<maxSum<<"\n";

}