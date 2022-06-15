#include<bits/stdc++.h>
using namespace std;


//https://leetcode.com/problems/longest-string-chain/

//so for a given string of length l , we need to check if any of its substrings with on missig char exitst in the dp map and its value
//and add its value to our ans
  int longestStrChain(vector<string>& words) {
        
        
        vector<vector<string>>arr(17,vector<string>(0));
        unordered_map<string,int>m;
        int minL=INT_MAX;
        for(int i =0;i<words.size();i++){
            int sizeh=words[i].length();
            minL=min(minL,sizeh);
            arr[sizeh].push_back(words[i]);
        }
        
        for(int i =0;i<arr[minL].size();i++){
            m[arr[minL][i]]=1;
        }
        int ans =1;
        
        for(int i=minL+1;i<17;i++){
            
            for(int j = 0;j<arr[i].size();j++){
                int ta=0;
                for(int k=0;k<i;k++){
                
                    string temp=arr[i][j].substr(0,k);
                    if(k+1<i){
                        temp+=arr[i][j].substr(k+1);
                    }
                    if(m.count(temp)){
                        ta=max(ta,m[temp]);
                    }
                }
                m[arr[i][j]] = ta+1;
                ans = max(ans,m[arr[i][j]]);
            }
        }
    
        return ans;
    }