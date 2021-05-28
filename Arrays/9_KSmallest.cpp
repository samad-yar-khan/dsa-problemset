/*
https://practice.geeksforgeeks.org/problems/kth-smallest-element5635/1#
*/


//we use th quick sleect algo
#include<iostream>
#include<climits>
using namespace std;

 int partition (int arr[], int low, int high)
    {
           // Your code here


       int i = low-1 , j=low , p=high;

        //this chooses  a random elemnt within our range , puts it on the far right and then wec calc the pivot 
        //this randomised partition func helps us minimise the complexity 
        //and leads to an average complexity of(N)
        int n = high-low+1;
        int pivot = rand() % n;
        swap(arr[low + pivot], arr[high]);
       
       while(j<high){
            
            if(arr[j] <= arr[p]){
                i++;//expand i 
                swap(arr[i] , arr[j]);
            }
            
            j++;
           
       }
      
       
       swap(arr[i+1]  , arr[p]);
       p = i+1;
       return p;
       
    }


int kthSmallest(int arr[], int l, int r, int k){

    //logic is like qs , we sue a partition and a pivot , we choose the crrect position for our first element 
    //after that we parition the array 
    //if pivot  = k , we reutn our pivot element 
    //else we look in the place where our pivot exists
    //
    //base case
    if(k-1>r || k-1 <l){
        return INT_MAX;
    }

    if(r <= l ){
        return arr[l];
    }

    //is
    int piv = partition (arr , l , r);
    
    if(piv == k-1){//kth smalest elemt at its right pos
        return  arr[piv];
    }

    //ih
    if( k-1 < piv){
        return kthSmallest(arr , l , piv-1 , k);
    }else{
        return kthSmallest(arr , piv+1 , r , k);
    }


}


    int main(){
        cout<<"Enter size : ";
        int n{0};
        cin>>n;
        int*arr = new int[n];

        cout<<"Enter elementa : ";

        for(int i{0} ; i < n ; i++){
            cin>>arr[i];
        }   

        cout<<"Ente k ";
        int k {0};cin>>k;

        int item = kthSmallest(arr , 0 , n-1 , k);

      cout<<item<<"\n";
        

        delete [] arr;

    }

