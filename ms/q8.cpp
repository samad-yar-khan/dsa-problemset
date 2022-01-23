#include <bits/stdc++.h>
#define ll long long
#define modVal 1000000007

using namespace std;


ll exp(ll m , ll n){    //m^n


    ll number = m ;
    ll power = n ;
    ll answer = 1;

    

    while( power > 0){
        if((power & 1 ) > 0){
            answer *= number ;
            answer%=modVal;
        } 
        //square the number 
        number*=number;
        number%=modVal;
        //right shift power
        power = power>>1;
    }
    return answer;
}

int main(){

    ll T{0};
    cin>>T;

    while(T--){
        
        int n =0,k=0;
        cin>>n>>k;

        vector<pair<int,int>>vec;
        for(int i =0;i<n;i++){
            int l=0,r=0;cin>>l>>r;
            vec.push_back({l,r});
        }

        sort(vec.begin(),vec.end());
        //  for(int i =0;i<n;i++){
        //     cout<<vec[i].first<<" "<<vec[i].second<<"\n";
        // }

        int i =0,j=0;

        int s=vec[i].first;
        int e=vec[i].second;
        int ans=0;
        j=1;
        int cc=0;
        while(i <n && j <n){
            
            if(j!=i && vec[i].second>=vec[i+1].first && cc>0 ){
                cc-=(vec[i].second-vec[i+1].first+1);
                i++;
            }

            while(j-i<k){
                if(e>=vec[j].first && e<=vec[j].second){
                    cc+=(e-vec[j].first+1);
                    e=max(e,vec[j].second);
                    j++;
                }else{
                    e=vec[j].second;
                    //  ans = max(ans , cc);
                    i=j;
                    cc=0;
                    break;
                }
            }
         
            if(j-i == k){
   ans = max(ans , cc);
            }
          

        }
        cout<<ans<<"\n";

    }
   


}

/*
2 
5 2 
1 10
5 15
14 50
30 70
99 100
7 6
-8 6
7 9 
-10 -5
-6 10
-7 -3
5 8
4 10

*/