#include<algorithm>
#include<iostream>
#include<vector>
#include <unordered_map>
using namespace std;
#define ll long long


/*
Zero Sum Subarrays 
Medium Accuracy: 50.41% Submissions: 18200 Points: 4
You are given an array arr[] of size n. Find the total count of sub-arrays having their sum equal to 0.


Example 1:

Input:
n = 6
arr[] = {0,0,5,5,0,0}
Output: 6
Explanation: The 6 subarrays are 
[0], [0], [0], [0], [0,0], and [0,0].

Example 2:

Input:
n = 10
arr[] = {6,-1,-3,4,-2,2,4,6,-12,-7}
Output: 4
Explanation: The 4 subarrays are [-1 -3 4]
[-2 2], [2 4 6 -12], and [-1 -3 4 -2 2]

Your Task:
You don't need to read input or print anything. Complete the function findSubarray() that takes the array arr and its size n as input parameters and returns the total number of sub-arrays with 0 sum. 
 

Expected Time Complexity : O(n)
Expected Auxilliary Space : O(n)
 

Constraints:    
1<= n <= 107
-1010 <= arri <= 1010
*/
    //Function to count subarrays with sum equal to 0.
    ll findSubarray(vector<ll> arr, int n ) {
        //code here
        unordered_map<ll , ll> f;

        ll nums = 0 ;
        ll s = 0 ;
        f.insert({0,1});
        for(int i = 0 ; i  < n ; i++){
            s+=arr[i];
           
            if(f.count(s) >0){
                nums+=f[s];
                f[s] += 1;
            }else{
                f.insert({s,1});
            }
        }
            
      return nums ;
    }


int main(){
    int n = 0;
    cin>>n ;
   vector<ll> arr;
    for(int i = 0 ; i < n ; i++){
        ll a = 0;
        cin>>a;
        arr.push_back(a);
    }

    cout<<findSubarray(arr , n);

}
