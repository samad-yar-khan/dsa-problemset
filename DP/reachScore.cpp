#include<bits/stdc++.h>
using namespace std;

//https://practice.geeksforgeeks.org/problems/reach-a-given-score-1587115621/1#
//indian coin chnage problem is the key , firt we mark the ways to makle the numebr through 3
//then we see how we can marke the numebr uising 5 and use the ways already donr by3 
//the n we see how wwe can make the number using 10 and using prev reuslts of 3 and 5


long long int count(long long int n)
{   
        
    if(n<3){
        return 0;
    }
    vector<long long>dp(n+1,0);
    vector<int> arr;
    dp[0]=1;
    arr.push_back(3);
    arr.push_back(5);
    arr.push_back(10);
    
    for(int i=0;i< 3 ;i++){
        for(int j = arr[i];j<=n ; j++){
            dp[j]+=dp[j-arr[i]];
        }
    }
    
    return dp[n];
    
}
