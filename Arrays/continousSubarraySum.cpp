#include<bits/stdc++.h>
using namespace std;

    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long>presum(n,0);
        //agar index 0 to x tak ka reemiander z tha and 0 se x + m ke sum ka bhi rem 0 hai, 
        //that mean x+1 to x+m ka rem 0 hai, and wahi devisble hai
        unordered_map<long long,int>mp;
        long long pre=0;
        for(int i =0;i<n;i++){
            pre+=nums[i];
            if(pre%k ==0 && i>0) return true;
            if(mp.count(pre%k)){
                if(i-mp[pre%k]>1){
                    return true;
                }
            }else{
                mp[pre%k]=i;
            }
        }
        return false;
    }