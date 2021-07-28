#include<bits/stdc++.h>
using namespace std;

bool DFS_path(int**edges , int V , int v1 , int v2 , bool* visited){

    visited[v1] = true;
    if(v1 == v2){
        cout<<v1<<" ";
        return true;
    }

    //look for the node
    for(int i = 0 ; i < V ; i++){
        if(visited[i] == true  || i == v1){
            continue;
        }
        if(edges[v1][i] == 1){
            bool found = DFS_path(edges , V , i , v2 , visited);
            if(found){
                cout<<v1<<" ";
                return true;
            }
        }
    }

    return false;

}

void get_path(int**edges , int V , int v1  , int v2){

    bool*visited = new  bool[V]{false};

    delete [] visited;
}

int main(){

     int V = 0 , E = 0 ;
    cin >> V >> E;

    //adjacency matrix
    int** edges = new int* [V];
    for(int i = 0 ; i < V ; i ++){
        edges [i] = new int[V];
        for(int j = 0 ; j < V ; j++ ){
            edges [i][j] = 0 ;
        }
    }

    //setting the edges
    for(int i{0} ; i < E ; i++){

        int x = 0 , y = 0 ;
        cin>>x>>y;

        edges[x][y] = 1;
        edges[y][x] = 1;
    }

    int vertex_1 = 0 , vertex_2 = 0 ;
    cin>>vertex_1>>vertex_2;

    get_path(edges , V , vertex_1 , vertex_2);
    
    for(int i = 0 ; i < V ; i++){
        delete [] edges[i];
    }
    delete [] edges;


    return 0;
}