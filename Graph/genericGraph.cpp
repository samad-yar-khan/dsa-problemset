#include<bits/stdc++.h>
using namespace std;

class Graph{

    private:

        int V;
        unordered_map<string , list<pair<string , int>>> edges;
    
    public:
    Graph(int V) {
        this->V = V;
    }

    void insertEdge(string src , string dest , int wt){

        edges[src].push_back({dest,wt});
        edges[dest].push_back(make_pair(src,wt));

    }

    void printGraph(){
        for(unordered_map<string ,list<pair<string ,int>>>::iterator itr = edges.begin() ; itr != edges.end() ; itr++ ){
            cout<<itr->first<<" -> ";
            for(auto itr2 = itr->second.begin() ; itr2 != itr->second.end() ; itr2++){
                cout<<"--"<<itr2->second<<"--"<<itr2->first<<"-->";
            }
            cout<<"\n";
        }
    }



    
};

int main(){
  
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r" , stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    int N=0;
    cin>>N;
    Graph G(N);
    while(N--){
        string src{""},des{""};
        int wt;
        cin>>src>>des>>wt;
        G.insertEdge(src ,des , wt);
    }

    cout<<"Graph \n";
    G.printGraph();



}

//input 
//5

// delhi kolkata 5
// kolkata mumbai 7
// delhi meerut 10
// meerut mbd 1
// mbd delhi 2

// /