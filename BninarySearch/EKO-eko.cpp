#include<bits/stdc++.h>
#define ll long long
using namespace std;
//https://www.spoj.com/problems/EKO/
/*
we ccan set ht to 0or to max ht , so we run binary search on this range and see if we can get k wood from tht cutting ht
if w1e are able to get k wood from this ht then we increae the ht and check if we cant ket the same reuslts by increaisng ht
if ts not possible we dicrease teh ht and cut more trees
*/

bool canGetWood(int *arr , int n , int h , int k){

    int treeAccuired = 0 ;
    for(int i = 0 ; i< n  ;i++){
        if(arr[i] > h){
            treeAccuired+=(arr[i]-h);
        }

        if(treeAccuired>=k){
            return true;
        }
    }
    return false;

}

int main(){

    int N = 0 ;
    int M = 0 ;
    int *arr = new int[N];

    cin>>N>>M;
    int maxHt =  0;
    for(int i = 0 ; i < N  ; i++){
        cin>>arr[i];
        maxHt = max(maxHt , arr[i]);
    }

    int si = 0 ;
    int ei = maxHt;
    int ans  = 0  ;
    while(si <= ei)
    {
        ll mid = si+ (ei-si)/2;

        if(canGetWood(arr ,  N , mid , M)){
            ans = mid;
            si= mid+1;
        }else{
            ei=mid-1;
        }

    }
    cout<<ans<<"\n";
    delete [] arr;
    return 0;
}