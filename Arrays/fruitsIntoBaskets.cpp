#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/fruit-into-baskets

/*
We keep two variables - n1 and n2 to deal with the type of fruit in the bucket
c1,c2 maintain the cout of fruits in that bucket

-1 indicated empty buckets

If we have an empty bucket, we put a fruit in it, such that its not put in the other bucket and we increment the count.
if we find out a third fruit we keep remiviong older added fruits, till one of the buckets get empty and is able to accomodate another type of fruit.

*/

    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int i =0;
        int j=0;
        int c1=0;
        int c2 =0;
        int n1=-1;
        int n2 = -1;
        int ans =0;
        while(j<n){
            ans= max(ans,c1+c2);
            if(n1==-1 && fruits[j]!=n2){
                n1 = fruits[j];
                c1=1;
                j++;
                continue;
            }
            if(n2 == -1 && fruits[j]!=n1){
                n2 = fruits[j];
                c2=1;
                j++;
                continue;
            }
            if(fruits[j] == n1){
                j++;
                c1++;
                continue;
            }
            if(fruits[j] == n2){
                j++;
                c2++;
                continue;
            }
            while(c1>0 && c2>0 && i< n && j<n && i<j){
                if(fruits[i] == n1){
                    i++;
                    c1--;
                }else if(fruits[i] == n2){
                    i++;
                    c2--;
                }else{
                    break;
                }
            }
            if(c1 == 0){
                n1=-1;
                
                continue;
            }
            if(c2 == 0){
                n2=-1;
                continue;
            }
            
        }
        ans = max(ans,c1+c2);
        return ans;
    }