/*
Number of 1 Bits 
Easy Accuracy: 64.8% Submissions: 17415 Points: 2
Given a positive integer N, print count of set bits in it. 

Example 1:

Input:
N = 6
Output:
2
Explanation:
Binary representation is '110' 
So the count of the set bit is 2.
Example 2:

Input:
8
Output:
1
Explanation:
Binary representation is '1000' 
So the count of the set bit is 1.
Your Task:  
You don't need to read input or print anything. Your task is to complete the function setBits() which takes an Integer N and returns the count of number of set bits.

Expected Time Complexity: O(LogN)
Expected Auxiliary Space: O(1)

Constraints:
1 ≤ N ≤ 109

Company Tags
*/
#include<iostream>
using namespace std;
    //o (log(N)) // because an int can have at most log(N) + 1 bits
    int setBits(int N) {
        // Write Your Code here
        int temp = N;
        int ans = 0;
        while(temp > 0){
            ans += (temp&1);
            temp = temp>>1;
        }
        return ans;
    }

//better method
//O(SetBits)
int setBitsFast(int N){
    int ans =0 ;
    while(N>0){
        N=(N&(N-1)); //this line will remove a set bit from left toright one by one till no set bits are left
        ans ++;
    }

    return ans;
}

int  main(){
    cout<<setBits(45)<<"\n";
    cout<<setBitsFast(45)<<"\n";
    cout<<__builtin_popcount(45)<<"\n"; //inbuilt func

}