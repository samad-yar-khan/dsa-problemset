#include<bits/stdc++.h>
#define ll long long
using namespace std;


using namespace std;
 
void SieveOfEratosthenes(bool *prime)
{
    // Create a boolean array
    // "prime[0..n]" and initialize
    // all entries it as true.
    // A value in prime[i] will
    // finally be false if i is
    // Not a prime, else true.
   
    memset(prime, true, sizeof(prime));
 
    for (int p = 2; p * p <= 1001 ; p++)
    {
        // If prime[p] is not changed,
        // then it is a prime
        if (prime[p] == true)
        {
            // Update all multiples
            // of p greater than or
            // equal to the square of it
            // numbers which are multiple
            // of p and are less than p^2
            // are already been marked.
            for (int i = p * p; i <= 1001; i += p)
                prime[i] = false;
        }
    }
 
   
}
 
// Driver Code


ll solve(string S , bool*arr){

    
  


}

int main(){

    

    int T = 0 ; 
    cin>>T;

     
    while(T--){

       string  S = 0 ;
        cin>>S;
        bool arr[1000001] ;
        SieveOfEratosthenes(arr);
        solve(S , arr); 
       

    }

}