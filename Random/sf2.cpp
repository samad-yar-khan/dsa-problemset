#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T=0;
    cin>>T;
    while(T--){

        string  s = {""};
        cin>>s;

        int freq[26] = {0};
        for(int i = 0 ; i < s.length() ; i++){
            freq[s[i] - 'a'] ++;
        }

        
        for(int i = 0 ; i < s.length() ; i++){
            if(freq[s[i] - 'a'] == 0){
                continue;
            }else{
                cout<<s.at(i)<<freq[s[i] - 'a']<<" ";
                freq[s[i] -'a'] = 0;
            }
        }
        cout<<"\n";

    }
}