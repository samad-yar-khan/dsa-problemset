#include<bits/stdc++.h>
using namespace std;


//https://leetcode.com/problems/count-binary-substrings/submissions/

//the question is that we need to cal the total number subtrings with equal number of  conseq zeros and ones 
//so what we can do is that we can calc total numbe of conseq zeros, then ones , then we can take the min of that nuimebr 
//ex we have 
//11001100
//we get something like
//2,2,2,2
//min of(2,2) + min(2,2)+min(2,2)
//ex
//1001000111
//we get
//1 2 1 3 3
//ans = min(1,2) + min(2,1) + min(1,3) + min(3,3)'

int countBinarySubstrings(string s) {
        
        int val1=-1;
        int val2=-1;
        
        int i =0;
        int ans =0;
        int n = s.length();
        while(i < n){
            int j = i;
            char key = s[i];
            int f=0;
            while(j < n && s[j]==key){
                f++;
                j++;
            }
            val2 = f;
            if(val1!=-1){
                ans+=min(val1,val2);
            }
            val1=val2;
            i=j;
        }
    
        return ans;
        
    }