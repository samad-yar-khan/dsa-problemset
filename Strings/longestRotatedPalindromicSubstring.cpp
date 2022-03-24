#include<bits/stdc++.h>
using namespace std;

//https://binarysearch.com/problems/Longest-Rotated-Palindromic-Substring

//whenever we are given the question of rotated arrays/string with substring ,  we can take twice of the array/string (Ex S+=S  and use our original logic of S on windows of size S )

int solve(string s) {
    string S=s;
    S+=S;
    int i =0;
    int n = S.length();
    int ans =0;
    while(i<n){
        int si=i-1,ei=i+1;
        while(si>=0 && S[i] == S[si]){
            si--;
        }
        while(ei<n && S[i] == S[ei] ){
            ei++;
        }

        while(si>=0 && ei < n && S[si] == S[ei] && ei-si+1<=n/2 )
        {
            si--;
            ei++;
        }
        if(ans < ei-si-1){
            cout<<ei<<" "<<si<<" ";
            ans = min(n/2, ei-si-1);
        }
     
        i++;
    }
    return ans;
}