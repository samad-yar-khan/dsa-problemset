#include<bits/stdc++.h>
using namespace std;


bool solve(string S){

    vector<int> f(26,0);

    for(int i = 0 ;i < S.length() ; i++){

        int ind = S[i] - 'a';
        f[ind]+=1;
      
    }
    // for(auto x:f){
    //     cout<<x<<" ";
    // }
    // cout<<"\n";
    int i = 0;
    while(i<26 && f[i]==0){
        i++;
    }
    
    int j = i+1;
    while(i< 26 && j < 26){

        j = i+1;
        while(j<26 && f[j] == 0){
            j++;
        }
        if(j<26 && f[j]>f[i]){
            return false;
        }
        i=j;
    }
    return true;


}

int main(){

    int T=0;cin>>T;
    while(T--){
        string S;cin>>S;
        cout<<boolalpha;
        cout<<solve(S)<<"\n";
    }

}