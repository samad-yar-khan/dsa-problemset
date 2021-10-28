#include<bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/longest-substring-without-repeating-characters/submissions/
  int lengthOfLongestSubstring(string s) {
        vector<int> freq(257,-1);
        
        int i =0;
        int n =s.length();
        int j =0;
        int LenMax = 0;
        
        while(i<n && j<n){
            // cout<<j-i<<" ";
        
            int index=s[j]-' ';//characrte index
            // cout<<index<<" ";
            
            if(freq[index] == -1){
                
                freq[index] = j ;
                j++;
                
            }else{
                
                LenMax = max(j-i,LenMax);
                int n_ = freq[index];
                while(i <= n_ ){
                    int index_ = s[i]-' ';
                    freq[index_] = -1;
                    i++; 
                }
                freq[index] = j;
                j++;      
            }
          
        }
          LenMax = max(j-i,LenMax);
        return LenMax;
    }