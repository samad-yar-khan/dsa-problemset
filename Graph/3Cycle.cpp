/*
3 Cycle
Send Feedback
Given a graph with N vertices (numbered from 0 to N-1) and M undirected edges, then count the distinct 3-cycles in the graph. A 3-cycle PQR is a cycle in which (P,Q), (Q,R) and (R,P) are connected by an edge.
Input Format :
The first line of input contains two space separated integers, that denotes the value of N and M.
Each of the following M lines contain two integers, that denote the vertices which have an undirected edge between them. Let us denote the two vertices with the symbol u and v. 
Output Format :
Print the count the number of 3-cycles in the given graph
Constraints :
0 <= N <= 100
0 <= M <= (N*(N-1))/2
0 <= u <= N - 1
0 <= v <= N - 1
Time Limit: 1 sec
Sample Input 1:
3 3
0 1
1 2
2 0
Sample Output 1:
1
*/

/*
int solve(int n,int m,vector<int>u,vector<int>v)
{
    //reprsent these edges using and eadjcency matrix on a amap

    int**edges = new int*[n];
    for(int i = 0 ; i < n ; i++){
        edges[i] = new int[n];
        for(int j = 0 ; j < n ; j++){
            edges [i][j] = 0 ; //no connectons till now
        }
    }

    for(int i = 0 ; i < m ; i++){
        int x = u[i]-1;
        int y = v[i]-1;//becais our marix indexing stars from zero but our elments are from 1 to N

        edges[x][y] = 1;
        edges[y][x] = 1;
    }

    int ans = 0 ;
    for(int i = 0 ; i < n ; i++){

        for(int j = 0 ; j < n ; j++){

            if(i!=j && edges[i][j]==1){
                 for(int k =0 ; k < n ; k++){

                    if(j!=k && j!=i &&edges[j][k]==1){
                         
                         if(edges[k][i]==1 && k!=i){

                             ans++;

                         }

                    }

                }
            }
           
        }
    }
	
    ans/=6;

	for(int i = 0 ; i < n ; i++ ){
		delete [ ] edges [i];
	}
	delete [ ]edges ;
	return ans;
}

*/

#include<bits/stdc++.h>
using namespace std;

int main(){

    int M = 0 ;
    int N = 0 ;

    cin>>M>>N;

    int **edges = new int*[M];
    for(int i = 0 ; i < M; i++){
        edges[i] = new int[M];
        for(int j = 0 ; j < M ; j++){
            edges[i][j] = 0;
        }
    }

    for(int i = 0 ; i<N ; i++){
        int x = 0;
        int y =0;
        cin>>x>>y;
        edges[x][y] = 1;
        edges[y][x] = 1;
    }

   
    int ans = 0 ;
  
    for(int i = 0 ; i< M ;i++){

        for(int j = 0 ; j < M ; j++){

            if(j == i || edges[i][j] == 0){
                continue;
            }

            for(int k = 0 ;k  < M ; k++ ){
                   if(j == k || k == i||edges[k][j] == 0){
                        continue;
                    }

                    if(edges[i][k] == 1){
                        ans++;
                    }


            }
        }
    }
    cout<<ans/6<<"\n";

for(int i = 0 ; i < M; i++){
        delete [] edges[i];

        
    }
    delete [] edges;
}


