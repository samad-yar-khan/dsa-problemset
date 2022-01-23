#include <bits/stdc++.h>
#define ll long long
#define modVal 1000000007

using namespace std;


ll exp(ll m , ll n){    //m^n


    ll number = m ;
    ll power = n ;
    ll answer = 1;

    

    while( power > 0){
        if((power & 1 ) > 0){
            answer *= number ;
            answer%=modVal;
        } 
        //square the number 
        number*=number;
        number%=modVal;
        //right shift power
        power = power>>1;
    }
    return answer;
}

int main(){

    ll T{0};
    cin>>T;

    while(T--){
        

        string add{"add"};
        string find{"find"};
        int p=0;cin>>p;
        unordered_map<string ,int>m;
        int ans =0;
        for(int i=0;i<p;i++){
            string a;cin>>a; 
            string b;cin>>b;
            if(a==add){
                for(int j =1;j<=b.length() ;j++){
                    m[b.substr(0,j)]++;
                }
            }else{
                if(m.count(b) ==0){
                    cout<<0<<"\n";
                }else{
                    cout<<m[b]<<'\n';
                }
            }
        }
        

    }
   


}

/*
1
5
add demure 
find d
add diligent
add enmity
find enm


*/