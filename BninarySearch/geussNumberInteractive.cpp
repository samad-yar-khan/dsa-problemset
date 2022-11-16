#include<bits/stdc++.h>
using namespace std;


//https://leetcode.com/problems/guess-number-higher-or-lower/
int geuss(int);

int guessNumber(int n) {
        long long l = 1;
        long long h = n;
        int ans =-1;
        while(l<=h){
            long long g = (1LL*l+h)/2;
            int res = guess(g);
            if(res==0){
                ans = g;break;
            }
            if(res == 1){
                l = g+1;
            }else{
                h= g-1;
            }
        }
        return ans;
    }