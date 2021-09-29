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

    string s{""};
    cin>>s;

    int arr[27] = {0};
    char A='a';
    for(int i = 0 ;i<s.length() ; i++){ 
        arr[s[i]-A]++;
    }   
    int even=0;
    int odd=0;
    for(int i =0 ; i<26 ; i++){
        if(arr[i]%2 == 0){
            even++;
        }else{
            odd++;
        }
    }

    string player[2] = {"First" , "Second"};
    int p = 0 ;

    while(odd > 1){
        int maxF_E=0;
        int z =-1;
        int x=-1;
        int maxF_O=0;
        for(int i =0 ; i < 26 ; i++){
            if(arr[i]%2==0){
                if(arr[i] > maxF_E){
                    z=i;
                    maxF_E=arr[i];
                }
            }else{
                if(arr[i] > maxF_O){
                    x=i;
                    maxF_O=arr[i];
                }
            }
        }
        if(maxF_E==0){
            arr[x]--;
            odd--;
            if(arr[x] != 0){
                even++;
            }

        }else{
            arr[z]--;
            if(arr[z] !=0){
                odd++;
            }
            even--;
        }
        p++;
    }
    cout<<player[p%2]<<"\n";


}

