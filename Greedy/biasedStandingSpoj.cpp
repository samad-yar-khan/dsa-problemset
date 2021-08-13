#include<bits/stdc++.h>
using namespace std;
#define ll long long int

// we just sort and calc dstances andd sem it um
//better soln for on time would br to use counting sort and maitain freq of each number and then keep a counte r aput vals
int main(){

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    ll T = 0;
    cin>>T;
    while(T--){

        ll n =0;
        cin>>n;
        ll*arr= new ll[n];

        for(ll i = 0;i < n ; i++){
            string s{""};
            cin>>s;
            cin>>arr[i];
        }

        sort(arr,arr+n);//by sortig we put them closest t theri posistion and now
        //we just need the min
        ll ans = 0 ;

        for(ll i = 0  ; i<n ; i++){
            ans+=abs(arr[i]-(i+1));
        }

        cout<<ans<<"\n";
        delete []arr;
    }

}


