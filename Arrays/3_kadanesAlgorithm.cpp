#include <bits/stdc++.h>

using namespace std;

int maxSubarraySum(int arr[], int n){

    //edge case 
    if(n ==1 ){
        return arr[0];
    }   
    
    //assume that the first element is the max sum till the curent posn and also that the max uptill now
    int max_subarr_sum = arr[0]; //means the maxx sub array sum upptill now
    int max_sum_ending_at_tail = arr[0];//means the max subarray sum we get if we include arr[i] or the elemnt at the end

    int i = 1;
    while (i < n)
    {   

         max_sum_ending_at_tail = max ( max_sum_ending_at_tail+arr[i] , arr[i]);
        max_subarr_sum = max(max_subarr_sum, max_sum_ending_at_tail);

        i++;
    }

    return max_subarr_sum;
    
}   