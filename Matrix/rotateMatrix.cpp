#include<bits/stdc++.h>
using namespace std;


//https://practice.geeksforgeeks.org/problems/rotate-a-2d-array-without-using-extra-space1004/1/
	void rotateMatrix(vector<vector<int>>& arr, int n) {
	    // code here   
	       
	       for(int i =0;i<n/2;i++){
	            
	            for(int j =i;j<n-i-1 ;j++){
	                    
	                int temp=arr[i][j];
	                arr[i][j] = arr[j][n-i-1];
	                arr[j][n-i-1]=arr[n-i-1][n-j-1];
	                arr[n-i-1][n-j-1]=arr[n-j-1][i];
	                arr[n-j-1][i]=temp;
	                    
	            }
	           
	       }
	    
	}
