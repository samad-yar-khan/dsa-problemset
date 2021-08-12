#include<bits/stdc++.h>
using namespace std;

//https://practice.geeksforgeeks.org/problems/minimum-cost-of-ropes-1587115620/1

//the min cost can only occur if at each time we join te ropes with minimun cost 
//after joining push the ropes in the pq again and then a the end 
//we will be left with just on rope and thats when we return the cost
/*

pehele sabse choti ropes ko hi join karkek min cost ayega , kyuki fir unhe nahi liya to koi aur badi add hogi 
and next addition mai cost badha hi jayega 

*/

long long minCost(long long arr[], long long n) {
        // Your code here
    priority_queue<long long , vector<long long > , greater<long long>> pq;
    for(int i = 0 ;  i < n ; i++){
        pq.push(arr[i]);
    }
    long long cost = 0;
    while(pq.size()>1){
        long long a = pq.top();
        pq.pop();
        long long b = pq.top();
        pq.pop();
        cost+=(a+b);
        pq.push(a+b);
    }
    return cost;

}