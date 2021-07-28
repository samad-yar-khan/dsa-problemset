#include<bits/stdc++.h>
using namespace std;

void isConnected(int**edges , int V){

    bool*visited = new bool [V];

    //bfs
    queue<int> perndingVertices;
    perndingVertices.push(0);
    visited[0] = true;
    
    while(!perndingVertices.empty()){

        int topV = perndingVertices.front();
        perndingVertices.pop();

        for(int i = 0; i< V ; i++){
            if(i == V || visited[i]){
                continue;
            }

            if(edges[i][topV] == 1){
                perndingVertices.push(i);
                visited[i] = true;
            }
        }

    }

    bool ans = true;

    for(int i = 0 ; i< V ;i++){
        ans = ans&&visited[i];
    }

    delete [] visited ;
    if(ans){
        cout<<"true\n";
    }else{
        cout<<"false\n";
    }

}

int main(){

    int V = 0 , E = 0 ;
    cout<<"Enter num vertices and edges : ";
    cin>>V>>E;
    int**edges = new int*[V];
    for(int i = 0 ; i < V ; i++){
        edges[i] = new int[V];
        for(int j = 0 ; j < V ; j++){
            edges[i][j] = 0;
        }
    }

    cout<<"Enter Edges :\n";
    for(int i = 0 ; i < E ; i++){
        int x = 0 , y = 0 ;
        cin>>x>>y;
        edges[x][y] = 1 ;
        edges[y][x] = 1;
    }

    isConnected(edges , V );

    for(int i = 0 ; i< V ; i++){
        delete [] edges[i];
    }

    delete [] edges ;

}