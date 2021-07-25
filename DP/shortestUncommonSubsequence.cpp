#include<bits/stdc++.h>
using namespace std;
#include<climits>
int shortestUnSub(string S, string T) {
      
      if(S.length() == 0){
          return -1;
      }
      
      if(T.length() == 0){
          return 1 ;
      }


      
      int**arr = new int*[S.length() +1 ];
      for(int i= 0; i <= S.length() ; i++){
          arr[i] = new int[T.length() +1 ];
          for(int j = 0 ; j <= T.length() ; j++){
              arr[i][j] = -1 ;
          }
      }
      
     for(int i = 0 ; i <= S.length() ; i++){
         arr[i][T.length()] = 1;
         
     }
     
     for(int j = 0 ; j <= T.length() ; j++){
         arr[S.length()][j] = INT_MAX;
     }
     
     for(int i = S.length() -1 ; i >=0 ; i--){
         
         for(int j = T.length() - 1; j>=0 ; j--){
             
            int case1 = arr[i+1][j];
            int case2 = INT_MAX;
            
            int k = j ;
            for(;  k < T.length() ; k++){
                if(S.at(i)==T.at(k)){
                    break;
                }
            }
            
            if(k==T.length())
            {
                 arr[i][j] = 1;
               
            }else{
                case2 = arr[i+1][k+1];
                 if(case2 < INT_MAX){
                case2 ++;
                 }
            arr[i][j] = min(case1 , case2);
                 }
             
         }
         
     }
     
     int ans = arr[0][0];
     
      for(int i= 0; i <= S.length() ; i++){
          delete []arr[i] ;
      }
      delete [] arr;
      return ans;
     
  
}

int solve(string t , string s ){
    return shortestUnSub(t,s);
}