#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

//space O(n) , time O(n^2) 
long long countPairs_brute(int X[], int Y[], int M, int N)
{
    //Your code here
    double *arrX = new double[M];
    double *arrY = new double[N];
    for(int i = 0 ; i < M ; i++){

        arrX[i] = (double)log(X[i])/(double)X[i] ;

    }

    for(int i = 0 ; i < N ; i++){

        arrY[i] = (double)log(Y[i])/(double)Y[i] ;

    }   

    long long count{0} ;

    for(int i = 0 ; i < M  ; i++){

        for(int j{0} ; j < N ; j++){
            if(arrX[i] > arrY[j]){
                count++;
            }
        }
    }

    delete [] arrX;
    delete [] arrY;
    return count;

}

//logic 
//pow(x,y) > pow (y,x) for x < y
//edge case
//1)for y = 0 , it ll be oppsite for all non zero xs
//2)for y = 1 , it ll be opposite for all xs more than 1 
//3)2^3 < 3^2
//4)2^4 == 4^2  

//space O(1) , time O(n) 
long long countPairs(int X[], int Y[], int M, int N){
  
    //Sort the arrays
    sort(X , X+M);
    sort(Y , Y+N);
    
    //count frequency for pairs
    long long count{0};
    
    //we count frquency of 0,1,2,3,4 from arrayY as our edge cases comrise of them
    int freq[5]{0};
    for(int i = 0 ; i < N ; i++){
        if(Y[i]<5){
        freq[Y[i]]++;
        }
    }
    
    //we count zeros for Array X
    int zero_count {0};
    while(X[zero_count] == 0){
        zero_count++;
    }

    int i = 0 , j = 0 ;

    //iterate till the 1's get over 
    while(i<M && X[i] <= 1){
        i++;
    }
    //our lofic works after 4 as that it where our specias cases witll end 
    //move past the edge cases as we ll handle x->0-3 and y->0-4
    while(j<N && Y[j] <= 4){
        j++;
    }
    
    //count when y is 0
    count += (M-zero_count)*freq[0];
    //count for when y is 1;
    count += (M-i)*freq[1];
    //count 1;
    int first2_index = i;
    
    int freq2X{0} , freq3X{0};
   while(X[i] <= 3){
       if(X[i] == 2){
           freq2X++;
       }
       if(X[i] == 3){
           freq3X++;
       }
       
        i++;
    }
    
    //we take the case where x = 2 ans y  = 2,4 
    //2 for the edge case and 4 for convenince 
    count += freq3X*(freq[2] + freq[4]);//special cases handled
    //we got back to where 2s start
    i = first2_index; //back to 2
    

    while( i < M && j <N){
    
        if(X[i] >= Y[j]){
            j++;
        }else{
            count += (N-j);    
            i++;
        }

    }

    return count;

}

int main(){

    int M{0} , N{0};
    cin>>M>>N;

    int *X = new int[M];
    int* Y = new int[N];

    cout<<"ARRX\n";
    for(int i = 0 ; i < M ; i++){

        cin>>X[i];

    }

    for(int i = 0 ; i < N ; i++){

        cin>>Y[i];

    }

    long long ans = countPairs(X,Y,M,N);

    cout<<ans<<'\n';

    delete [] X;
    delete [] Y;

}