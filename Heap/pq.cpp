#include<bits/stdc++.h>
using namespace std;

class maxPq{

    public:

    vector<int>heap_array;
    int heapSize;
    int currInd;

    maxPq(){
        currInd=-1;
        heapSize=0;
    }

    int pqSize(){
        return currInd+1;
    }

//push
    void insert(int a){
        int insertIndex = currInd+1;
        if(insertIndex>=heap_array.size()){
            heap_array.push_back(a);
            heapSize++;
        }else{
            heap_array[insertIndex] = a;
        }
        int ind = insertIndex;
        bool breakLoop = false;
        while(ind>=0 && !breakLoop){
            int parent = (ind-1)/2;
            if(parent<0){
                breakLoop = true;
                break;
            }
            if(heap_array[parent] > heap_array[ind]){
                swap(heap_array[parent],heap_array[ind]);
                ind=parent;
            }else{
                breakLoop=true;
                break;
            }
        }
        currInd++;
    }

    int pop(){
        if(currInd<0){
            return -1;
        }
        swap(heap_array[0],heap_array[currInd]);
        int poppedElement = heap_array[currInd];
        currInd--;
        int myind = 0;
        while (myind <= currInd)
        {
            int child1 = 2*myind + 1;
            int child2 = 2*myind + 2;
            int swapInd = myind;
            if(child1 <= currInd && heap_array[child1] < heap_array[swapInd]){
                swapInd = child1;
            }
            if(child2 <= currInd && heap_array[child2] < heap_array[swapInd]){
                swapInd = child2;
            }
            if(swapInd == myind){
                break;
            }else{
                swap(heap_array[swapInd],heap_array[myind]);
                myind = swapInd;
            }
        }
        return poppedElement;
        
    }

};

int main(){

    maxPq pq;
    for(int i = 0 ;i < 10 ;i++){
        int a =0;cin>>a;
        pq.insert(a);
    }
    for(int i = 0 ;i < 10 ;i++){
        cout<<pq.pop()<<"\n";
    }

}