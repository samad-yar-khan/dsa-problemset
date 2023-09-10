#include<bits/stdc++.h>
using namespace std;
/*
Input: n = 2
Output: 6
Explanation: All possible orders: 
(P1,P2,D1,D2), (P1,P2,D2,D1), (P1,D1,P2,D2), (P2,P1,D1,D2), (P2,P1,D2,D1) and (P2,D2,P1,D1).
This is an invalid order (P1,D2,P2,D1) because Pickup 2 is after of Delivery 2.

considering the above case, we can define the cases like calculating permutations of numbers from 1 to n where each number is repeated twice: {1, 2, 1, 2}. Where 2 indicate delivery or pickup of 2 but only one of them can take place since pickup will have to be first. 
So answer will be ((2n)!)/(2^n)
*/

int countOrders(int n) {

    long long ans  =1;
    long long modval = 1000000007;
    for(int i =1;i<=n;i++){
        ans = (ans*i)%modval;
    }
    for(int i =1;i<2*n;i+=2){
        ans = (ans*i)%modval;
    }
    return ans;
}