#include<bits/stdc++.h>
using namespace std;

  long long findMinDiff(vector<long long> a, long long n, long long m){
    //code
        
        sort(a.begin() , a.end());
        
        if(n==m){
            return (a.at(n-1)-a.at(0));
        }
        
        long long i = 0;
        long long j = m-1;
        long long diff =a[m-1]-a[0];
        
        while(j<n){
            diff =min(a[j]-a[i] , diff);
            i++;
            j++;
        }
        return diff;
    
    }   