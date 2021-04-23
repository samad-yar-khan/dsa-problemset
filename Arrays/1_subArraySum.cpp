#include <bits/stdc++.h>
#define ll long long
using namespace std;


vector<ll> subarraySum(ll*, ll , ll );

//sliding window optimised
vector<int> subarraySumOptimised(int*, int , int );


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n{0} , s{0};
    cin>>n>>s;

    int* arr = new int[n];
    for(int i = 0 ; i < n ; i++){
        cin>>arr[i];
    }

    vector<int> ans = subarraySumOptimised(arr, n , s);

    for(auto i:ans){
        cout<<i<<' ';
    }

    return 0;
}

//sliding window technique

vector<int> subarraySumOptimised(int *arr, int n, int s){

    int si {0} , ci{0} , temp_sum{0};
    //we initially put our first element into this sum 
    temp_sum+=arr[ci++];
    while(ci<=n && si<=n){ //equal because we may  reach a case wherw e reach the end and then start removing elements
    
        if(temp_sum<s){
            temp_sum+=arr[ci++];           
        }else if(temp_sum>s){
            temp_sum-=arr[si++];
        }else{
            break;
        }

    }

    vector<int> ans;
        
    if(temp_sum == s){
        ans.push_back(si+1); //we need this in the indexing starting from 1
        ans.push_back(ci);
    }else{
        ans.push_back(-1);
    }

    return ans;

}


//naive soln O(n^2)
vector<ll> subarraySum(ll *arr, ll n, ll s){
        
        // Your code here
        bool found_s = false;
        
        ll si{0} , ei{0};
        
        for(ll i  = 0 ; i < n ; i ++){
            int sum = 0 ;
            si = i ;
            for(int j = i ; j < n ; j++){
                sum +=  arr[j];
               
                if(sum == s){
                    ei = j;
                    found_s = true ;
                    break;
                }
            }
            
            if(found_s){
                break;
            }
        }
        
        vector<ll> ans;
        if(ei == 0){
            ans.push_back(-1);
            return ans;
        }
        ans.push_back(si+1);
        ans.push_back(ei+1);
        return ans;
        
    }







