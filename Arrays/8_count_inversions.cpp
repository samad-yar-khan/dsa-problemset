//https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

long long merge(long long  arr[], long  long l, long long m, long long r)
    {
         // Your code here
        long long size = r-l+1;
        long long*arr2 = new long long[size]{0};
        long long ans = 0  ;
        long long i{0} , j{0} , k{0};
        i = l ;
        k = 0 ;
        j = m+1;
        bool fc{false};
        while( i <= m && j <=r){
            
            if(arr[i] <= arr[j]){
                arr2[k++] = arr[i++];
               
            }else{
                arr2[k++] = arr[j++];
                ans += m-i+1;
            }
            
        }

        // if(i <= m){
        //     ans+= ((m-i)*(r-m));
        // }
        
        while(i <= m){
            arr2[k++] = arr[i++];
        }
        while(j<=r){
            arr2[k++] = arr[j++];
        }
        
        //now we have to copy back
        long long it1{l} ,it2{0};
        
        while(it2 < size){
            arr[it1++] = arr2[it2++];
        }
        
        delete []arr2;
        return ans ; 
    }

    long long  mergeSort(long long arr[], long long l, long long  r)
    {
        //code here
        if(l>=r){
            return 0; //size 0 ,1
        }
        
        //ih
        long long mid = (l+r)/2;
        long long a1 = mergeSort(arr,l , mid );
        long long a2 = mergeSort(arr , mid+1,r);
        
        //is
        long long ma = merge(arr , l , mid , r);//merge and copy
        return a1+a2 + ma;
    }


 long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
    long long * arr2 =  new long long [N];
        
    for(int i = 0 ; i < N ; i++){
        arr2[i]=  arr[i];
    }
    
    long long count = mergeSort(arr2 , 0 , N-1);
    

    delete [] arr2;
    return count;
    
}

int main(){

    ll n{0};
    cin>>n;

    ll* arr = new ll[n];

    for(ll i{0} ; i < n ; i++){
        cin>>arr[i];
    }

    cout<<"Ans : "<<inversionCount(arr , n);


    delete [] arr;

}



