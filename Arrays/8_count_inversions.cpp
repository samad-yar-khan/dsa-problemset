//https://practice.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;

long long int merge_sorted(long long arr1[] , long long arr2[] , long long s1 , long long s2 , long long arr3[] ){

    ll i = 0 , j = 0 , k = 0 ;
    ll array_size = s1+s2;
    ll count=0;
    while(i < s1 && j < s2){

        if(arr1[i] <= arr2[j]){
            arr3[k] = arr1[i];
            i++;
            k++;
        }else{
            arr3[k] = arr2[j];
        
            j++;
            k++;
            
            count += (s1-i);
        }

    }


    while(i<s1){
         arr3[k] = arr1[i];
            i++;
            k++;
    }
    while(j<s2){
        arr3[k] = arr2[j];
        j++;
        k++;
    }

    return count;

}


long long int merge_sort_method (long long arr[] , long long N){

    if( N  == 1 ){
        return 0;
    }

    //ih
    long long size1 = N/2;
    long long size2 = N - size1;

    long long ans1 = merge_sort_method(arr,size1);
    long long ans2 = merge_sort_method(arr+size1, size2);

    //is
    long long int* arr3 = new long long int[N];
   int my_ans = merge_sorted(arr,arr+size1 ,size1,size2, arr3 );

   delete [] arr3;
   return my_ans + ans1 + ans2;

}

 long long int inversionCount(long long arr[], long long N)
{
    // Your Code Here
    long long * arr2 =  new long long [N];
        
    for(int i = 0 ; i < N ; i++){
        arr2[i]=  arr[i];
    }
    
    long long count = merge_sort_method(arr , N);
    

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



