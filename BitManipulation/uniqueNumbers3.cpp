/*
https://leetcode.com/problems/single-number-ii/
*/

#include<iostream>
using namespace std;

#include<vector>
int singleNumber(vector<int>& nums) {

    //make an array to track bits
    int bits[33] = {0};
     int neg_bits[33] = {0};


// O(64N)
    for(int i = 0 ; i < nums.size() ; i++){
        int temp = nums[i];
        int bit_index = 0 ;
        if(temp > 0 ){
             while(temp > 0){
            if((temp&1) > 0){
                bits[bit_index]++;
            }
            temp = temp>>1;
            bit_index++;
        }
        }else{
           int t2 = (-1)*temp;
             while(t2 > 0){
                if((t2&1) > 0){
                    neg_bits[bit_index]++;
                }
                t2 = t2>>1;
                bit_index++;
            }
        }
       

    }
 
    //now bist will have the cumilative sum of all bits at each index
    //now we modulo by 3 to revove the numbers which wwere repeated thrice
    for(int i = 0 ; i < 32 ; i++){
        bits[i] = bits[i]%3;
        neg_bits[i] = neg_bits[i]%3;
    }

    int ans = 0;
    long long num = 1;

    for(int i = 0 ; i < 32 ; i++){
        ans += bits[i]*num;
        num=num<<1;
    }

     num = 1;
     for(int i = 0 ; i < 32 ; i++){
        ans -= neg_bits[i]*num;
        num=num<<1;
    }

    return ans;


}

int main(){
    int n = 0;
    cin>>n;
    vector<int>nums;
    for(int i = 0 ;  i<n ; i++){
        int a=0;
        cin>>a;
        nums.push_back(a);
    }

    cout<<singleNumber(nums)<<"\n";

    
}