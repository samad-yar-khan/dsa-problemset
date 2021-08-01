#include<bits/stdc++.h>

using namespace std;


float root(float n , float p){
    
    int si = 0;
    int ei = n;
    float ans  = INT_MIN ;
    while(si <= ei){
        int mid = (si+ei)/2;

        if(mid*mid == n){
            return mid;
        }else if(mid*mid < n){
            if(mid>ans){
                ans = mid;
            }
            si=mid+1;
        }else{
            ei = mid-1;
        }

    }

    // float poin
    float inc = 0.1;
    for(int i = 1 ; i <= p ; i++){

        
        while(ans*ans <= n){
            ans = ans+inc;
        }
       ans = ans-inc;//because we have overshot the value
        inc = inc/10;

    }


    return ans;
}


int main(){

    int n = 0 ;
    cin>>n;
    cout<<root(n,3);
    return 0;
}