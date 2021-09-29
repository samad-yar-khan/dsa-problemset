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

    int n =0;
    cin>>n;
    string s{""};
    cin>>s;
    bool hasL=false;
    bool hasR=false;


    for(int i = 0; i< n ; i++){
        if(s[i] == 'L'){
            hasL=true;
        }else if(s[i] == 'R'){
            hasR=true;
        }
    }
    
    if(hasL && hasR){
        bool ml=false,mr=false;
        int l =0,r=0;
        for(int i =0;i<n ; i++){
            if(!ml && s[i] == 'R'){
                l=i;
                ml=true;
            }
            if(!mr && s[i] == 'L'){
                r=i;mr=true;
            }
        }   
        cout<<l+1<<" "<<r<<"\n";
    }else if(hasR && !hasL){
          int l =0,r=0;
        bool ml=false,mr=false;
            for(int i =0;i<n ; i++){
            if(!ml && s[i] == 'R'){
                l=i;
                ml=true;
            }
            if(s[i] == 'R'){
                r=i;mr=true;
            }
            
        }   
        cout<<l+1<<" "<<r+2<<"\n";
    }else if(!hasR and hasL ){
        int l =0,r=0;
        bool ml=false,mr=false;
            for(int i =n-1;i>=0; i--){
            if(!ml && s[i] == 'L'){
                l=i;
                ml=true;
            }
            if(s[i] == 'L'){
                r=i;mr=true;
            }
          
        } 
          cout<<l+1<<" "<<r<<"\n";  
    }

}

