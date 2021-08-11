#include<bits/stdc++.h>
using namespace std;

void mstPrims(int **edges ,  int V  , int E);
int main(){

   
    int V = 0 , E= 0 ;
    cin>>V>>E;

    int**edges = new int*[V];
    for(int i = 0 ; i < V ;i++){
        edges[i] = new int[V];
        for(int j = 0 ; j < V ; j++){
            edges[i][j] = 0;
        }
    }

    for(int i =  0 ; i < E ; i++){
        int v1 = 0,v2 = 0 ;
        cin>>v1>>v2;
        int wt=0;
        cin>>wt;
        edges[v1][v2] = wt;
        edges[v2][v1] = wt;
    }

    mstPrims(edges , V, E);

    for(int i = 0 ; i<V ; i++){
        delete [] edges [i];
    }
    delete [] edges ;
}

void mstPrims(int **edges ,  int V  , int E){

    bool*visited = new bool[V];
     int *parent = new int [V];
      int*wt=new int [V];
    for(int i =0 ; i < V ; i++){
        visited[i] = false;
        wt[i] = INT_MAX;
        parent[i] = -1;
    }
    

    wt[0]=-1;

    
    int edgeCount = 0 ;

    while(edgeCount < V){

        int cw = INT_MAX;
        int minVertex = 0;
        //min non viisted vertex dhundo
        for(int i = 0 ; i < V ; i++){
            if(cw > wt[i] && !visited[i]){
                cw = wt[i];
                minVertex = i;
            }
        }
        //marks it visited;
        visited[minVertex] = true;
        //go through all its non visited vertex and makeour node its parent if wt through is less than its current wt

        //we gothrough all connected vertices from our nodea and if 
        //the wt of that node is mmorpe than wt through us then,make us its parent and update wt;
        for(int i = 0 ; i<V ; i++){
            if(!visited[i] && edges[minVertex][i] != 0){
                if(edges[minVertex][i] < wt[i]){
                    wt[i] =  edges[minVertex][i] ;
                    parent[i] = minVertex;
                }
            }
        }   

        edgeCount++;

    }

    //print all nodes
    for(int i = 1 ; i < V ; i++){
        int node = i;
        int ourParent = parent[i];
        int weight = wt[i];

        cout<<min(ourParent,node)<<" "<<max(ourParent,node)<<" "<<weight<<"\n";

    }

    delete [] wt;
    delete [] parent;
    delete [] visited;

}   




// int next_vertex (bool*visited , int * weight , int V){

//     int min_vertex = -1 ;
//     int min_vertex_weight = INT_MAX;
//     for(int i {0} ; i < V ; i++){
//         if(!visited[i] && min_vertex_weight> weight[i]){
//             min_vertex=i;
//             min_vertex_weight = weight[i];
//         }
//     }

//     return min_vertex;
// }

// void prime(int**edges , int V , int E){

//     bool *visited = new bool[V];
//     int *parent = new int[V];
//     int * weight = new int[V];

//     for(int i{0} ; i < V ; i++){
//         visited[i] = false;
//         weight [i] = INT_MAX; //infinite weight initially
//     } 

//     //mark zero as source
//     weight[0] = 0 ;
//     parent[0] = -1 ;

//     //we ll max visit all v vertices so only v iteation are needed

//     for(int i{0} ; i < V ; i++){

//         int min_vertex = next_vertex(visited , weight , V);
//         visited[min_vertex] = true;
//         for(int j{0} ; j < V ; j++){

//             if(!visited[j] && edges[min_vertex][j]!=0 ){

//                 if(edges[min_vertex][j] < weight[j]){
//                     parent[j] = min_vertex;
//                     weight[j] = edges[min_vertex][j];
//                 }
//             }
//         }
//     }

//     for(int i = 1 ; i < V ; i++){

//         if(i < parent[i]){
//             cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
//         }else{
//             cout<<parent[i]<<" "<<i<<" "<<weight[i]<<endl;
//         }
//     }


// }

// int main()
// {
//     int V, E;
//     cin >> V >> E;

//     //adjacencys matrix
//     int**edges = new int*[V];
//     for(int i {0} ; i <V ; i++){
//         edges[i]  = new int[V];
//         for(int j = 0 ; j < V ; j++){
//             edges[i][j] = 0 ;
//         }
//     } 

//     for(int i{0} ; i < E ; i++){
//         int x = 0 , y = 0 , wt = 0 ;
//         cin>>x>>y>>wt;

//         edges[x][y] = wt;
//         edges[y][x] = wt;
//     }

//     prime(edges , V , E );

//     return 0;
// }

