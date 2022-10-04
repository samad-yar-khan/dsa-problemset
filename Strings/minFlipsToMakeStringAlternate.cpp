#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/submissions/
 int minFlips(string s) {
        //n=length of s;
        //to show the shifting of n digits to the fornt we can just use a string S
        //which is s+s, S=s+s
        //now if we take windows of size n in S, and find min bits flipped we can check for all cases
        //where some prefix is appended to the end of th string
        //now, we can take cases, where the bit parity is same as (index%2) or its the opposite
        //when we slide the widnow, we forts check if the first bit, had any contribution to a or b
        //by comparing parity with mod 2 of index, and subtarct the effect
        //then we extned the window and see the effect of the last added element on a and b
        string S= s+s;
        int i =0;
        int j =0;
        int a =0;
        int b =0;
        int n = s.length();
        int ans =INT_MAX;
        while(j<n){
            //follows parity
            if(S[j]-'0' != j%2){
                a++;
            }
            //reverse parity bits
            if(S[j]-'0' == j%2){
                b++;
            }
            j++;
        }
        j--;
        ans = min(a,b);

        while(i<n){
            if(s[i]-'0' != i%2){
                a--;
            }
            if(s[i]-'0' == i%2){
                b--;
            }
            i++;

            j++;
            if(j>=2*n){
                break;
            }
             if(S[j]-'0' != j%2){
                a++;
            }
            //reverse parity bits
            if(S[j]-'0' == j%2){
                b++;
            }

            ans = min(ans,min(a,b));
        }
       return ans;
    }