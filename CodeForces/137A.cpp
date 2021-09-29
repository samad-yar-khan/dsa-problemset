#include<bits/stdc++.h>
using namespace std;
#define ll long long int
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

    ll n =0,k=0;
    cin>>n>>k;

    if(n==1){
        cout<<0<<'\n';
        return 0;
    }
    vector<int> arr;
    for(int i =0;i<n;i++){
        int a=0;cin>>a;
        arr.push_back(a);
    }
    int kth = arr[k-1];
    for(int i=k; i<n ; i++){
        if(arr[i]!=kth){
            cout<<-1<<"\n";
            return 0;
        }
    }
    int j =k-1;
    while(j>=0 && arr[j]==kth){
        j--;
    }
    j++;
    cout<<(j)<<"\n";

    return 0;

}