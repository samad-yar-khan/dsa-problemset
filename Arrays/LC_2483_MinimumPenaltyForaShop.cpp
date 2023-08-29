#include<bits/stdc++.h>
using namespace std;

int bestClosingTime(string customers) {
    int n = customers.size();
    if(n==0){
        return 0;
    }
    vector<int>presum(n,0);
    vector<int>postsum(n,0);
    int c =0;
    for(int i =0;i<n;i++){
        int C = (customers[i] == 'N');
        c+=C;
        presum[i] = c;
        
    }
  
    c =0;
    for(int j =n-1;j>=0;j--){
        int C = (customers[j] == 'Y');
        c+=C;
        postsum[j] = c;
       
    }
    int min_p = presum[n-1];
    int ans = n;
    for(int i =n-1;i>=0;i--){
        int cc=0;
        if(i>=0 && i<n){
            cc+=postsum[i];
        }
        if(i-1>=0 && i-1<n){
            cc+=presum[i-1];
        }
        if(min_p >= cc){
          
            min_p=cc;
            ans = min(ans, i);
        }
    
    }
   
    return ans;
}
