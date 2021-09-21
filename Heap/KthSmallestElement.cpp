#include<bits/stdc++.h>
using namespace std;



// method 1 using a max herap
//complexity - O(Nlog(K))
int kthSmallest(int arr[], int l, int r, int k) {
        //code here
        priority_queue<int> k_smallest;//max pq pax heap
        for(int i =l;i<k; i++){
            k_smallest.push(arr[i]);
        }
        
        for(int i =k ;i<=r ; i++){
            if(k_smallest.top() > arr[i]){
                k_smallest.pop();
                k_smallest.push(arr[i]);
            }
        }
        
        return k_smallest.top();
}

//method 2 using quiickslect

int partition(int arr[], int l, int r){

    int e_ind = rand()%(r-l+1);
    e_ind += l;
    // cout<<l<<" "<<r<<".";
    int c=0;
    int element = arr[e_ind];
    for(int i = l; i <= r ; i++){
        if(i==e_ind){
            continue;
        }
        if(arr[i] < element){
            c++;
        }
    }

    swap(arr[e_ind]  , arr[l+c]);
    int i = l ;
    int j = r ;

    while(i<l+c && j>l+c){

        if(arr[i]<element && arr[j]>element){
            i++;j--;
        }else if(arr[i]>=element && arr[j]>element){
            j--;
        }else if(arr[i]<element && arr[j]<element){
            i++;
        }else{
            swap(arr[i],arr[j]);
        }
    }
    return l+c;
}

int kthSmallest(int arr[], int l, int r, int k) {
    
     //base case
    while(k-1>=l && k-1 <= r){
        int part = partition(arr , l , r);
        if(part == k-1){
            return arr[part];
        }
        //ih
        if(part > k-1){
            r=part-1;
        }else{
            l=part+1;
        }
        // cout<<r<<","<<l<<".";
        
    }
    return 0;
}