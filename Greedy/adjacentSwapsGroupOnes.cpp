#include<bits/stdc++.h>
using namespace std;

int solve(string s) {
    int countOnes = 0;
    /*
        The logic is that we focus on removing the zeros between the One's
        YE zero ya to tum left se nmikaloge ya right se
        ab ham zero aise nikalenge ki waste swaps na ho. watse swaps are swaps between 0 and 0 
        jais sabse oehle sabse left wala zero nuikal diya One's ke bad hai ya rightmost
        to har zero ke left and right mai kitne ones hai, isdka count rakhna hai
        and jis side kame ones honge, us side kam swaps honge
        ans hame apne zero ko usi side se niklana hai
    */
    for(int i =0;i<s.length();i++){
        countOnes+=(s[i]-'0');
    }
    int currCountOnes = 0;
    int swapsNeeded =0;
    for(int i =0;i<s.length();i++){
        currCountOnes+=(s[i]-'0');
        if(s[i] == '0'){
            swapsNeeded +=(min(currCountOnes ,countOnes-currCountOnes ));
        }
    }
    return swapsNeeded;
}