#include<bits/stdc++.h>
using namespace  std;

int main(){

    unordered_map<char,pair<double,double>>mp;
    mp['A'] = make_pair(100,80);
    mp['B'] = make_pair(79,60);
    mp['C'] = make_pair(59,45);
    mp['D'] = make_pair(44,33);
    mp['E'] = make_pair(32,0);

    double T=0;cin>>T;
    for(int i =0;i<5;i++){
        cout<<char('A'+ i)<<" : ";
        cout<<(mp['A'+i].first*T)/100<<" - "<<(mp['A'+i].second*T)/100<<"\n";
    }


}