#include<bits/stdc++.h>
using namespace std;

bool canPlace(int*arr , int n , int c , int minDistance){

    int i = 0 ;
    int j = 1;
    // place one cow at index i
    int cowsLeft = c ;
    cowsLeft = cowsLeft-1;

    while(j<n ){
        
       
        if(arr[j] - arr[i] >= minDistance){
            cowsLeft-=1;
            i = j ;
            j++;
        }else{
            j++;
        }
        if(cowsLeft==0){
            break;
        }

    }

    if(cowsLeft==0){
        return true;
    }

    return false;

}

int aggressiveCows(int *arr , int n , int c){

    int maxDifference = arr[n-1] - arr[0];
    int minDifference = 0;
    int si = 0;
    int ei = maxDifference;
    int ans = 0 ;

    while(si <= ei){

        int mid = (si+ei)/2;
        //mid will be the distance that we are covering 
        if(canPlace(arr ,n , c, mid)){
          
            ans = mid;
            si = mid+1;
        }else{
            ei = mid-1;
        }

    }
    return ans;

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int T= 0;
    cin>>T;
    while(T--){


        int n = 0 ;
        int c = 0 ;
        cin>>n>>c;

        int*arr = new int[n];

        for(int i = 0 ; i < n ; i++)
        {
            cin>>arr[i];
        }


        sort(arr , arr+n);

        //    for(int i = 0 ; i < n ; i++)
        // {
        //     cout<<arr[i]<<" ";
        // }
        // cout<<'\n';
        

        cout<<aggressiveCows(arr , n  , c)<<"\n";


        delete [] arr;

    }

}