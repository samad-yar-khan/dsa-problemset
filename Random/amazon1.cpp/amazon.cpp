#include<bits/stdc++.h>
#define ll long long
using namespace std;


ll NcR(int n, int r)
{
 
  
    long long p = 1, k = 1;
 
   
    if (n - r < r){
        r = n - r;
    }
        
 
    if (r != 0) {
        while (r) {
            p *= n;
            k *= r;
 
            long long m = __gcd(p, k);

            p /= m;
            k /= m;
            n--;
            r--;
        }
 
       
    }
    else{
         p = 1;
    }
       

    return p;
}

ll solve(int*arr, int  n , int k , int m , int M){

    int v = 0;
    for(int i = 0 ;i<n ;i++){
        if(arr[i]<=M && arr[i]>=m){
           v++;
        }
    }

    ll ans = 0 ;
    if(k > v){
        return ans;
    }
    for(int i = k ; i <= v; i++){
        ans = ans + NcR(v , i);
    }
    return ans;

}

int main(){

    

    int T = 0 ; 
    cin>>T;
    while(T--){

        int N = 0 ;
        int arr[20] = {0};
        cin>>N;
        for(int i =0; i< N ; i++){
            cin>>arr[i];
        }

        int k = 0 ;
        cin>>k;
        int minLevel = 0 ;
        int maxLevel = 0 ;
        cin>>minLevel;
        cin>>maxLevel;
        
        ll ans = solve(arr , N , k , minLevel , maxLevel);
        cout<<ans<<"\n";
       

    }

}