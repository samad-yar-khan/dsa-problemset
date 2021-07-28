#include<bits/stdc++.h>
using namespace std;


//our lofic is to place pare thesis and imagine its as matrices
//so ek bar mai ham inhe do parts mai divide akrenge
/*
ex = M1*M2*M3*M4

then ,
    case1 = rec(M1)) + rec(M2*M3*M4) + multiplxtion needed  to multiply the resultant matrices;
    case2 = rec(M1*M2) + rec(M3*M4) +  multiplxtion needed  to multiply the resultant matrices; 
    case3 =rec(M1*M2*M3))  + rec(M4) + multiplxtion needed  to multiply the resultant matrices
    now we take min of these

*/
int matrixHelper(int i ,  int j , int*arr){
    
    //no multiplcation needed
    if( j - i <= 1){ //0 1 so either one matric or none
        return 0;
    }

    //is
    int minAns = INT_MAX;
    //here we jst put twwo brackets
    //(M1)(M2M3) or (M1M2)M3
    for(int x = i+1 ; x < j ; x++){

        int leftAns = matrixHelper(i , x , arr);
        int rightAns = matrixHelper(x , j , arr);
        int ourMultiplications = leftAns + rightAns + (arr[i]*arr[x]*arr[j]);

        minAns = min(minAns , ourMultiplications);

    }

    return minAns;


}


int matrixMultiplication(int N, int arr[])
{        // code here
        return (matrixHelper(0 , N-1 , arr));

}

//memoization
int matrixHelper2(int i ,  int j , int*arr , int dp[101][101]){
    
    //no multiplcation needed
    if( j - i <= 1){ //0 1 so either one matric or none
        return 0;
    }
    
    //chek if we have alrwady have an ans for this multiplication
    if(dp[i][j]!=-1){
        return dp[i][j];
    }

    //is
    int minAns = INT_MAX;
    //here we jst put twwo brackets
    //(M1)(M2M3) or (M1M2)M3
    for(int x = i+1 ; x < j ; x++){

        int leftAns = matrixHelper2(i , x , arr , dp);
        int rightAns = matrixHelper2(x , j , arr , dp);
        int ourMultiplications = leftAns + rightAns + (arr[i]*arr[x]*arr[j]);

        minAns = min(minAns , ourMultiplications);

    }

    dp[i][j] = minAns;
    return dp[i][j];


}


int matrixMultiplication2(int N, int arr[])
{        // code here
        int dp[101][101] ;
        for(int i = 0 ; i <= N ; i++){
           
            for(int j = 0; j <=N; j++){
                dp[i][j] = -1;
            }
        }
        int ans = (matrixHelper2(0 , N-1 , arr , dp));
      
        return ans;
}

//if we have 4 matrices then their row and col sizes are reprsnted by and array of size 5
// 0  1  2  3   4
//[20,30,40,30,50]

//so fo (0,4) we make calls in follwoing manner 
// - 1 -> 
// (0,1) &(1,4)
//2 -> (0,2) & (2,4)
//3 -> (0,3) & (3,4) and we follow same logic of miniming 
//now ,for any cell x,y , for taking a certain k size array from the left (i+1<=k<y)we need once cell to the left of it -> (i,k) where  k < j 
//and one cell below it (k , j) , hence we start filling from the bottom , and from right to left so we havve all the ans for al the req cells like dp 


int matrixDP (int N , int arr[]){

    int dp[101][101] ;

    for(int i = 0 ; i <= N ; i ++){
        for(int j = 0 ; j<=i ; j++){
            dp[i][j] = 0 ;
        }
    }

    //k will represent size
    for(int i = N ; i >= 0  ; i--){
        for(int j = 0 ; j < N ;j++){
            if(j-i<2){
                dp[i][j] = 0;
            }else{
                int ans = INT_MAX;
                for(int k = i+1 ; k< j ; k++ ){
                    ans  = min(dp[i][k] +  dp[k][j] + arr[i]*arr[k]*arr[j] , ans);
                }
                dp[i][j] = ans;

            }
        }
    }

    int ans = dp[0][N-1];
    return ans;

}