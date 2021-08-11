#include<bits/stdc++.h>
using namespace std;
#define ll long long


int main(){

    int n = 0 ;
    cin>>n;
    if(n <=2){
        cout<<n<<"\n";
        return 0;
    }

    int leftOver = INT_MIN;
    int ans = 0 ;
    for(int a = 2 ; a < n ; a++){
        if(n%a>leftOver){
            leftOver=n%a;
            ans = a;
        }
    }
    cout<<ans<<"\n";
}