//https://practice.geeksforgeeks.org/problems/number-of-pairs-1587115620/1
#include<iostream>
using namespace std;

int TimeFresh(int**mat , int m , int n){

    int time = 1;
    bool trans{false};
    int total = 0;
    //check if transmission is even possible
    for( int i = 0 ; i < m ; i++){

            for(int j = 0 ; j < n ; j++){

                if(mat[i][j] == 2){

                    if(i<m-1 && mat[i+1][j] == 1){
                        
                        trans = true;
                    }
                    if(i>0 && mat[i-1][j] == 1){
                       
                        trans = true;

                    }
                    if(j<n-1 && mat[i][j+1] == 1){
                       
                        trans = true;

                    }
                    if(j>0 && mat[i][j-1]== 1){
                       
                        trans = true;
                    }
                }
            }

    }
    if(!trans){
        return -1;
    }

    //do all transmissions
    do{
        
        trans = false;
        
        for( int i = 0 ; i < m ; i++){

            for(int j = 0 ; j < n ; j++){

                if(mat[i][j] == 2){

                    if(i<m-1 && mat[i+1][j] == 1){
                        mat[i+1][j] = 3;
                        trans = true;
                    }
                    if(i>0 && mat[i-1][j] == 1){
                        mat[i-1][j] = 3;
                        trans = true;

                    }
                    if(j<n-1 && mat[i][j+1] == 1){
                        mat[i][j+1] = 3;
                        trans = true;

                    }
                    if(j>0 && mat[i][j-1]== 1){
                        mat[i][j-1] = 3;
                        trans = true;
                    }
                }
            }

        }
       
        for( int i = 0 ; i < m ; i++){

            for(int j = 0 ; j < n ; j++){

                if(mat[i][j] == 3){

                    mat[i][j] = 2;
                   
                }
            }

        }
  
        if(trans){
            time ++;
        }

 

    }while(trans);
    //see if all are rot
     for( int i = 0 ; i < m ; i++){

            for(int j = 0 ; j < n ; j++){

                if(mat[i][j] == 1){
                    return -1;
                }
            }

    }

    return time;

}

int main(){
    
    int m{0} , n{0};
    cin>>m>>n;

    int** mat = new int*[m];
    for(int i = 0 ; i < m ; i++){
        mat[i] = new int[n];
        for(int j = 0 ; j < n ; j++){
            cin>>mat[i][j];
        }
    }
    cout<<TimeFresh(mat , m, n);
    for(int i = 0 ; i < m ; i++){
        delete [] mat[i];  
    }
    delete [] mat;
    return 0;

}

