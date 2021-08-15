// https://www.spoj.com/problems/BALIFE/

#include<bits/stdc++.h>
using namespace std;
#define ll long long 


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n =1;
    cin>>n;
    while(n>0){
        
        ll*arr =new ll[n];
        ll*sum = new ll[n];

        ll s = 0  ;
        for(int i  = 0 ;i < n ; i++){
            cin>>arr[i];
            s+=arr[i];
            sum[i] = s;
        }
        ll avg = s/n;
        if(s%n!=0){
            cout<<-1<<"\n";
        }else{

             ll diff = INT_MIN;

            for(int i = 0 ;i < n-1 ; i++){

                ll temp = abs(avg*(i+1)-sum[i]);
                diff = max(diff , temp);

            }
            cout<<diff<<"\n";
        }       
    
        cin>>n;

    }


}

















































