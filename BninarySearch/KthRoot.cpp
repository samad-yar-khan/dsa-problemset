#include<iostream>
using namespace std;
#define int long long

int power( int n , int k){

    int a = n;
    int ans = 1;
    while(k>0){
        if(k&1 == 1){
            ans*=a;
        }
        k=k>>1;
        a=a*a;
    }

    return ans;

}

int KthRoot(int n , int k){
    int si = 1;
    int ei = n;
    int ans = 0;
    while(si<=ei){
        int mid = si+ ((ei-si)/2);
      
        int value = power(mid , k);
        // cout<<value<<"\n";
        
        //overflow

        if(value <= 0){
            ei=mid-1;
            continue;
        }
        if( value == n){
            return mid;
        }

        if(value<=n ){
            si=mid+1;
            ans=max(mid,ans);
        }else{
            ei=mid-1;
        }
    }
    return ans;
}

int main(){

    int T=0;
    cin>>T;
    while (T--)
    {
        /* code */

        int n = 0 ;
        int k = 0 ;

        cin>>n>>k;
        cout<<KthRoot(n , k)<<"\n";

    }
    return 0;

}
