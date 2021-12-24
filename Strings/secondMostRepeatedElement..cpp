#include<bits/stdc++.h>
using namespace std;
//https://practice.geeksforgeeks.org/problems/second-most-repeated-string-in-a-sequence0534/1#
string secFrequent (string arr[], int n)
    {
        //code here.'
        unordered_map<string , int>m;
        for(int i=0;i<n ;i++){
            m[arr[i]]++;
        }
        int v=0;
        auto x = m.begin();
        for(auto i = m.begin() ;i!=m.end() ; i++){
            if(v<i->second){
                x=i;
                v=i->second;
            }
        }
        auto y = m.begin();
        v=0;
         for(auto i = m.begin() ;i!=m.end() ; i++){
            if(v<i->second && i!=x ){
                y=i;
                v=i->second;
            }
        }
        return y->first;
    }