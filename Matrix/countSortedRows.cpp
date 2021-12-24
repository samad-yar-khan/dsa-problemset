#include<bits/stdc++.h>
using namespace std;
//https://practice.geeksforgeeks.org/problems/count-sorted-rows2702/1#

 int sortedCount(int N, int M, vector<vector<int>> Mat) {
        // code here
        int ans =0;
        for(int i =0;i<N;i++){

            bool sortedI=true,sortedD=true;;
            for(int j =0;j<M-1;j++){
                if(Mat[i][j]>=Mat[i][j+1]){
                    sortedI=false;
                    break;
                }
            }
            for(int j =0;j<M-1;j++){
                if(Mat[i][j]<=Mat[i][j+1]){
                    sortedD=false;
                    break;
                }
            }
            if(sortedI||sortedD){
                ans++;
            }
        }
        return ans;
    }