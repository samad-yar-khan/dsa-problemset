#include<bits/stdc++.h>
using namespace std;

//https://binarysearch.com/problems/Contiguously-Increasing-Numbers

/*
    int the problem statement we had to find number f=between s and end such that they were contigiusly increaisng 
    and within the range
    so we pefrom bfs on number bw s and e and add the enxt digit in end if its less than e and 
    if number is within range, we push it to ans
*/

vector<int> solve(int start, int end) {
    queue<int>pn;
    for(int i =1;i<=9;i++){
        pn.push(i);
    }
    vector<int> ans;
    while(!pn.empty()){
        int curr = pn.front();
        pn.pop();
        int ld = curr%10;
        if(ld+1 <=9 && ld+1+(curr*10) <= end){
            pn.push(ld+1+curr*10);
        }
        
        if(curr<=end && curr >= start){
            ans.push_back(curr);
        }
        
    }
    return ans;
}