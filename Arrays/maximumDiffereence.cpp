#include<bits/stdc++.h>
using namespace std;

void printArr(int *arr , int  n){
    cout<<"----ARRAY-----\n";
     cout<<"\n[ ";
    for(int i =0;i< n ; i++){
       
        cout<<arr[i]<<",";
       
    }
     cout<<" ]\n";
}

    int findMaxDiff(int arr[], int n)
    {
      //Your code here
       int *LF = new int[n];
       int *RF = new int[n];
       
    for(int i = 0 ;  i< n ; i++){
        LF[i]= 0;RF[i] =0;
        //got to left
        int j = i ;
        while(j >= 0){
            if(arr[j] < arr[i]){
                LF[i] = arr[j];
                break;
            }
            j--;
        }
        j =  i ;
        while( j < n){
            if(arr[j] < arr[i]){
                RF[i] = arr[j];
                break;
            }
            j++;
        }
        
    }
    int ans = INT_MIN;
    for(int i =0; i < n ; i++){
        ans = max(ans , abs(LF[i]-RF[i]));
    }
      
        delete [] LF;delete [] RF;
        return ans;
    }

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

     #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r" , stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    int T=0;
    cin>>T;
    while(T--){

        int n=0;
        cin>>n;
        int*arr = new int[n];
        for(int i =0;i< n;i++){
            cin>>arr[i];
        }
        
    cout<<findMaxDiff(arr , n)<<"\n";

        delete [] arr;
    }

}
