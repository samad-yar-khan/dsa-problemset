
#include<iostream>
#include<cmath>
#include<vector>
#define ll long long
using namespace std;

    int findWays (int n, int m, int**mat , int i , int j){
        //bc
        if(i == n && j == m ){
            return 1;
        }
        //edge case
        if(i >n || j >m){
            return 0;
        }
        //is
        if(mat[i][j] == 1){
            return 0;
        }
        
        //ih
        int r = 0;
        int l = 0;

        if(j < m )
        {
             r =  findWays (n,  m, mat ,  i ,  j+1);
        }

        if( i < n){
               l = findWays (n,  m, mat ,  i+1 ,  j);
        }

     
        
        return  r + l;
        
        
    }
    
	int FindWays(int n, int m, vector<vector<int>>blocked_cells ){
	    // Code here
	       
	int ** mat = new int*[n];
	for(int i = 0 ;i < n ; i++){
	        
	       mat[i] = new int[m];
	       for(int j = 0 ; j < m ; j++){
	           mat[i][j] = 1;
	       }
	    
	}
	
	for(int i = 0 ;i < blocked_cells.size(); i++){
	    int a = blocked_cells[i][0] - 1;
	     int b = blocked_cells[i][1] - 1;
	     
	     mat[a][b] = 0;
	}
	
	
		for(int i = 0 ;i < n ; i++){
	        
	      
	       for(int j = 0 ; j < m ; j++){
	           cout<<mat[i][j];
	       }
	       cout<<"\n";
	    
	}
	    
	   int ans = findWays(n-1,m-1,mat,0,0);
	   for(int i = 0 ;i < n ; i++){
	        
	       delete [] mat[i];
	     
	    }
	    
	    delete [] mat;
	    return ans;
	    
	    
	}

    int main(){

        int n = 0 , m= 0 , k = 0 ;
        cin>>n>>m>>k;

        vector<vector<int>> vec(k);
        for(int i = 0 ; i < k ; i++){
            for(int j = 0 ; j < 2 ; j++){
                int a = 0 ;
                cin>>a;
                vec[i].push_back(a);
            }
        }

        cout<<FindWays(n,m ,vec);

    }