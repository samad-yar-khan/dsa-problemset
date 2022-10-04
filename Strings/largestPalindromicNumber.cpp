#include<bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/largest-palindromic-number/
 string largestPalindromic(string num) {
        vector<int>f(10,0);
        bool oz =1;
        for(int i=0;i<num.length();i++){
            f[num[i] - '0']++;
            if(num[i]!='0'){
                oz=0;
            }
        }
        if(oz){
            return "0";
        }
        oz=1;
        string ans="";
        for(int i =9;i>=0;i--){
            if(f[i]/2 > 0){
                if(i!=0){
                    oz=0;
                }
                string k (f[i]/2, '0'+i);
                f[i] -= (2*(f[i]/2));
                ans+=k;
            }
        }
        bool oddA=false;
        int dig=0;
        int fr=INT_MIN;
        for(int i=9;i>=0;i--){
            if(f[i] >0 ){
                dig=i;
                oddA=true;
                break;
                
            }
        }
        if(oz){
             string o(1,'0' + dig);
            return o;
        }
        
        if(oddA)
        {
            string o(1,'0' + dig);
            string suff(ans);
            reverse(suff.begin(),suff.end());
            ans=ans+o+suff;
        }else{
            string suff(ans);
            reverse(suff.begin(),suff.end());
            ans+=suff;
        }
        return ans;
    }