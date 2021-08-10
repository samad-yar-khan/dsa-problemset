#include<bits/stdc++.h>
using namespace std;
#define ll long long


ll solve(int*arr , int n ){
  
    sort(arr , arr+n);
    ll s = 0;
    for(int i = 0 ; i < n ; i++){
        s+=arr[i];
    }

    ll avg = s/n;//avg would be optimal
    ll leftOver = s%n;
    ll count = 0;

    if(leftOver == 0){

        for(int i = 0 ; i< n ; i++){
            if(arr[i]<avg){
                count+=(avg-arr[i]);
            }
        }

       
    }else{

        avg+=1;

        int i = 0 , j = n-1;
        while( i < j && arr[j]>avg &&arr[i] <avg){

        
            int right = arr[j];
            int loan = right - avg;
            int need = avg-arr[i];

            if(loan == need){
                arr[j] -= loan;
                arr[i] +=loan;
                i++;j--;
                count+=loan;
            }else if(loan > need){
                arr[j] -= need;
                arr[i] += need;
                i++;
                count+=need;
            }else{
                arr[i]+=loan;
                arr[j]-=loan;
                j--;
                count+=loan;
            }

        }

        for(int i =0 ; i < n ; i++){
            if(arr[i] < avg){
                count+=(avg-arr[i]);
            }
        }

     
    }
    
    return count;

}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    int T= 0 ;
    cin>>T;
    while(T--){

        int  n = 0 ;
        cin>>n;
        int arr[100000]={0};
        for(int i = 0 ; i < n ; i++){
            cin>>arr[i];
        }   

        cout<<solve(arr , n)<<"\n";

    }

}