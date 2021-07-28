#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class triplet{

    public:
    int val;
    int index;
    int row;
    
    triplet(int val ,int index ,int row){
        this->val = val;
        this->index = index ;
        this->row = row;
    }
    triplet(){
        this->val = 0;
        this->index = 0 ;
        this->row = 0;
    }

};

class compare{

    public :

    bool operator()(triplet* a , triplet* b){
        return a->val > b->val;
    }

};

  vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {

        priority_queue<triplet* , vector<triplet*> , compare> pq;

            for(int i  = 0 ; i < arr.size() ; i++){

                triplet* trip = new triplet();
                trip->val = arr[i][0];
                trip->row = i;
                trip->index = 0;
                pq.push(trip);
            }   
        
        vector<int> sortedVec;

        while(!pq.empty()){

            triplet* ttop = pq.top();
            pq.pop();

            sortedVec.push_back(ttop->val);
            int row = ttop->row;
            int rowSize = arr[row].size();
            int nextIndex = ttop->index + 1;
            if(nextIndex < rowSize){

                 triplet* trip = new triplet();
                trip->val = arr[row][nextIndex];
                trip->row = row;
                trip->index = nextIndex;

                pq.push(trip);

            }


        }

        return sortedVec;

    }


int main(){

    vector<vector<int>> vec;
    int n = 0 , m= 0 ;
    cin>>n>>m ;
    for(int i = 0 ; i < n ; i++){

        vector<int> row_i;
        for(int j = 0 ; j < m ; j++){

            int a = 0 ;
            cin>>a;
            row_i.push_back(a);

        }

        vec.push_back(row_i);
    }


    vector<int> ans = mergeKArrays(vec  , m);
    for(int i = 0 ; i < n*n ; i++ ){
        cout<<ans[i]<<" ";
    }


}