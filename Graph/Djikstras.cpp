#include<bits/stdc++.h>
using namespace std;


vector<int> Djikstra(vector<vector<pair<int, int>>> edges , int V , int E , int sv);

int main()
{

    int E = 0 , V = 0;
    cin>>V>>E;
    vector<pair<int , int>> emptyRow;
    vector<vector<pair<int , int>>> edges(V , emptyRow);


    for(int i =0 ; i < E ; i++){

        int V1 = 0 , V2=0 ,Wt = 0 ;
        cin>>V1>>V2>>Wt;

        pair<int, int> node1(V2,Wt);
        pair<int, int> node2(V1,Wt);

        edges[V1].push_back(node1);
        edges[V2].push_back(node2);

    }
    int startingVertex=0;
    cin>>startingVertex;
    vector<int> ans = Djikstra(edges , V ,E , startingVertex);
    for (int i = 0 ;i< V ; i++){
        cout<<i<<" "<<ans[i]<<"\n";
    }
    

}

vector<int> Djikstra(vector<vector<pair<int, int>>> edges , int V , int E , int sv){

    vector<int> distances(V , INT_MAX);
    vector<bool> visited(V , false);
    distances[sv] = 0 ;//sv has distance 0;
    for(int i = 0 ; i < V ; i++){

        int minDistance = INT_MAX;
        int closestNode = -1;
        for(int j = 0; j< V ;j++){
            if(!visited[j] && minDistance > distances[j]){
                closestNode=j;
                minDistance=distances[j];
            }
        }

        //go to all unvisted neioghbours of our ndoe and se eif gfoing to the neigbour via us would be much m more beneficial or not
        visited[closestNode] = true;
        for(int j = 0 ; j < edges[closestNode].size() ; j++){
            int neighbour = edges[closestNode][j].first;
            int edgeLen = edges[closestNode][j].second;
              if(visited[neighbour]){
                    continue;
                }
            int distance = edgeLen + distances[closestNode];
            if(distance < distances[neighbour]){
                distances[neighbour] = distance;
            }

        }

    }
    return distances;



}


//using adjacency matrix
/*
void Djikstra(int **edges , int V);

int main()
{

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

    Djikstra(edges , V);

    for(int i = 0 ; i<V ; i++){
        delete [] edges [i];
    }
    delete [] edges ;
	return 0;
}

void Djikstra(int **edges , int V){
	
    int*distances = new int[V];
    bool *visited = new bool[V];
    for(int i = 0; i < V ; i++){
        distances[i] = INT_MAX;
        visited[i] = false;
    }
    
    
    distances[0] = 0 ;//sv has distance 0;
    for(int i = 0 ; i < V ; i++){

        int minDistance = INT_MAX;
        int closestNode = -1;
        for(int j = 0; j< V ;j++){
            if(!visited[j] && minDistance > distances[j]){
                closestNode=j;
                minDistance=distances[j];
            }
        }

        //go to all unvisted neioghbours of our ndoe and se eif gfoing to the neigbour via us would be much m more beneficial or not
        visited[closestNode] = true;
        for(int j = 0 ; j < V ; j++){
           
            if(visited[j]){
                continue;
            }
            
            if(edges[closestNode][j]!=0){
                 int D = distances[closestNode] + edges[closestNode][j];
                if(D<distances[j]){
                    distances[j] = D;
                }
            }
           

        }

    }
  	
    for(int i = 0 ; i < V ; i++){
        cout<< i << " " << distances[i]<<"\n";
    }



}
*/


/*
//old way i did in cn

#include <iostream>
#include <climits>
#include <queue>
using namespace std;


//change to vector of vector of pais
//my negbouring nodes would be connected to each other and my vertex using ths class
class node {
    public:
    int wt;
    int vertex ;
    node* next;

    node(){
        wt = 0 ;
        vertex = 0;
        next = NULL;
    }

    node(int vertex , int wt , node* next = NULL){
        this->wt = wt ;
        this->vertex = vertex;
        this->next = next;
    }

    ~node(){
        delete next;
    }

};

void add_node(node**heads , node** tails , int x , int y  , int wt){

    if(heads[x] == NULL ){
        heads[x] = new node(y,wt);
        tails[x] = heads[x];
    }else{
        tails[x]->next = new node(y,wt);
        tails[x] = tails[x]->next;
    }

    if(heads[y] == NULL){
        heads[y] = new node(x , wt);
        tails[y] = heads[y];
    }else{
        tails[y]->next = new node(x,wt);
        tails[y] = tails[y]->next;
    }
}

class compare{

    public:
    bool operator() (pair<int,int> v1 , pair<int,int>v2){
        return v1.second>v2.second;
    }
};

void   Djaktras(node**head,node**tail,int V ,int E){

    //cout<<"DJAKSTRAS ALGO FOUND THE MIN DISTANCE OF EACH VERTEX FROM SOURCE VRTEX 0 "<<endl;

    bool*visited = new bool [V]; //for viisted status
    pair<int , int>*distances =  new pair<int , int >[V]; //distabce from source

    //initilaise that none of the vertcs have been visited so  far and distance of all vertices to be infinitty
   
    //INITIALISER

    for(int i{0} ; i < V ; i++){
        visited[i] = false;
        distances[i].first = i;
        distances[i].second = INT_MAX;
    }

    //now we need to make 0 the source vertex ad calculate the distanc of each vertex from 0
    distances[0].second = 0 ;

    priority_queue<pair<int,int> , vector<pair<int,int>> , compare> pending;

    pending.push(distances[0]);

    for(int i{0} ; i < V ; i++){
        
        //since we have different distaces of same vertex , it may happene that a same vertex i spopped again

        pair<int , int > min_vertex = pending.top();
        pending.pop();
        int my_vertex = min_vertex.first;

        while(visited[my_vertex]){
            min_vertex = pending.top();
            pending.pop();
            my_vertex = min_vertex.first;
        }

        visited[my_vertex] = true;

        node*neighbours = head [my_vertex];

        while(neighbours!=NULL){

            int neighbour = neighbours->vertex;
            // if(visited[neighbour]){
            //     neighbours = neighbours->next; //i had in initially missed this step . If our neigbour is visted , we need to go to the next before we hit a continue statement
            //     continue;                      // else we run into an infinite loop
            // }
            // int edge_length = neighbours->wt;
            // int distance_through_me = distances[my_vertex].second + edge_length;
            // if(distances[neighbour].second > distance_through_me){
            //     distances[neighbour].second = distance_through_me;
            //     pending.push(distances[neighbour]); //even if its a copy , we will get the min distance at top
            // }
            if(!visited[neighbour]){
                int edge_length = neighbours->wt ;
                int my_distance = edge_length + distances[my_vertex].second;
                if(distances[neighbour].second > my_distance){
                    distances[neighbour].second = my_distance;
                    pending.push(distances[neighbour]);
                }
            }
            neighbours = neighbours->next;
        } 

    }

    for(int i{0} ; i<V ; i++){
        cout<<i<<" "<<distances[i].second<<endl;
    }


}


int main()
{
    int V{0}, E{0};
    // cout <<"Ente the number of vertices and edges for your weighted graph : ";
    cin >> V >> E;

    //adjacency list
    node** head = new node*[V]; //adjacency list
    node** tail = new node*[V];
    for(int i = 0 ; i < V ; i ++)
    {
        head[i]  = NULL;
        tail[i] = NULL;
    }
    
    //input
    // cout<<"Enter all the "<<E<<" edges followed by their weight "<<endl;
    for(int i {0} ; i < E ; i++ ){

    int x=0 ,  y=0 ,  wt= 0;
    
    cin>>x>>y>>wt;
    
    add_node(head , tail ,  x , y , wt);
    
    }

    Djaktras(head,tail, V , E);
    // for(int i{0} ; i < V ; i++){
    //     cout<<i<<"---";
    //     node*my_head = head[i];
    //     while(my_head!=NULL){
    //         cout<<i<<" "<<my_head->vertex<<" "<<my_head->wt<<endl;
    //         my_head=my_head->next;
    //     }
    //     cout<<endl;
    // }
    //

    for(int i = 0 ; i < V ; i++){
        delete head[i];
    }
    delete[] head;
    delete[] tail ;
    return 0;
}
*/


