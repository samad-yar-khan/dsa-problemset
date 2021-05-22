//https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

// long long merge(long long  arr[], long  long l, long long m, long long r)
//     {
//          // Your code here
//         long long size = r-l+1;
//         long long*arr2 = new long long[size]{0};
//         long long ans = 0  ;
//         long long i{0} , j{0} , k{0};
//         i = l ;
//         k = 0 ;
//         j = m+1;
//         bool fc{false};
//         while( i <= m && j <=r){
            
//             if(arr[i] <= arr[j]){
//                 arr2[k++] = arr[i++];
               
//             }else{
//                 arr2[k++] = arr[j++];
//                 ans += m-i+1;
//             }
            
//         }
        
//         while(i <= m){
//             arr2[k++] = arr[i++];
//         }
//         while(j<=r){
//             arr2[k++] = arr[j++];
//         }
        
//         //now we have to copy back
//         long long it1{l} ,it2{0};
        
//         while(it2 < size){
//             arr[it1++] = arr2[it2++];
//         }
        
//         delete []arr2;
//         return ans ; 
//     }

//     long long  mergeSort(long long arr[], long long l, long long  r)
//     {
//         //code here
//         if(l>=r){
//             return 0; //size 0 ,1
//         }
        
//         //ih
//         long long mid = (l+r)/2;
//         long long a1 = mergeSort(arr,l , mid );
//         long long a2 = mergeSort(arr , mid+1,r);
        
//         //is
//         long long ma = merge(arr , l , mid , r);//merge and copy
//         return a1+a2 + ma;
//     }

long long mergeSorted(long long* arr1 , long long *arr2 ,  long long si1 , long long ei1 , long long si2 , long long ei2 , long long *arr3 ){

    ll i{si1} , j{si2} , k{0} , count{0};
    
    while( i <= ei1 && j <= ei2){

        if(arr1[i] <= arr2[j]){
            arr3[k++] = arr1[i++];
        }else{
            //if our jth element is smaller than ith , then it will be smalller than ei-i+1 elemnts 
            count+=ei1-i+1;
            arr3[k++] = arr2[j++];
        }

    }

    while(i<=ei1){
         arr3[k++] = arr1[i++];
    }
    while(j<=ei2){
        arr3[k++] = arr2[j++];
    }

    return count ;

}


long long mergeSort(long long* arr, long long si , long long ei){

    //bc
    if(si>=ei){
        return 0;
    }

    //ih devide and conq
    long long mid = (si+ei)/2;

    long long leftInv = mergeSort(arr ,  si , mid);
    long long rightInv = mergeSort(arr , mid+1 , ei);

    //now our left and right right arrays aare sorteda and we need to combine them and get our crosss inversions between array left and right 
    long long *temp  = new long long [ei-si+1];

    long long ourInv = mergeSorted(arr , arr , si , mid , mid+1 , ei , temp);

    //now temp is sorted combination of array from indices si to ei and we copy it back 
    //while our function retunrd our inversions
    for(int i = 0 ; i < ei-si+1 ; i++){

        arr[si+i] = temp[i];

    }

    delete [] temp;

    return ourInv + leftInv + rightInv;

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



