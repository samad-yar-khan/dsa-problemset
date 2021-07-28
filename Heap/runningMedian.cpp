 
 //https://practice.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1#
 #include<bits/stdc++.h>

 using namespace std;
 
  priority_queue<double> max_pq;
    priority_queue<double , vector<double> , greater<double>> min_pq;
    void insertHeap(int &x)
    {
        if(max_pq.empty()&&min_pq.empty()){
            max_pq.push(x);
        }else if(max_pq.top()  < x){
            min_pq.push(x);
        }else {
            max_pq.push(x);
        }
        
        balanceHeaps();
        
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        
        if(max_pq.size()<min_pq.size() ) {
            max_pq.push(min_pq.top());
            min_pq.pop();
        }else if(max_pq.size()-min_pq.size()  > 1){
            min_pq.push(max_pq.top());
            max_pq.pop();
        }
        
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(max_pq.size() > min_pq.size()){
            return max_pq.top();
        }else{
            double ans = (min_pq.top()+max_pq.top())/2;
            return ans;
        }
    }