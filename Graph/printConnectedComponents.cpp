#include<bits/stdc++.h>
using namespace std;

/*
V = 0 - N
compomnt 1 0,1,2,4 
compomnt 2  3,5,6
compnt 3  7,8

visited -[1 ,2, 4 , 0]

iterate(i = 0 to 8){
    if(i!viietd ){
        dfs(i)
    }
}
1-2-3-1  
5-6-4-*5
*/



void dfs(int**edges , int V , bool* visited , int vertex , vector<int>& vec){
    visited[vertex ] = true;
    vec.push_back(vertex);
    for(int i = 0 ; i< V ; i++){
        if(visited[i] || i==V) {
			continue ;
        }   
        if(edges[vertex][i] == 1){
            dfs(edges , V , visited , i , vec);
        }
    }
}

void printConnected(int**edges , int V){

    bool *visited = new bool[V]{false};
    for(int i = 0 ; i< V ; i++){
        if(!visited[i]){
            vector<int> vec;
            dfs(edges , V , visited , i , vec);
            sort(vec.begin() , vec.end());
            for(auto j:vec){
                cout<<j<<" ";
            }
            cout<<"\n";
        }
    }
    delete[] visited;
}

int main(){

    int V = 0 , E = 0;  
    cin>>V>>E;
    if(V== 0){
        return 0;
    }
    int**edges = new int*[V];
    for(int i = 0 ; i < V ; i++){
        edges[i] = new int[V];
        for(int j = 0 ; j < V ; j++){
            edges[i][j] = 0;
        }
    }
    for(int i = 0 ; i < E ; i++){
        int x = 0 , y = 0 ;
        cin>>x>>y;
        edges[x][y] = 1 ;
        edges[y][x] = 1;
    }
    printConnected(edges , V );
    for(int i = 0 ; i< V ; i++){
        delete [] edges[i];
    }
    delete [] edges ;
}