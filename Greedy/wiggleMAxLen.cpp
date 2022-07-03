#include<bits/stdc++.h>
using namespace std;

//we just need to find increaisng and dicreasing pairs of susbseql , for gthis we can always find numbe rof peaks in array

 int wiggleMaxLength(vector<int>& nums) {
       
        if(nums.size()==0){
            return 0;
        }
        
        if(nums.size() == 1){
            return 1;
        }
        int ans =2;
        int d1 = nums[1]-nums[0];
        int i =1;
        while(i<nums.size()-1 && d1==0){
            d1=nums[i+1]-nums[i];
            i++;
        }
        if(d1==0){
            return 1;
        }
        for(;i+1<nums.size();i++){
            int d2 = nums[i+1]-nums[i];
            if(d2 == 0){
                continue;
            }
            if((d2>0 && d1<0) || (d2<0 && d1>0)){
                d1=d2;
               
                ans++;
            }
        }
        return ans;
    }