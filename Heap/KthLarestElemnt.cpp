#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-the-kth-largest-integer-in-the-array/

class comp
    {
        public:
        
            bool operator()(string a,string b){
                if(a.length() != b.length() ){
                    return a.length() > b.length();
                }
                return a > b;
            }
        
    };
    bool co(string a,string b){
                if(a.length() != b.length() ){
                    return a.length() < b.length();
                }
                return a < b;
    }
    
    string kthLargestNumber(vector<string>& nums, int k) {
        
        priority_queue<string , vector<string> , comp> pq;
        
        for(int i =0;i<k ;i++){
            pq.push(nums[i]);
        }
        
        for(int i=k ; i<nums.size() ; i++){
            if(co(pq.top() , nums[i])){
                pq.pop();
                pq.push(nums[i]);
            }
        }
        // for(int i=0;i< nums.size() ;i++){
        //     cout<<pq.top()<<" ";
        //     pq.pop();
        // }
        // return 0;
               return pq.top();
    }