#include<bits/stdc++.h>
using namespace std;


// https://leetcode.com/problems/maximum-product-of-word-lengths/

// convert strings to 24 bit digits

 int maxProduct(vector<string>& words) {
        int n = words.size();
       vector<int>nums(n,0);
        for(int i  =0;i<n;i++){
            for(int j =0;j<words[i].length();j++){
                nums[i] = (nums[i] | (1<<(words[i][j]-'a')));
            }
        }
        int ans =0;
        for(int i =0;i<n;i++){
            for(int j =i+1;j<n ;j++){
                if((nums[i]&nums[j]) == 0){
                    int mul = words[i].length()*words[j].length();
                    ans = max(ans,mul);
                }
            }
        }
        return ans;
        
    }