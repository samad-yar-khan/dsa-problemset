#include<bits/stdc++.h>
using namespace std;


/*
#include <iostream>
#include<queue>
using namespace std;

//forward declarations
bool has_path_DFS( int** edges , int N , int vertex_1 , int vertex_2  , bool* visited ){

  //base
  visited[vertex_1] = true;
  
  if(vertex_1 == vertex_2 ){
    return true;
  }

  for(int i = 0 ; i < N ; i++){

    if(visited[i] || i == vertex_1 ){
      continue;
    }

    if(edges[vertex_1][i] == 1){
      bool ans = has_path_DFS(edges , N , i , vertex_2 , visited);
      if(ans){
        return ans;
      }
    }

  }

  return false;
 
}

bool path_exists_DFS(int** edges , int N , int vertex_1 , int vertex_2 ){

  bool* visited = new bool[N];
  for(int i{0} ; i < N ; i++){
    visited[i] = false;
  }

  bool ans  = has_path_DFS(edges  , N , vertex_1 , vertex_2 , visited);

  delete [] visited;
  return ans;

}


bool path_exists(int** edges , int N , int vertex_1 , int vertex_2  );
bool has_path( int** edges , int N , int vertex_1 , int vertex_2  , bool* visited );

int main() {
  
  int V, E;
  cin >> V >> E;
  //adjacency matrix 
  int** edges = new int*[V];
  for(int i = 0 ; i < V ; i++){

    edges[i] = new int[V];
    //initialising the adjacency matric to represneted that all oouor verices are disconnected at first
    for(int j = 0 ; j < V ; j++ ){
      edges[i][j] = 0 ;
    }

  }

  //edges input 
  for(int i {0} ; i < E ; i++ ){

    int x = 0 , y = 0;
    cin>>x>>y;

    //if x is connexcted y , then y is also connected to x
    edges[x][y] = 1 ;
    edges[y][x] = 1 ;

  }

  //vertices whose connection needs to be checked
  int vertex_1 = 0  ,  vertex_2 = 0 ;
  cin>>vertex_1>>vertex_2;
	
  cout<<boolalpha;
  cout<<path_exists(edges,V,vertex_1,vertex_2);

  return 0;
}

bool path_exists(int** edges , int N , int vertex_1 , int vertex_2  ){

  bool* visited = new bool [N];
  for(int i{0} ; i < N ; i++ ){
    visited [i] = false;
  }
  bool ans = has_path(edges , N , vertex_1 , vertex_2 , visited);
  delete [] visited;
  return ans;
}

bool has_path( int** edges , int N , int vertex_1 , int vertex_2  , bool* visited ){

  queue<int> pending_vertices ;
  pending_vertices.push(vertex_1);
  visited[vertex_1] = true;

  while (!pending_vertices.empty())
  {
    
    int current_vertex = pending_vertices.front();
    pending_vertices.pop();

    for(int i = 0 ; i < N ; i++ ){

        if(current_vertex == i || visited[i]){
          continue;
        }

        //if my current vertex and i have a edge connectng em , i ll check if vetex i is vertex2 or not
        if(edges[current_vertex][i] == 1){

          if( i == vertex_2){
            visited[i] = true ;
            return true ;
          }else{
            visited[i] = true ;
            pending_vertices.push(i);
          }

        }

    }

    //if we havent found vertex 2  by this pt then its not there 
    
  }
  return false;
}
*/

// we go in dfs fahion to all our paths and then as soon as we reach our target node
//our satrting and eeding elemnt beocome sae

bool hasPathBFS(int** edges , int V , bool* visited , int si  , int ei){

    queue<int> pn;
    pn.push(si);
    visited[si] = true;

    while(pn.size() > 0){
        int ourNode = pn.front();
        pn.pop();

        if(ourNode==ei){
            return true;
        }

        for(int i = 0 ; i<V ; i++){
            if(visited[i]){
                continue;
            }

            if(edges[ourNode][i] ==1 ){
                visited[i] = true;
                pn.push(i);
            }
        }

    }
    return false;

}

bool hasPath(int** edges , int V , bool* visited , int si  , int ei){
    visited[si] = true; 	
    if(si == ei){
        return true ;
    }
    
    for(int i = 0 ; i < V ; i++){
       if(visited[i] == true || i == si){
           continue;
       }
        
        if(edges[si][i] == 1){
          
            bool found = hasPath(edges , V ,  visited , i , ei);
            
            if(found){
                return true;
            }
        }
    }
    
    return false;
    
}


int main() {
    // Write your code here
    int V = 0 , E=0;
    
    cin>>V>>E;
    
    int**edges = new int*[V];
    for(int i = 0 ; i<V ; i++){
        edges[i] = new int[V];
        for(int j = 0  ; j< V ; j++){
            edges[i][j] = 0;
        }
    }
    
    
    for(int i = 0 ; i < E ; i++){
        int x = 0 ,  y =0 ;
        cin>>x>>y ;
		edges[x][y] = 1;
        edges[y][x] = 1 ;
    }
    
    int startingIndex = 0 ;
    int endingIndex = 0;
    cin>>startingIndex>>endingIndex;
	
    bool *visited = new bool[V];
        for(int i = 0 ; i< V ; i++){
            visited[i] = false;;
        }
    
    
    bool ans = hasPath (edges , V , visited , startingIndex , endingIndex);
    
    
    for(int  i = 0  ;i< V ; i++){
        delete [] edges[i];
    }
    delete [] visited ;
    
    delete [] edges ;
if(ans){
    cout<<"true"<<"\n";
}else{
        cout<<"false"<<"\n";
}
    return 0;
}