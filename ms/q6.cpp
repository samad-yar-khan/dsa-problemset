#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define mod 1000000007

long long nCr(int n, int r){

    if(r>=n){
        return 0;
    }

    //we use the pascals triangle to solve ncr 
    // we need max of r elemnts to reahc our ans
    int*pascal = new int[r+1];
    for(int i = 0 ; i <=r ; i++){
        pascal[i] = 0;
    }
    //we havc teh first row 0C0 for  now
    pascal[0] = 1;

    for(int i = 1 ;i<=n ; i++){
        for(int j = min(i,r) ;j>=1 ; j--){
            pascal[j] = (pascal[j-1]+pascal[j])%mod;
        }
    }
    long long total= 1<<n;
    long long s = 0 ;
    for(int i =0;i<r ; i++){
        s+=pascal[i];
    } 
    return total-s ;

}

int countTeams(int num  , vector<int> skills , int ma , int minL , int maxL){

    int c=0;
    for(int i = 0 ;i<skills.size() ; i++){
        if(skills[i] <= maxL && skills[i]>=minL){
            c++;
        }
    }
    if(c<ma){
        return 0;
    }
    return nCr(c , ma);
}


int main(){
  
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r" , stdin);
        freopen("../output.txt", "w", stdout);
    #endif

  

    // for(int i =0 ;i < primes.size() ; i++){
    //     cout<<primes[i]<<"\n";
    // }
    int T = 0;cin>>T;

    while(T--){

      int num = 0 ;
      cin>>num;
      vector<int>skills;
      for(int i = 0  ; i < num ; i++){
          int a = 0 ;cin>>a;
          skills.push_back(a);
      }
      int ma= 0;
      cin>>ma;
      int ml=0,ML=0;
      cin>>ml>>ML;
      cout<<countTeams(num,skills,ma,ml,ML)<<"\n";
      
    }
  

}