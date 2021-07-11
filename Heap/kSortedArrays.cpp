#include<bits/stdc++.h>
#include<iostream>
using namespace std;

class triplet {

    public :
    int array_num ;
    int my_index ;
    int val;

    triplet (int arr_num , int val , int index){
        this->array_num = arr_num;
        this->val = val;
        this->my_index = index;

    }
};

//comparator class
class Comp {
    public :

    bool operator()(triplet *a,triplet* b) {
        return a->val > b->val;
    }
};


vector<int> mergeKArrays(vector<vector<int>> arr, int K){
        //code here
    vector<int> ans;
    priority_queue<triplet* , vector<triplet*> , Comp> pq;
    for(int i = 0 ; i < arr.size() ; i++){
        triplet* a = new triplet(i , arr[i][0] , 0);
        pq.push(a);
    }

    while(!pq.empty()){

        triplet* t = pq.top();
        pq.pop();

        ans.push_back(t->val);
        int row = t->array_num;
        int index = t->my_index;
        index++;
       if(index < arr.at(row).size()){
           triplet* t2 = new triplet(row , arr[row][index] , index);
       }
    }

    return ans;

}