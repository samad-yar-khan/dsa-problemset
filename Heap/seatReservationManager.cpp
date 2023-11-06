#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/seat-reservation-manager/

class SeatManager {
public:
    
    priority_queue<int, vector<int> , greater<int>>pq;
    int count;
    
    SeatManager(int n) {
        priority_queue<int, vector<int> , greater<int>>pq;
        this->count =1;
        this->pq = pq;
    }
    
    int reserve() {
        if (pq.size() == 0){
            return count++;
        }
        int ans = pq.top();
        pq.pop();
        return ans;
    }
    
    void unreserve(int seatNumber) {
        pq.push(seatNumber);
    }
    
};
