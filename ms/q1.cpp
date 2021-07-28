#include<bits/stdc++.h>
using namespace std;


int solve(char*arr , int*arr2 , int n){

    int i = 0;
    int ans = 0;
    while( i < n-1){

        int j = i+1;
        int sum = arr2[i];
        int maxVal = arr2[i];

        while(arr[j] == arr[i]){
            maxVal = max(maxVal , arr2[j]);
            sum += arr2[j];
            j++;
        }
        int minCost =  sum - maxVal;
        ans +=minCost;
        i = j ;
    }

    return ans;

}

int main(){

   char arr[] = {'a' ,'b' ,'c','a','a','a'};
   int arr2 [] = { 1, 2  ,3 , 4,  5 ,6 };
   cout<<solve(arr ,arr2 , 6);

}