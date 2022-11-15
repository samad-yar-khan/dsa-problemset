#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/find-median-from-data-stream/
class MedianFinder {
public:
    
    priority_queue<int>max_h;
    priority_queue<int, vector<int>, greater<int>>min_h;
    int size;
    
    MedianFinder() {

        this->size=0;
        max_h.push(INT_MIN);
        min_h.push(INT_MAX);

    }
    
    void addNum(int num) {
        size++;
        if(num <= max_h.top()){
            max_h.push(num);
        }else{
            min_h.push(num);
        }
        int diff = max_h.size()-min_h.size();
        if(diff<=-2){
            max_h.push(min_h.top());
            min_h.pop();
        }else if(diff>=2){
            min_h.push(max_h.top());
            max_h.pop();
        }
    }
    
    double findMedian() {
        double ans =0;
        if(min_h.size() == max_h.size()){
            ans = min_h.top() + max_h.top();
            ans/=(double)2;
        }else{
            if(min_h.size() > max_h.size()){
                ans = min_h.top();
            }else{
                ans =max_h.top();
            }
        }
        return ans;
        
    }
};
