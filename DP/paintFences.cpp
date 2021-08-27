#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007

long long countWays(int n, int k){
    
    //edge case 
    if(n==1){
        return k;
    }

    if(n==2){
        long long same = k ;
        long long diff = (k*(k-1))%mod;

        return (same+diff)%mod;
    }

    //for 2 fences
    long long same = k; //ways to face 2 fences of last two are smae
    long long diff = (k*(k-1))%mod; //ways to face 2 fence if last two are diff
    long long total = (same + diff)%mod;

    for(int i = 3 ; i <= n ; i++){
        long long same_i = diff;//jus take the ways to ppaint i-1 fences if last two are  same and add same color to end , only 1 way 
        long long diff_i = (total*(k-1))%mod;//take all the ways to ppaint the fence and put a diff color at the end of each
        same = same_i;
        diff = diff_i;
        total = (same + diff)%mod;
    }
    return total;
}