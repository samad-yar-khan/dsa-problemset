#include<bits/stdc++.h>
using namespace std;

#include<bits/stdc++.h>
using namespace std;

void dfs(int **edge , bool* visited , int V , int starting_vertex){

    //mark visted 
 visited[starting_vertex] = true;
    cout<<starting_vertex<<"\n";

    for(int i = 0 ; i < V ; i++){
        if(!visited[i] && edge[starting_vertex][i] ==1 && i!=starting_vertex){
            dfs(edge , visited , V , i);
        }
    }

}

void bfs(int **edge , bool* visited , int V , int starting_vertex){

    //mark visted 
    visited[starting_vertex] = true;
    queue<int> pendingVertices ;
    pendingVertices.push(starting_vertex);

    while(pendingVertices.size() > 0){
       int currVertex = pendingVertices.front();
       pendingVertices.pop();
       cout<<currVertex<<"\n";

        for(int i = 0 ; i<V ; i++){
            if(edge[currVertex][i] == 1 && !visited[i] ){
                visited[i] = true;
                pendingVertices.push(i);
            }
        }


    }

}


void DFS(int **edges , int V){

    bool * visited= new  bool [V];
    for(int i = 0 ; i < V ; i++){
        visited[i] = false;
    }

    //call dfs on each noon visted node for disconncted grpah
    for(  int  i = 0  ; i < V ; i++){
        dfs(edges , visited , V , i);
    }

    delete [] visited;

}

void BFS(int **edges , int V){

    bool * visited= new  bool [V];
    for(int i = 0 ; i < V ; i++){
        visited[i] = false;
    }

    //call dfs on each noon visted node for disconncted grpah
    for(  int  i = 0  ; i < V ; i++){
        bfs(edges , visited , V , i);
    }

    delete [] visited;

}

int main(){

    int V = 0 , E= 0;
    cout<<"Number Vertices :";
    cin>>V;

    cout<<"Number edges : ";
    cin>>E;
    int**edge = new int*[V];
    for(int i = 0 ; i <  V  ; i++){
        edge[i] = new int [V];
        for(int j = 0  ; j < V ; j++){
            edge[i][j] = 0 ; //no edges between i and j
        }
    }

    cout<<"Enter edges : \n";
    
    for(int i = 0 ; i< E ; i++){
        int a = 0 ;
        int b =  0 ;
        cin>>a>>b;

        edge[a][b] = 1 ;
        edge[b][a] = 1 ;
    }

   
    BFS(edge , V);
    cout<<"----\n";
    DFS(edge , V);

    for(int i = 0  ; i < V  ; i++){
        delete [] edge[i];
    }

    delete [] edge ;

    return 0;

}
/*

7
8
0 1
0 2
1 3
1 4
2 6
3 5
4 5
5 6
0

*/
