#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;

//brute forec rec
int balancedBTs(int h){
    //base case
  //base case
    if (h <=1){
        return 1;
    } 

    //is
   
    long tree1 = balancedBTs(h-1)%mod;
    long tree2 =  balancedBTs(h-2)%mod;

     //case 1 , left and right have same ht
    int case1=(tree1*tree1)%mod;
    //diff hts
    int case2 = (tree1*tree2)%mod ;
    int case3 = (tree1*tree2)%mod;

    return ((case1 + case2)%mod + case3)%mod;

    
}


//memoization
int balanceBt_memo(int ht , int *arr)
{

    if(ht <= 1){
        return 1;
    }
    //check
    if(arr[ht] != -1){
        return arr[ht];
    }

    //ih
    long tree1 = balanceBt_memo(ht-1 , arr)%mod;
    long tree2 = balanceBt_memo(ht-2 , arr)%mod;

    // left and right subtree have same ht
    int case1 = (tree1*tree1)%mod;
    //unequal hts
    int case2 = (tree2*tree1)%mod;

    int case3 = (tree1*tree2)%mod;

    arr[ht] = ((case1 + case2)%mod + case3%mod)%mod;
    return arr[ht];

}

//dp method
 long long int countBT(int h) { 
        // code here
        long long int*arr = new long long int[h+1];
        for(int i = 0 ; i <= h ; i++){
            arr[i] = -1;
        }   
        
        arr[0] = 1 ;
        arr[1]  = 1 ;
        for(int i = 2 ; i <=h ; i++){
                
            long long int tree1 = arr[i-1]%mod;
            long long int tree2 = arr[i-2]%mod; 
            
            long long int case1 = (tree1*tree1)%mod;
            long long int case2 = (tree2*tree1)%mod;    
            long long int case3 = (tree2*tree1)%mod;
            
            arr[i] = ((case1+case2)%mod + case3)%mod;
        }
            
        
        long long int ans = arr[h];
        delete [] arr;
        return ans;
    }

