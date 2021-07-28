#include<bits/stdc++.h>
using namespace std;

//naive backtack solution 
//i fcan take each numbe - 0 time , 1 time , 2time ---n times till its diiff is not negative 
//memoization 
//if we remove the array arr we get abcktracing
   long long int help( int S[], int m, int n  , int ind  , long long int**arr ){

    //base case
    if(n==0){
        return 1;
    }
    //edge case
    if(n<0 || ind>=m){
        return 0;
    }
    
    if(arr[ind][n]!=-1){
        return arr[ind][n];
    }
    
    //backtrack
    long long int ans = 0;
    int num = S[ind];
    int takenNum = 0 ;
    while(takenNum <= n){

        ans += (help(S , m , n - takenNum , ind+1 ,arr));
        takenNum+=num;

    }

    arr[ind][n] = ans;
    return ans;

}

 long long int count( int S[], int m, int n ){
    
    long long int**arr = new long long int*[m+1];
    for(int i = 0 ; i <=  m ; i++){
        arr[i] = new long long int[n+1];
        for(int j = 0 ; j<= n ; j++){
            arr[i][j] = -1;
        }
    }
    long long int ans = help(S , m , n , 0 , arr);
    for(int i = 0 ; i<=m ;i++){
        delete [] arr[i];
    }
    delete [] arr;
    return ans;
 }
 

//dp O(mn) space and  O(mn) time
int count_dp(int *arr , int n , int val){

    int **output = new int*[n+1];//row represet array size

    //columns will represent value
    for(int i = 0 ; i <= n ; i++){
        output[i] = new int[val+1];
    }
 
    //first row and col = 0

    for(int i = 0 ; i <= n ; i++){
        output[i][0] = 0; //col 0
    }

    for( int j = 0 ; j <= val ; j++){
        output[0][j] = 0;
    }

    //j represents diff values of val
    //i repesents size of aray from back
    for(int i = 1 ; i <= n ; i++){

        int index = n - i;
        for(int j = 1 ; j <= val ; j++)
        {
            int case1 = 0 , case2 = 0; //case on deals with smaller array and case w deals with when we add our elemnet

            case1 = output[i-1][j];

            if( arr[index] == j){  //if iits equal subtracting it will result to 0  , so our combination is 1
                case2 = 1;
            }else if( arr[index] < j ) { //we cant subtract from val if its larger as it will becooe a newgatve  monetary  amount
                case2 = output[i][j-arr[index]];
            } 
            output[i][j] = case1 + case2;
        }
    }


    int ans = output[n][val];
    for(int i = 0 ; i <= n  ; i++){
        delete [] output[i];
    }

    delete [] output;
    return ans;

}


int countWaysToMakeChange(int d[], int n, int v){

  /*  Don't write main().
   *  Don't read input, it is passed as function argument.
   *  Return output and don't print it.
   *  Taking input and printing output is handled automatically.
   */
    return count_dp (d , n , v);
    
    
}






//dp o(n) space  and O(mn) time
//refer sumeet malik vid
long long int coinChangeDP( int S[], int m, int n){

    int*arr = new int [n+1];
    for(int i = 0  ; i <= n ; i++){
        arr[i] =0;
    }
    arr[0] = 1 ;//numebr of ways to make 0 is 1

    //now we go one by one and fill arr for each number in S
    //arr[j] signifies number of ways to make j using denontions till S[i] , jab loop karneg neeche

    for(int i = 0  ; i < m ; i++)
    {
        for(int j = 1 ; j <= n ; j++){
            if(S[i] > j){
                continue;
            }
            arr[j]+= arr[j-S[i]];
        }
    }
    
    long long int ans = arr[n];
    delete [] arr;
    return ans;

}