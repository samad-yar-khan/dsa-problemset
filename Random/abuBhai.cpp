#include<iostream>
using namespace std;

int solve(int *arr , pair<int , int>* Qys , int n , int Q){
    
    pair<int , int> dp[1000000];
    pair<int , int > a(0,1);
    dp[0] = a;
    int i = 0 ; int j= 1 ;
    while ( j< n && i< n){
        if(arr[j] > arr[j-1]){
            pair<int , int> a(i , j-i+1);
            dp[j] = a;
            j++;
        }else{
             pair<int , int > a(j,1);
             dp[j] = a;
             i = j ;
             j++;
        }
    }

    for(int i = 0 ; i < Q ; i++){
        int l = Qys[i].first;
        int r = Qys[i].second;

        if(dp[l].first == dp[r].first){
            cout<<r-l+1<<'\n';
        }else{
            int k = l;
            int ans=0;
            while(dp[k].first == l){
                ans++;
                k++;
            }
            while(k<=r){
                ans=max(ans , dp[k].second);
            }
            cout<<ans<<"\n";
        }

    } 

}

