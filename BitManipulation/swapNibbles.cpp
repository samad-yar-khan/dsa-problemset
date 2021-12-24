#include<bits/stdc++.h>
using namespace std;
//https://practice.geeksforgeeks.org/problems/swap-two-nibbles-in-a-byte0446/1
 int swapNibbles( unsigned char x){
        // code here
        unsigned char leftHalf = (x<<4);
        unsigned char rightHalf = (x>>4);
        
        return leftHalf+rightHalf;
    }