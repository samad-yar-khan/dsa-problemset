#include<bits/stdc++.h>
using namespace std;


// https://practice.geeksforgeeks.org/problems/maximize-sum-after-k-negations1149/1#
//logic
// so we flip our negative nums , till iether we have flipped all k , or we have reached the positive boundry , if we flipped all k , then we just need to add the rest , else if we reach the positive boundryiy , we need tosort the array again and just flip the smallest number k times becasue that would lead to min deductiion drom overall sum

 long long int maximizeSum(long long int a[], int n, int k)
    {
        // Your code goes here
        sort(a , a+n);
        int i = 0 ;
        long long int s = 0;
     
        while(i<k && a[i]<0){
            
            a[i]=-1*a[i];

            i++;
        }
        sort(a,a+n);
        if((k-i)%2 !=0 && (k-i)!=0){
            a[0] = -a[0];
        }
        i=0;
        while(i<n){
            s+=a[i];
            i++;
        }
        return s;
    }