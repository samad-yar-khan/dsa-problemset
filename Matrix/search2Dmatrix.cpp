#include<bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/search-a-2d-matrix/submissions/

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int si =0;
        int ei = rows*cols -1 ;
       
        while(si <= ei){
                
            int mid = si + ((ei-si)/2);
            
            int y = mid%cols;
            int x = mid/cols;
            // cout<<"("<<x<<','<<y<<")";
            if(matrix[x][y] == target){
                return true;
            }
            
            if(matrix[x][y] > target){
                ei=mid-1;
            }else{
                si=mid+1;
            }
            
            
        }
        return false;
        
    }