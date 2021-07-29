// Given a number in base 2, convert it into base 6

// For e.g.

// 1100 in base 2 represented as [false, false, true, true] in test #1,
// 12 in base 10, and
// 20 in base 6 represented as [0, 2] in test #1.
// [execution time limit] 1 seconds (cpp)

// [input] array.boolean base2

// Max length = 100

// if ith position of the array is true that means the ith position of the number is 1.

// [output] array.integer

// ith position of the array represents the ith position of the number is in base 6
#include<bits/stdc++.h>
using namespace std;


int addNum (int*numArr , int a , int n){

    int carry = a ;
    int i = 0;
    while(carry!=0){
        int sum = carry + numArr[i];
        numArr[i] = sum%10;
        carry = sum/10;
        i++;
    }

    return max(n , i-1);

}

int devNum(int *numArr , int a , int n ){
    
}

vector<int> base2To6Hire2020(vector<bool> base2) {
    
    stack<int> s;
    long long numBase10 = 0 ;
    long long power2 = 1;
    for(int i = base2.size() -1; i >= 0 ; i--) {
            
        int a =  base2[i] ? 1 : 0;
        numBase10 += (power2*a);
        power2 = power2<<1;
        
    }
    
    while(numBase10 > 0){
        long long d = numBase10/6;
        int r = numBase10%6;
        s.push(r);
        numBase10 = d;
    }
    
    vector<int> vec ;
    while(s.size() > 0){
        vec.push_back(s.top());
        s.pop();
    }
    
    return vec;
    
}
