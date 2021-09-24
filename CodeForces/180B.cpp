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

    ll t=0,x=0,y=0,a=0,b=0;
    cin>>t>>x>>y>>a>>b;

    ll disX = a-x;
    ll disY = b-y;
    char NX='E';
    char NY = 'N';
    if(disX < 0){
        NX = 'W';
        disX=-disX;
    }
    if(disY<0){
        NY = 'S';
        disY = -disY;
    }

    string s{""};
    cin>>s;
    ll tt =0;

    while((disX>0 || disY>0) && tt< t){

        if(s[tt] == NX){
            disX--;
        }
        if(s[tt] == NY ){
            disY--;
        }
        tt++;

    }
    if(disX>0 || disY>0){
        cout<<-1<<"\n";
    }else{
        cout<<tt<<"\n";
    }

}

