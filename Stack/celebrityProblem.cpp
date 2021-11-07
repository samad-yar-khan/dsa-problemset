#include<bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/the-celebrity-problem/1#
  int celebrity(vector<vector<int> >& M, int n) 
    {
        // code here 
        //logic 1 was to vclasculate the indegree and our degree of each element 
        //if tehre exista a elemnt with indegree n-1 and out degree 0 , then thats our celeb
        // vector<pair<int,int>> person(n , make_pair(0,0));
        // for(int i = 0 ;i < n ; i++){
        //     for(int j =0;j < n ; j++){
        //         if(M[i][j] == 1){
        //             person[i].first++;
        //             person[j].second++;
        //         }
        //     }
        // }
        
        // for(int i = 0 ;i < n ;i++){
        //     if(person[i].first == 0 && person[i].second == n-1){
        //         return i;
        //     }
        // }
        // return -1;
        

        //tow pointer approach 
        //we put one pointer at 0(i) and one at n-1(j)
        //now if(j knows i)->j cnat eba cledb and we eleminuater j
        //if j doenst know i , i cant be a celeb and we do i++
        //so at the end i , must be a elemnt which is known by all
        ///at the end we just check if i is actuallya celeb
        
        int i = 0 ;
        int j = n-1 ;
        
        while(i<j){
            if(M[j][i] == 1){
                j--;
            }//j lnows i, j cant be a celeb
            else{
                i++;//if j doenst know i , i cant be a celeb
            }
        }
        
        int celeb = i ;
        for(int i = 0 ;i < n ; i++){
            if(celeb!=i){
                if(M[i][celeb] == 0|| M[celeb][i]==1){
                    return -1;
                }
            }
        }
        return celeb;
        
        
    }