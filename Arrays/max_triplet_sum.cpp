#include<bits/stdc++.h>
using namespace std;

//https://www.interviewbit.com/problems/maximum-sum-triplet/
//O(n2)
//work on middle , look for left , look for right and get sum
int solve(vector<int> &A) {
   
    int S = A.size();

    int ans = 0;

    for(int i =1 ; i<S-1;i++){
        int X = 0;
        int Y = 0;
        for(int j = 0 ; j < i ; j++){
            if(A.at(j)<A.at(i)){
                X = max(X,A.at(j));
            }
        }
        for(int j = i+1 ; j<S ;j++){
            if(A.at(j) > A.at(i)){
                Y = max(Y,A.at(j));
            }
        }
        if(X==0||Y==0){
            continue;
        }
        int sum = X+Y+A.at(i);
        // cout<<X<<" "<<A[i]<<" "<<Y<<" ";
        ans = max(sum, ans);
    }

    return ans;

}


int solve(vector<int> &A) {
   
    int S = A.size();

    int ans = 0;
    set<int> s;
    s.push(A[0]);
    for(int i =1 ; i<S-1;i++){
        int X = 0;
        int Y = 0;
        for(int j = 0 ; j < i ; j++){
            if(A.at(j)<A.at(i)){
                X = max(X,A.at(j));
            }
        }
        for(int j = i+1 ; j<S ;j++){
            if(A.at(j) > A.at(i)){
                Y = max(Y,A.at(j));
            }
        }
        if(X==0||Y==0){
            continue;
        }
        int sum = X+Y+A.at(i);
        // cout<<X<<" "<<A[i]<<" "<<Y<<" ";
        ans = max(sum, ans);
    }

    return ans;

}
