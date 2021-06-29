#include<iostream>
#include<cmath>
#define ll long long
using namespace std;
//https://hack.codingblocks.com/app/practice/1/1264/problem

//counts number of set bits in a number
int setBitsFast(int n){
    int ans = 0;
    while (n > 0)
    {
        n = n&(n-1);
        ans++;
    }
    return ans;
    
}


int main(){
   
    int primes[] = {2,3,5,7,11,13,17,19}; //8 so , to make subsequences we need numbers fro 1 to 2^8 - 1

    int T = 0;
    cin>>T;
    while (T--){
    
        ll ans = 0 ;
        int n = 0 ;
        cin>>n;

        for(ll i = 1 ; i <= (1<<8) -1 ; i++){ //8 because array has 8 elemens and 1<<8 - 1 => 11111111

            ll denominator = 1;
            // for(int j = 0 ; j <=7 ; j++){
            //     if(i&(1<<j)){ //check if jth bit from the right is set or not
            //         denominator=denominator*primes[j];
            //     }
            // }

            int num = i , j = 0;

            while(num > 0){
                if(num&1){
                    denominator=denominator*primes[j];
                }
                num=num>>1;
                j++;
            }

            ll ourSet = n/denominator;
            int numSetBits = __builtin_popcount(i);
            if(numSetBits & 1){//odd numbe of set bits mean we have taken odd numbe of primes for the set
                ans += ourSet;
            }else{
                ans -= ourSet;
            }

           

        }


        cout<<ans<<"\n";


    } 
    

}