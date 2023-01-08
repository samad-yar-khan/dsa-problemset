#include<bits/stdc++.h>
using namespace std;


/*
We create a diff array whose sum needs to be >=0 for the answer to exist
we add values to cs till its +ve, when it becomes -ve we move the ptr to the next value
because none of the values in between can lead to an answer
*/
int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = cost.size();
        vector<int>diff(n,0);
        int ts =0;
        for(int i=0;i<n;i++){
            diff[i] = gas[i]-cost[i];
            ts+=diff[i];
        }
        if(ts<0){
            return -1;
        }
        int i =0;
        int j =0;
        int cs =0;
        bool done = true;
        int vis = 0;
        while(vis<n){
            cs+=diff[j];
            vis++;
            if(cs < 0){
                vis=0;
                cs=0;
                j++;
                i=j;
            }else{
                j=(j+1)%n;
            }
        }
        return i;
    }