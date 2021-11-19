#include<bits/stdc++.h>
using namespace std;


//https://practice.geeksforgeeks.org/problems/minimum-swaps/1#

//so what qwe can do with thisqn is that , we vcan makre pair of indexes and the numbers and then sort them accto numbers.
//after sorting the numebr attan correct position 
//no we see where the number was origfinallya asn weher it had to be .
//for this we conmnect the indexes forming a graph
//ex if 1 had to be at 3(indexes)
//3 had rto be at 2
//2 bad to be 4 and 4 at 1
//1->3->4->2->1 becoems and close cycle component and min swaps reqd to swpa them is len-1
//for single swap, 1 has to be at index 2 and index 2rlrmnt at 1 . we get 1->2->1 and we geta cycle of len = 2 and len-1 = (1) swap
//for a elemnt at corrct posmn 1->1 (1-1 = 0 swaps)


	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    
	    vector<pair<int, int>> vec;
	    for(int i = 0 ; i < nums.size() ;i++){
	        vec.push_back({nums[i],i});
	    }
	    
	    sort(vec.begin(),vec.end());
	    int count =0;
	    vector<int> v(nums.size(),0);
	    for(int i = 0 ; i<nums.size() ; i++){
	        v[i]=vec[i].second;
	    }
	    
	    vector<bool> vis(nums.size(),false);
	    int ans =0;
	    int n = nums.size();
	    for(int i = 0 ;i<n ;i++ ){
	        if(vis[i]){
	            continue;
	        }
	        int j = i;
	        int c=0;
	        while(!vis[j]){
	            c++;
	            vis[j] = true;
	            j=v[j];
	        }
	        ans+=(c-1);
	    }
	    return ans;

	}