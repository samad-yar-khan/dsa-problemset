#include<bits/stdc++.h>
using namespace std;



//we now , to chekc mirror tree we would hav created a whole tree , revers ethe tree , or compare inorddr of one tree with post porder og another tree an dof theey are same then trees are mirrors,
//but here we can just use a queue to store children of tree 1 and staxkc to stroe thr children of the otehr
//now one by one we pop out chilkren and by defualt due top teh stakc m the children are inverted
//the children inverted resulstbion inversion of tree b by default at each node levele and its smiliar to inverting a tree and making comparisions

 int checkMirrorTree(int n, int e, int A[], int B[]) {
       

    vector<stack<int>> t1(n+1);
    vector<queue<int>> t2(n+1);
  
    for(int i = 0; i<2*e ; i=i+2){
        
        t1[A[i]].push(A[i+1]);
        t2[B[i]].push(B[i+1]);

    }
    // cout<<t1[1].top()<<" "<<t2[1].front()<<"\n";
    for(int i =0 ;i<=n ; i++){

        if(t1[i].size()!=t2[i].size()){
            return 0;
        }

        while(t1[i].size()>0){
            if(t1[i].top()!=t2[i].front()){
                return 0;
            }

            t1[i].pop();
            t2[i].pop();
        }

    }

    return 1;


    //    map<int, vector<int>> graph1;
    //    map<int, vector<int>> graph2;
       
    //    for(int i =0; i < 2*e ; i+=2){
           
    //        graph1[A[i]].push_back(A[i+1]);
    //        graph2[B[i]].push_back(B[i+1]);
         
    //    }
       
    //    //reverse graph2 
    //    queue<int> pendingNodes;
    //    pendingNodes.push(graph2.begin()->first);
       
    //    while(pendingNodes.size() > 0){
    //        int topNodes = pendingNodes.front();
    //        pendingNodes.pop();
           
    //        //reverse all children and pop them in the the quue
    //        for(int i = 0 ;i<graph2[topNodes].size() ; i++){
    //            pendingNodes.push(graph2[topNodes].at(i));
    //        }
    //         reverse(graph2[topNodes].begin() ,graph2[topNodes].end());
           
    //    }
       
       
    //     auto itr1 = graph1.begin();
    //     auto itr2 = graph2.begin();
        
    //     while(itr1 != graph1.end() && itr2 != graph2.end() ){
            
    //         if(itr1->first != itr2->first){
    //             return 0;
    //         }
    //         if(itr1->second.size() != itr2->second.size()){
    //             return 0;
    //         }
            
    //         for(int i = 0 ; i<itr1->second.size()  ; i++){
    //             if(itr1->second.at(i) != itr2->second.at(i)){
    //                 return 0;
    //             }
    //         }
            
    //         itr1++;
    //         itr2++;
    //     }
        
    
    //     return 1;
       





        
    }

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r" , stdin);
        freopen("../output.txt", "w", stdout);
    #endif
   



    int n =0;int e=0;
    cin>>n>>e;
    int*arr1=new int[2*e];
    int*arr2=new int[2*e];

    for(int i =0;i<2*e ; i++){
        cin>>arr1[i];
    }

    for(int i =0;i<2*e ; i++){
        cin>>arr2[i];
    }

    cout<<checkMirrorTree(n,e,arr1,arr2);

    delete [] arr1;
    delete [] arr2;
}
