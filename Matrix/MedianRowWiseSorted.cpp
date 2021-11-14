#include<bits/stdc++.h>
using namespace std;


   //https://practice.geeksforgeeks.org/problems/median-in-a-row-wise-sorted-matrix1527/1#
   
    class trip{
        
        public :
        
        int x;
        int y;
        int val;
        
        trip(){
            x=0;
            y=0;
            val=0;
        }
        
        trip(int X,int Y, int V){
            x=X;
            y=Y;
            val=V;
        }
        
        
    };
    
    class compClass{
        
        public :
        
        bool operator()(trip t1 , trip t2){
                
            return t1.val > t2.val;
            
        }
          
    };

    int median(vector<vector<int>> &matrix, int r, int c){
        // code here          
        
        priority_queue<trip,vector<trip>,compClass> pq;
      
        int its = 0 ;
        int ans = 0;
        int n = ((r*c)/2)+1;
        
        for(int i = 0 ;i<r ;i++){
            
            trip t(i,0,matrix[i][0]);
            pq.push(t);
        }
        
      
        
        while(its < n){
            trip t = pq.top();
            
            pq.pop();
            ans = t.val;
            // cout<<ans<<" ";
            
            trip newT(t.x,t.y+1,matrix[t.x][t.y+1]);
           if(t.y+1<c){
               pq.push(newT);
           }
            
            its++;
        }
        return ans;
        
    }
