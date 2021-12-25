#include<bits/stdc++.h>
using namespace std;


int minJumps(int arr[], int n){
        // Your code here

        vector<int> jumps(n , -1);
        jumps[0] = 0;
        
        
        for(int i =0;i<n ;i++){
            if(jumps[i]==-1){
                return -1;
            }   

            int jumps_i = arr[i];
            if(jumps_i+i >= n-1){
                return jumps[i];
            }

            while(jumps_i--){
                if(jumps[i]==-1){
                    jumps[i+jumps_i] = jumps[i]+1;
                }
            }
        }

    return jumps[n];

        

}

//min jump optimise
//on time , o1 space

//the logic is to maintain a bfs in the array
//max reach will mark the bound of where we can go with the coming jump
//steps wwill tell us  how many steps we can take with the currnet level
//at eahc index we will reset our max reach 
//as our steps are over , that means that the level is opver , and to knmow the boundof the netx levekl
//we will do maxReacgh -i
//and increment the jump

//the 
int minJumps(int arr[], int n){
        // Your code here

        int maxReach = arr[0];
        int jumps =1;
        int steps = arr[0];
        if(n==1){
            return 0;
        }
        int i =1;
        while(i<=maxReach && i < n){

            if(i==n-1){
                return jumps;
            }
            maxReach=max(maxReach,arr[i]+i);
            steps--;
            if(steps ==0){
                jumps++;
                steps= maxReach-i;
            }

            i++;
        }
        
    return maxReach >= n-1 ? jumps : -1;
        
}