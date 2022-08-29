  #include<bits/stdc++.h> 
  using namespace std;

   
    int stallsVisisted(int distance, int initEnergy, vector<int>dis,vector<int>lit) {
        int f = initEnergy;
        int i =0;
        long long curr = initEnergy;
        priority_queue<long long> pq;
        int count =0;
        while(i<dis.size() && curr < distance){
            while(i<dis.size() && dis[i]<=curr){
                pq.push(lit[i]);
                i++;
            }
            if(curr<distance && pq.empty()){
                break;
            }
            if(pq.size()){
                curr+=pq.top();
                count++;
                pq.pop();
            }

        }
        while(pq.size() && curr<distance){
                curr+=pq.top();
                count++;
                pq.pop();
        }
        return (curr>=distance)?count:-1;
    }