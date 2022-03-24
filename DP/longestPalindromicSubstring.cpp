#include<bits/stdc++.h>
using namespace std;


//logic is that we try a bottom up dp approach
//we chekc for susbtrig of len 0,then 1 and then 2,
//when the gap between two index is g , it woul depedn on substring of diff g-1


    string longestPalindrome(string s) {
        
        
        bool isPalindrome[1000][1000];//will store if 
        int l = s.length();
        int ans =0;
        int x =0;
        int y =0;
        for(int gap=0 ; gap <= l ; gap++){
            for(int i  = 0 , j = gap; i<l && j<l ; i++,j++){
                
                //one character
                if (gap==0){
                    isPalindrome[i][j] = true;
                    continue;
                }
                
                //two characters
                if(gap == 1 ){
                    isPalindrome[i][j] = (s[i]==s[j]);
                    if(isPalindrome[i][j]){
                       if(gap > ans){
                           ans=gap;
                           x =i;
                           y=j;
                       }
                    }
                    continue;
                }
                
                //when indices are apart , we only check first an last elemnt and if the middle string is palindrome
                //then ours is alo palindrom
                if(s[i]!=s[j]){
                     isPalindrome[i][j] = false;
                }else{
                     isPalindrome[i][j] = isPalindrome[i+1][j-1];
                    if(isPalindrome[i][j]){
                       if(gap > ans){
                           ans=gap;
                           x =i;
                           y=j;
                       }
                    }
                   
                }
                
            }
        }
        
        
        return s.substr(x , ans+1);
        
        
        
    }

    // the above aproach is time - O(n2) and space O(n2), we can improve upon the space 
    //https://www.geeksforgeeks.org/longest-palindromic-substring-set-2/
    //the beleo method is o1 space and On2 time
     string longestPalindrome_constantSpace(string S){
        // code here 
        int ans =1;
        int n = S.length();
        int si_a =0;
        for(int i =0;i<n ;i++){
                
            int si=i-1;
            int ei=i+1;
            while(si>=0 && S[si] == S[i] ){
                si--;
            }
            while(ei<n && S[ei] == S[i] ){
                ei++;
            }
            
            while(si>=0 && ei<n && S[si]==S[ei]){
                si--;ei++;
            }
            
            
            if(ei-si-1>ans){
                ans = ei-si-1;
                si_a = si+1;
            }
            
        }
        
        return S.substr(si_a,ans);
    }