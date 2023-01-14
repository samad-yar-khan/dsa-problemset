#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>vc;
        for(int i=0;i<nums.size();i++){
            for(int j =i+1;j<nums.size();j++){
                int k = j+1;
                int l = nums.size()-1;
                while(k<l){
                    if(1LL*nums[i] + 1LL*nums[j] + 1LL*nums[k] + 1LL*nums[l] == 1LL*target){
                        vector<int>vec{nums[i],nums[j],nums[k],nums[l]};
                        vc.push_back(vec);
                        int kk = k, ll = l;
                        while(kk<nums.size() && kk<l && nums[k]==nums[kk]){
                            kk++;
                        }
                        while(ll>=0 && ll>kk && nums[ll] == nums[l]){
                            ll--;
                        }
                        k=kk;
                        l=ll;
                    }else if(1LL*nums[i] + 1LL*nums[j] + 1LL*nums[k] + 1LL*nums[l] > 1LL*target){
                        l--;
                    }else{
                        k++;
                    }
                }
                while(j<nums.size()-1 && nums[j] == nums[j+1]){
                    j++;
                }
            }
            while(i<nums.size()-1 && nums[i] == nums[i+1]){
                i++;
            }
        }
        
        return vc;
            
    }