#include<bits/stdc++.h>
using namespace std;

/*
Go through the node in dfs fashion adn if
you found the source throuh your path
hen print your node
*/
//we do same like bfs but to ttrace the pathhw e must know who inseted a particilar node in the queue

bool BFS_path(int**edges , int V , int v1 , int v2 , bool* visited){

    queue<int> pendingVertices ;
    unordered_map<int , int> parent;
vector<int> path;
    pendingVertices.push(v1);
    visited[v1] = true;

    while(!pendingVertices.empty()){

        int topV = pendingVertices.front();
        pendingVertices.pop();

        if(topV == v2){
       		int curr = v2;
            path.push_back(v2);
            while(curr!=v1){
                curr = parent[curr];
                path.push_back(curr);
            }
                    break;
        }
        
        for(int i = 0 ; i < V ; i++){
            if(topV==i || visited[i]){
                continue;
            }
            
            if(edges[topV][i] == 1){
                visited[i] = true;
                parent[i] = topV;
                pendingVertices.push(i);
            }
        }

    }
    
    for(auto i : path){
        cout<<i<<" ";
    }



 
}

void get_path(int**edges , int V , int v1  , int v2){

    bool*visited = new  bool[V]{false};
    BFS_path(edges , V , v1 , v2 , visited);

    delete [] visited;
}

int main()
{
    int V, E ;

    cin>>V>>E;

    //adjacency matrix
    int**edges = new int*[V];
    for(int i{0} ; i < V ; i++ ){
        edges[i] = new int[V];
        for(int j{0} ; j < V ; j++){
            edges[i][j] = 0; //no connections establshes
        }
    } 

    for(int i{0} ; i < E ; i++){
        int x = 0 , y = 0 ;
        cin>>x>>y;
        edges[x][y] = 1;
        edges[y][x] = 1;
    }

    //v1 and v2 are the pertices , the path bw these vertices are needed 
    int v1= 0 , v2 = 0 ;
    cin>>v1>>v2;
    get_path(edges,V,v1,v2);


    for(int i = 0 ; i<V ; i++){
        delete  [] edges[i];
    }
    delete [] edges ;

    return 0;
}

