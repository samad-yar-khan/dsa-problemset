#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/jump-game/
//this is a greedy approahch sing pq where we pick the max block within our range an go to it and ssee if we can reach the end
//we do this using a pq
//complecity = O(nlogn)
//space = o(n)
 bool canJump(vector<int>& nums) {
            
        //greedy + pq
        priority_queue<pair<int , int>> pq;
        
        int i = 0 ;
        int n = nums.size();

        if(n<=1){
            return true;
        }
        pq.push(make_pair(nums[0],0));
        bool* visited = new bool[n];
        
        for(int i = 0 ; i < n ; i++){
            visited[i] = false;
        }
        visited[0] = true;
        while(i<n-1 && pq.size()>0){
            
            pair<int , int> top=pq.top();
            pq.pop();
                
            i = top.second;
            int jumps = top.first;
            if(i+jumps>=n-1){
                return true;
            }
            
            while(!visited[i+jumps]){
                pq.push(make_pair(nums[i+jumps]  , i+jumps));
                visited[i+jumps] = true;
                jumps--;
            }   
        }
        
        delete [] visited;
        return false;
}

//a better approahc is o use dp
//we keep a viisted dp array where we mark if its possible to go on a index or not
//w intiially mark index 0 as viistable and then from that we wiil iteartee from i = 0 to n and if the ith index
//is viistable then we mark the rest elments we can visit using this and then we can see if we are abe to reach the end or not
// if my cyrrent elemnt is not visitabale that means i wont be able to visit the last elment aswelll and we break
 
// time= O(n)
 //space = O(n)
 bool canJumpDP(vector<int>& nums) {
        int i = 0 ;
        int n = nums.size();

        if(n<=1){
            return true;
        }
      
        bool* visitable = new bool[n];
        
        for(int i = 0 ; i < n ; i++){
            visitable[i] = false;
        }
        visitable[0] = true;
        
        for(int i = 0 ; i< n ; i++){
            if(!visitable[i]){
                break;
            }
            int jumps=nums[i];
            if(i+jumps>=n-1){
                return true;
            }
            
            while(jumps>0 && !visitable[jumps+i]){
                visitable[jumps+i] = true;
                jumps--;
            }
        }
        
        return false;
    }

    //a better space optimised soln would be to itaeret only till the vsitable elemt and we updat this visitale elmebnt each time 

bool canJumpDP(vector<int>& nums) {
    int  visitable = 0;
    int n =nums.size();

    if(n<=1)
    {   
        return true;
    }

    int visitable = 0;

    for(int i =0 ; i<n && i<=visitable ; i++){
        visitable = max(visitable , i+nums[i]);
        if(visitable >= n-1){
            return true;
        }
    }
    return false;

}