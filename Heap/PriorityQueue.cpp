
#include<iostream>
#include<vector>
using namespace std;

class MinPriorityQueue {
    vector<int> pq;
    
    public :
    
    MinPriorityQueue() {
        
    }
    
    bool isEmpty() {
        return pq.size() == 0;
    }
    
    // Return the size of priorityQueue - no of elements present
    int getSize() {
        return pq.size();
    }
    
    int getMin() {
        if(isEmpty()) {
            return 0;		// Priority Queue is empty
        }
        return pq[0];
    }
    
    void insert(int element) {
       
       pq.push_back(element);
       //now i upheapify
       //parent1 
        int currIndex = pq.size()-1; 
        int parent = (currIndex - 1)/2;


        while(parent>=0 && pq.at(parent) > pq.at(currIndex)){

            swap(pq.at(currIndex) , pq.at(parent));
            currIndex = parent;
            parent = (currIndex-1)/2;

        }

    }
    
    int removeMin() {
        // Complete this function

    	//edge case
        if(pq.size() == 0){
            return  0 ;
        }

        //swap the fist and last node and delete the last node
        swap(pq.at(0) , pq.at(pq.size() - 1));
        //store the last elemnt 
        int minElement = pq.at(pq.size() -1);
        //delete min from end
        pq.pop_back();

        ///downheapify 
        int myIndex = 0 ;
        int leftChildIndex = 1 ;
        int rightChildIndex = 2;

        while(leftChildIndex < pq.size()){  //iterate till we have some chile 

            int leftChild = INT_MAX , rightChild = INT_MAX;
            leftChild=pq.at(leftChildIndex);
            rightChild= rightChildIndex < pq.size() ? pq.at(rightChildIndex) : INT_MAX ;
            int swapIndex= myIndex;
            
            //min of our child nodes
            if(leftChild < rightChild){
                swapIndex = leftChildIndex ;
            }else{
                swapIndex = rightChildIndex;
            }

            if(pq.at(swapIndex) < pq.at(myIndex)){
                swap(pq.at(myIndex) , pq.at(swapIndex));
                myIndex=swapIndex;

                leftChildIndex = (2*myIndex )+ 1 ;
                rightChildIndex = (2*myIndex) + 2;

            }else{
                break;
            }
        }

        return minElement;

    }
};



// class PriorityQueue {
//     vector<int> pq;
    
//     public :
    
//     PriorityQueue() {
        
//     }
    
//     bool isEmpty() {
//         return pq.size() == 0;
//     }
    
//     // Return the size of priorityQueue - no of elements present
//     int getSize() {
//         return pq.size();
//     }
    
//     int getMin() {
//         if(isEmpty()) {
//             return 0;		// Priority Queue is empty
//         }
//         return pq[0];
//     }
    
//     void insert(int element) {
//         pq.push_back(element);
        
//         int childIndex = pq.size() - 1;
        
//         while(childIndex > 0) {
//             int parentIndex = (childIndex - 1) / 2;
            
//             if(pq[childIndex] < pq[parentIndex]) {
//                 int temp = pq[childIndex];
//                 pq[childIndex] = pq[parentIndex];
//                 pq[parentIndex] = temp;
//             }
//             else {
//                 break;
//             }
//             childIndex = parentIndex;
//         }
        
//     }
    
//         int removeMin() {
//         // Complete this function\
        
//     	//edge case
//         if(pq.size()==0){
//             return 0;
//         }
        
//              int ans = pq.at(0); //we need to return this so we juts store this in ans
//         //swap

//         int limit = pq.size()-1;
//         pq.at(0)=pq.at(limit);
//         pq.at(limit)=ans; //although this doenst make much sense t just signfies the swapping 

//         //delete last element
//         pq.pop_back();
//         limit--;

//         int my_index = 0;
//         int left_child_index = 2*my_index + 1;
//         int right_child_index = 2*my_index + 2;


//         while(!(left_child_index>limit)){ //iterate till our left child goes out of bounds which mean that .which means that we have reached a leaf node
//         int min_index = my_index;
//         //finding the min

//         if(pq.at(min_index)>pq.at(left_child_index)){
//             min_index=left_child_index;
//         }
//         //before comparing right and  min we must see if right even exists or not
//         if( right_child_index<pq.size() && pq.at(min_index)>pq.at(right_child_index)){
//             min_index=right_child_index;
//         }

//         //if my eleemnt is min index break out else we just swap and find new chilren indices

//         if(my_index==min_index){
//             break;
//         }else{
//             int temp = pq.at(my_index);
//             pq.at(my_index)= pq.at(min_index);
//             pq.at(min_index)=temp;

//             my_index=min_index;
//             left_child_index = 2*my_index + 1;
//             right_child_index = 2*my_index + 2;
//         }


//         }
//         return ans;
//         }
// };


#include<vector>
class MaxPriorityQueue {
    // Complete this clas
     private:

    vector <int> pq;  //same as minpq we need to create a heap

    public :
    
    //constructor
    MaxPriorityQueue () {

    }

    int getSize (){
        return pq.size();
    }

    bool isEmpty (){
        return pq.size() == 0;
    }

    int insert (int x){

        pq.push_back(x);
        //upheapify
        int myIndex = pq.size() -1 ;
        int parentIndex = (myIndex-1)/2;

        while(parentIndex >=0 && pq.at(myIndex) > pq.at(parentIndex)){

            swap(pq.at(myIndex) , pq.at(parentIndex));
            myIndex = parentIndex;
            parentIndex = (myIndex - 1)/2;
        }

    }

    int getMax (){

        if(pq.empty()){
            return 0;
        }

        return pq.at(0);

    }

    int removeMax(){

        if(pq.size()==0){
            return 0;
        }   

        int maxElement = pq.at(0);
        //swap first and llast and dlelete last
        swap(pq.at(0) , pq.at(pq.size() -1));
        pq.pop_back();

        //now downhealpify
        int myIndex = 0 ;
        int leftChildIndex = 2*myIndex+1;
        int rightChildIndex = 2*myIndex+2;
        
        while (leftChildIndex < pq.size())
        {
            
            int leftChild = pq.at(leftChildIndex);
            int myElement = pq.at(myIndex);
            int rightChild = rightChildIndex < pq.size() ? pq.at(rightChildIndex) : INT_MIN;
            
            int swapIndex = (leftChild > rightChild) ? leftChildIndex : rightChildIndex;

            if(pq.at(swapIndex) > pq.at(myIndex)){
                
                swap(pq.at(myIndex) , pq.at(swapIndex));
                myIndex=swapIndex;
                leftChildIndex = 2*myIndex+1;
                rightChildIndex = 2*myIndex+2;

            }else{
                break;
            }


        }
        


    }

    
};


/*max pq

class PriorityQueue {
    // Complete this clas
     private:

    vector <int> pq;  //same as minpq we need to create a heap

    public :
    
    //constructor
    PriorityQueue () {

    }

    int getSize (){
        return pq.size();
    }

    bool isEmpty (){
        return pq.size() == 0;
    }

    int insert (int x){

        pq.push_back(x); //pushed it to the end of the vec or last element in cbt

        int my_index = pq.size()-1;
        int parent_index = ( my_index -1 )/2;

        //either my parents becoes larger than me or i reach the top most node in the cbt
        while (my_index > 0 && pq.at(my_index) > pq.at(parent_index)){

            int temp = pq.at(my_index);
            pq.at(my_index) = pq.at(parent_index);
            pq.at(parent_index)= temp;

            my_index = parent_index;
            parent_index = (my_index-1)/2;
        }
    }

    int getMax (){

        if(pq.empty()){
            return 0;
        }

        return pq.at(0);

    }

    int removeMax(){

        if(pq.empty()){
            return 0; 
        }
    
        //swap
        int ans = pq.at(0);
        pq.at(0)=pq.at(pq.size() - 1);
        pq.pop_back();

        //seting child induces
        int my_index =0;
        int left_child_index = 2*my_index + 1;
        int right_child_index = 2*my_index + 2;

        //iteralte till you have no children left or you dont neeed to donw heapifyy anymore    
        while(left_child_index < pq.size()){
            int max_index = my_index;

            if(pq.at(left_child_index) > pq.at(max_index) ){
            max_index = left_child_index;
            }

            if(right_child_index <pq.size()  && pq.at(right_child_index) > pq.at(max_index)){
                max_index = right_child_index;
            }

            if(my_index==max_index){
                break;
            }else{
                int temp = pq.at(my_index);
                pq.at(my_index)=pq.at(max_index);
                pq.at(max_index)=temp;

                my_index=max_index;

                left_child_index = 2*my_index + 1;
                right_child_index = 2*my_index + 2;

            }

        }
        return ans;
    }

    
    
};

*/