#include<bits/stdc++.h>
using namespace std;

long long putMarbles(vector<int>& weights, int k) {

    priority_queue<int>max_p;
    priority_queue<int, vector<int>,greater<int>>min_p;
    if(k<=1){
        return 0;
    }
    int n = weights.size();
    vector<int>copy(n-1,0);
    for(int i =0;i<n-1;i++){
        copy[i] =  weights[i]+weights[i+1];
       
    }
    for(int i =0;i<n-1;i++){
        if(max_p.size()<k-1){
            max_p.push(copy[i]);
        }else{
            if(max_p.top()>copy[i]){
                max_p.pop();
                max_p.push(copy[i]);
            }
        }
        if(min_p.size()<k-1){
            min_p.push(copy[i]);
        }else{
            if(min_p.top()<copy[i]){
               
                min_p.pop();
                min_p.push(copy[i]);
            }
        }
    }

    long long sum1=0,sum2=0;
    while(max_p.size() && min_p.size()){
        sum1+= 1LL*max_p.top();max_p.pop();
        sum2+= 1LL*min_p.top();min_p.pop();
    }
    // cout<<sum2<<"\n"<<sum1<<"\n";
    return sum2-sum1;
    
}