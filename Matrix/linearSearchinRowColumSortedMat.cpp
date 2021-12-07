#include<bits/stdc++.h>
using namespace std;
// https://practice.geeksforgeeks.org/problems/search-in-a-matrix17201720/1#

int matSearch (vector <vector <int>> &mat, int N, int M, int X)
	{
	    // your code here
	    int i =0,j=M-1;
	    while(i < N && j<M){
	        if(mat[i][j] == X){
	            return 1;
	        }
	        if(mat[i][j]>X){
	            j--;
	        }else{
	            i++;
	        }
	        
	    }
	    return 0;
	}

//the logic is that we keep our elemnt at the ewnd 
//bow if we need a largeer number we can onlu go down
//if we need a smaller numbe r, we go left
