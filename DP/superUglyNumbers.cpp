#include<bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/super-ugly-number/submissions/
//https://www.youtube.com/watch?v=0FMKNDEopR0&ab_channel=Pepcoding

    class trip{
        public:
        
        int numIndex ;
        int numPtr ;
        long long numVal;
        
        trip(int a , int b , long long c){
            numIndex = a ;
            numPtr = b ;
            numVal = c;
        }
        
    };

    class comp{
        
        public:
            
        bool operator()(trip p1 ,trip p2){
            return p1.numVal>p2.numVal;
        }
        
    };
    
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        
        vector<int> vec(n,0);
        vec[0] = 1 ;
        int m = primes.size();
      
        priority_queue<trip , vector<trip> , comp> pq;
        
        for(int i = 0 ;i < m ; i++){
            trip t(i, 0 , primes[i]*vec[0]);
            pq.push(t);
        }
        
        for(int i=1 ; i < n ; i++ ){
            
            trip node = pq.top();
            pq.pop();
            if(node.numVal <= vec[i-1]){
                trip t(node.numIndex, node.numPtr+1 , primes[node.numIndex]*(1LL)*vec.at(node.numPtr+1));
                pq.push(t);
                i--;
                continue;
            }
            vec[i] = node.numVal;
            trip t(node.numIndex, node.numPtr+1 , primes[node.numIndex]*(1LL)*vec.at(node.numPtr+1));
            pq.push(t);
           

        }
        
        return vec[n-1];
        
    }