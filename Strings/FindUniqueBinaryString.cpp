#include<bits/stdc++.h>
using namespace std;


// https://leetcode.com/problems/find-unique-binary-string/

/*
Given an array of strings nums containing n unique binary strings each of length n, return a binary string of length n that does not appear in nums. If there are multiple answers, you may return any of them.
*/


/*
Approach 1

The fiirst intuitive approach was to form binary numbers out of each string, go in serial wise fashion and then we find the missing number from 1 to n 
iterating theriugh the array will take n time and forming the binary number will take n time
outer loop -> n ; n elemnts
inner loop -> n iterations ; n digit binary string

overall -> O(n^2)

sorting the binaary number will take  O(nlogn) time

storing n number will take O(n) space

Time = O(n^2  + nlogn)
Space = O(n)

*/

string findDifferentBinaryString_1(vector<string>& nums) {
        string ans;
        int n =nums.size();
        int curr =0;
        vector<int>v;
        for(int i =0;i<n ;i++){
            int num=0;
            int c=1;
            for(int j = 0;j<n; j++){
                if(nums[i][j] -'0' == 1){
                    num+=c;
                }
                c= (c<<1);
            }
            v.push_back(num);
           
        }
        sort(v.begin(),v.end());
        for(int i =0;i<n;i++){
            if(curr!=v[i]){
                break;
                
            }
            curr++;
        }
        int i =0;
       
        while(i<n){
            if(curr&1){
                ans+='1';
            }else{
                ans+='0';
            }
            curr=curr>>1;
            i++;
        }
        return ans;
        
        
    }


/*
Approach 2 : mind blown

so we have n strings , and each string has n elemnts(0/1).
if we form our answer string such that at each index, there is some mismatch with atleast one string

n = 3 ; nums=["010","000","111"]

now we start our ans as empty ; ans = ""

our first string is "010", we form our first index based on this, we have '0' in the original string so we add '1' to our, this makes sure it wont coincide with nums[0]
ans = "1"

now at i =1, nums[1] = "000", we dicide our andswers strings fist index based on this
nums[1][1] is '0' , so we add '1' to our  ans, to make it diff from nums[1]

ans = "11"

now at i = 2,nums[i] = "111", nums[i][i] = '1', so we add '0' to our answer
ans = "110"

as our ans differs from each number by one binary digit, the ans must be unique.

pattern : n number and n digits

Time = O(n)
Space = O(1)



*/


    string findDifferentBinaryString(vector<string>& nums) {
        
        string ans="";
        for(int i =0;i<nums.size();i++){
            if(nums[i][i] == '0'){
                ans+='1';
            }else{
                ans+='0';
            }
        }
    return ans;
    }
