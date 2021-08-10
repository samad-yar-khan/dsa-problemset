#include<iostream>
#include<algorithm>
using namespace std;

// class edges {

//     public:
//     int source;
//     int destination;
//     int weight;

//     edges(){
//         source = 0 ;
//         destination = 0 ;
//         weight = 0 ; 
//     }



// };

// //comparator function
// bool compare_weights(edges e1 , edges e2){
//     return e1.weight<e2.weight;
// }

// //this function basicaly returns the parents of a vertex in the mst
// int parents(int v , int*parent ){

//     int v_i = v;
//     int k = parent[v_i];
//     while(k!=v_i){
//         v_i = k;
//         k=parent[v_i];
//     }
//     return k;
// }

// int main()
// {
//   int V=0, E=0;
//   cin >> V >> E;

//     edges * input = new edges[E];
//     for(int i{0} ; i < E ; i++){
//         int x=0 , y= 0  ,z=0 ;
//         cin>>x>>y>>z;

//         input[i].source = min(x,y);
//         input[i].destination = max(x,y);
//         input[i].weight = z;
//     }
//       //now iknow all my edges 
//     //what we need to do is sort these edges based on wts

//     //this uses a comparator fucnc to sort the edges according to wts
//     sort(input , input+E , compare_weights);

//     edges *MST = new edges[V-1];
    
//     int* parent = new int[V];
//     for(int i{0} ; i < V ; i++){
//         parent[i]  = i ; //eacch is its owen parents at first
//     }

//     int count = 0 ;
//     int i = 0 ;

//     while(count < V-1){

//         int V1 = input[i].source;
//         int V2 = input[i].destination;
//         int P1 = parents(V1,parent);
//         int P2 = parents(V2,parent);

//         if(P1 == P2){
//             i++;
//             continue; //if parents are same we sip this dhe
//         }

//         MST[count] = input[i]; //this is the copy contruor and copies this edge onto our 
//         parent[P1] = P2; //because P1 is the top most parenst such that P1 is is own parent
//         count++;
//         i++;

//     }

//     for(int i{0} ; i < V-1 ; i++){
//         cout<<MST[i].source<<" "<<MST[i].destination<<" "<<MST[i].weight<<endl;
//     }
//     delete[] MST;
//     delete[] input ;
//     delete[] parent;
//     return 0;
// }

class edge{
    public :

        int source;
        int destination;
        int weight ;

        edge(){
            this->source = 0;
            this->destination = 0 ;
            this->weight = 0 ;
        }

        edge(int source , int destination , int weight){
            this ->source = source;
            this ->destination = destination;
            this->weight = weight;
        }

      
        
        
};  

bool compare(edge e1 , edge e2){
    return e1.weight < e2.weight;
}

int getParent(int vertex , int *parents ){

    int v = vertex;
    while(parents[v] != v){//while i dont become my own parents , becaus ethen i will be teh root parents
        v = parents[v];
    }
    return v;
}


void kruskel_MST(edge* edges , int  n , int e ){
    
    //sort the edges by wt sowe can appply greey and choos the min edge each time
    sort(edges,edges+e , compare);

      //UNION FIND 
    //keep track of each certex parents to keep track of the components
    int *parents = new int[n];
    for(int i= 0 ; i < n ; i++){
        parents[i] = i; //each node its own parents  , n disjoint sets
    }

    //now i choose the min edges to add and if teh vertices mading up that edge dont belong to  thr sme componet or don =t havet= the same parent , then we just add them and we set the parents tree

    int edgesLeft = n-1;
    int itr = 0 ;

    edge*mst = new edge[n-1]; 

    while(edgesLeft){

        edge E = edges[itr];
        int parentSource = getParent(E.source, parents);
        int parentDestination = getParent(E.destination , parents);

        if(parentSource == parentDestination){
            itr++;
        }else{

            ///parents are not same spo the vertices dont lie on thr same componet hence this
            //wont lead to cycle  to add this to the mst
            int index = n-1-edgesLeft;
            mst[index]=E;
            edgesLeft--;
            //now we need to connect the parents dfo the parent tree an dto set cyclysation

            parents[parentDestination]=parentSource;

            itr++;
        }


    }


    for(int i = 0 ; i < n-1 ; i++){
        cout <<min(mst[i].source , mst[i].destination)<<" "<<max(mst[i].source , mst[i].destination)<<" "<<mst[i].weight<<"\n";
    }

    delete [] parents;
    delete [] mst;



}

int main(){
    
    int n = 0 ;
    int e = 0 ;
    cin>>n>>e;

    //each edge consit of a source destination and a wt
    edge*edges = new edge[e];

    for(int i = 0 ; i < e ; i++){
        int src = 0 ;
        int des = 0 ;
        int wt = 0 ;
        cin>>src>>des>>wt;
        edge E(src , des , wt);
        edges[i] = E;
    }

    
    kruskel_MST(edges,n,e);
   
    // for(int i = 0 ; i < e ; i++){
    //     cout <<edges[i].source<<" "<<edges[i].destination<<" "<<edges[i].weight<<"\n";
    // }




    delete [] edges;

}