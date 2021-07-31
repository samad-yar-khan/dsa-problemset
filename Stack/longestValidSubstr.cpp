#include<bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/valid-substring0624/1#

//o(n) time and o(n) space
//logic is that we put ( in stakck along with index 
//when we see ) we have to checkif last insrted elemmnt was ( or not
//incase kast inserted elemnt was (  we pop it off else we push or ) in with its idnex
//at the end we arte left with certain brackets of differnet indices in our stakc
//the elemnts between then bracket5s were perefect strings, hencve we just need to compute tehir len
//bu subtracting indices of these and finc max

 int findMaxLen(string s) {
        // code here
        int max = INT_MIN;
        int i = 0 ;
        stack<pair<int , char>> st;
        while(i < s.length()){
            if(s.at(i)== '('){
                pair<int , char > p(i , '(');
                st.push(p);
            }else{
                if(st.size() != 0 && st.top().second == '('){
                    st.pop();
                }else{
                     pair<int , char > p(i,')');
                     
                st.push(p);
                }
            }
            i++;
        }
        if(st.size() > 0){
            int a = s.length();
            int b = st.top().first;
            st.pop();
            int diff = a-b-1;
            while(st.size()>0){
                a = b ;
                b = st.top().first;
                st.pop();
               if(a-b-1 > diff){
                diff = a-b-1;   
               }
            }
            if(b > 0){
                if(diff < b){
                    diff=b;
                }  
             }
            
            return diff;
            
        }
            return s.length();
        
       
    }

///logic 2 
//O(n) time an o(1) space
//https://www.geeksforgeeks.org/length-of-the-longest-valid-substring/ approahc 3
int findMaxLen2(string s) {
        // code here
             // code here
       int mL = 0 ;
     int lc =0 ;
     int rc = 0 ;
     for(int i = 0 ; i< s.length() ;i++){
         if(s.at(i) == '('){
             lc++;
         }else{
             rc++;
         }
            if(rc > lc ){
                lc = 0 ;
                rc = 0 ;
            }
            if(rc == lc){
                int diff= 2*rc;        
                 mL = max(mL ,diff);
            }
        
        
     }
     
     lc=0;
     rc=0;
     for(int i = s.length() -1 ; i>= 0 ;i--){
         if(s.at(i) == '('){
             lc++;
         }else{
             rc++;
         }
            if(lc > rc ){
                lc = 0 ;
                rc = 0 ;
            }
            if(rc == lc){
                int diff= 2*lc;        
                 mL = max(mL ,diff);
            }
        
        
     }

     return mL;
       
    }
