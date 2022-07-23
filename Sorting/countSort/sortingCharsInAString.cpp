#include<bits/stdc++.h>
using namespace std;

/*
    Count sort is appliaed when numbers beinge sorted are in a given range.
    or 
    The sortinng parameter of elements is in given range
    steps -> figure out the min and max elements and decide range of frrquqncy array
        ->Iterate through the elements and calculate frequcny
        -> now we need to convert this freq array to a position array, so that we can know the last position of an elemnt in sorted order
        -> so, make this freq array a presum and we get the last position for the values
        -> now we decremenent the values one to get the last index for the values
        -> noew itrate form the back and place elemnts in respctive last position and decrenet the position by 1
        -> this is done to achiev stable sorting
*/

//https://practice.geeksforgeeks.org/problems/counting-sort/1
string countSort(string arr){
        // code here
        //Count Sort
        vector<int>freq(26,0);
        int n = arr.length();
        for(int i = 0 ; i < n ; i++){
            freq[arr[i]-'a']++;
        }
        //nowe we make this is a presum array so taht it can indicate the last index where ith char needs tp be places
        int presum=0;
        for(int i =0;i<26 ;i++){
            presum += freq[i];
            freq[i] = presum;
        }   
        //subtrat -1 from each freq to make it denote index and not the position
        
        for(int i =0;i<26 ;i++){
            freq[i]--;
        }   
        //now we iterate from the back and place the arr[i] characters in respective position
        //using freq and decrement frer[arr[i]]
        string ans(arr);
        
        for(int i =n-1 ; i>=0 ;i--){
            int pos = freq[arr[i]-'a']--;
            ans[pos] = arr[i];
        }
        return ans;
    }