//https://practice.geeksforgeeks.org/problems/finding-the-numbers0215/1
#include<iostream>
using namespace std;
#include<vector>

    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        
        int res = 0 ;
        
       for(int i =  0 ; i < nums.size() ; i++){
            
            res = res^nums[i];   
        
       }
        
        //find posn of first set bit of res
            
        int pos = 0 ;
        int temp = res;
        
        while( (temp&1) != 1){//while last bit is zero
            temp=temp>>1;
            pos++;
        }
        
        int mask = (1<<pos);
        
        int num1=0;
        for(int i = 0 ; i <nums.size() ; i++)
        {
            if((mask&nums[i]) > 0){
                num1=num1^nums[i];
            }
        }
        //num1 should have foriist number
        int num2 = num1^res;
        
        vector<int> ans;
        ans.push_back(min(num1,num2));
        ans.push_back(max(num1,num2));
        
        return ans;
        
    }