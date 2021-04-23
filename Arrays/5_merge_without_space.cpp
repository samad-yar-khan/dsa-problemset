#include<iostream>
using namespace std;

//gives us the array we need to use for an index of heap
long long *get_array (long long arr1[], long long arr2[], int n, int m , int x){

    return (x<n)?arr1:arr2;

}

//gives us the actual index from heap index
int actual_index( int n , int x){

    return (x<n) ? x : x-n;

}

long long actual_value(long long arr1[], long long arr2[], int n, int m , int x){

    long long *arr = (x<n)?arr1:arr2;
    int real_index = (x<n)?x:x-n;

    return arr[real_index];

}




void heapify(long long arr1[], long long arr2[], int n, int m){

    //assume first elment is laready in the heap
    //we will modify first array while our pi , ci are both less than n 
    //when any of the the two become more than n , we have to calculate actual index which is pi-n and ci-n
    int ci = 1;
    while( ci < n+m ){

        int pi = (ci-1)/2;

       int a_ci = actual_index(n,ci) ;
       int a_pi = actual_index(n,pi);


        long long my_val = actual_value(arr1,arr2,n,m,ci);
        long long parent_val =  actual_value(arr1,arr2,n,m,pi);

        while(pi >= 0 && my_val > parent_val){

            //we need to ccheck our parents array and our array
            long long *child_array = get_array(arr1,arr2,n,m,ci) ;
            long long *parent_array = get_array(arr1,arr2,n,m,pi);

            //now we need to switch the elements to up heapify
            long long temp = child_array[a_ci] ;
            child_array[a_ci] = parent_array[a_pi];
            parent_array[a_pi] = temp;

            //now we need to recalculate all the values
            ci = pi;//we are now here
            pi = (ci-1)/2;
            a_ci = actual_index(n,ci);
            a_pi = actual_index(n,pi);
            my_val = actual_value(arr1,arr2,n,m,ci);
            parent_val = actual_value(arr1,arr2,n,m,pi);

        }

        ci++;

    }

}

void di_heapify(long long arr1[], long long arr2[], int n, int m){

    int ci = 0;
    int ei = n+m-1;
    //now at each iteration we put the element at the starting index at the end
    //now we need to dehipfy the heap 
    //index 0 will alsways be at arr1 
    //we need to check where our last element is , in arr2 or arr1
    int total_heap_size = m+n;
    while(ci < ei){

        long long* last_elemnt_arr = get_array(arr1,arr2,n,m,ei) ;
        //now ww got to know where last element belongs but we also need to calculate its actual index wrt the arrya and not the heap
        int a_ei = actual_index(n,ei);

        //now swap the first and the last elements 
        //like heapsort
        long long temp  = arr1 [0];
        arr1[0] = last_elemnt_arr[a_ei];
        last_elemnt_arr[a_ei] = temp;
        //now we assume the last elemnt to be deleted or dequed from the heap
        total_heap_size--;
        ei--;

        //now deheapfy
        long long mi = ci;
        long long c1 = 2*mi + 1;
        long long c2 = 2*mi + 2;

        
        
        while(c1 < total_heap_size){

            int a_mi = actual_index(n,mi);
            int a_c1 = actual_index(n,c1);
            int a_c2 = actual_index(n,c2);

            long long*arr_me = get_array(arr1,arr2,n,m,mi);//where i have my index
            long long*arr_c1 = get_array(arr1,arr2,n,m,c1);
            long long*arr_c2 = get_array(arr1,arr2,n,m ,c2);
            

            int max_index = mi;
            int max_value = arr_me[a_mi];

            if(max_value<arr_c1[a_c1]){
                max_index = c1;
                max_value = arr_c1[a_c1];
            }

            if(c2 < total_heap_size && max_value<arr_c2[a_c2]){
               max_index = c2;
                max_value = arr_c2[a_c2];
            }

            if(max_index == mi){
                break;
            }else if(max_index == c1){

                //first we swap the two
                long long temp = arr_me[a_mi];
                arr_me[a_mi]  = arr_c1[a_c1];
                arr_c1[a_c1] = temp;

                //now we caclulate new value of parents
                mi = c1;
                c1 = 2*mi + 1;
                c2 = 2*mi + 2;

            }else{

                //first we swap the two
                long long temp = arr_me[a_mi];
                arr_me[a_mi]  = arr_c2[a_c2];
                arr_c2[a_c2] = temp;

                //now we lake c1 our new location
                mi = c2;
                c1 = 2*mi + 1;
                c2 = 2*mi + 2;
            
            }


        }
       
    }

}


void merge(long long arr1[], long long arr2[], int n, int m) 
    { 
        // code here 
        heapify(arr1,arr2,n,m);
        di_heapify(arr1,arr2,n,m);

    } 


int main(){

    int n{0} , m {0};
    cin>>n>>m;

    long long*arr1 = new long long [n];
    long long*arr2 = new long long [m];

    cout<<"Enter elements of arr 1 \n";
    for( int i = 0 ; i < n ; i++){
        cin>>arr1[i];
    }

      cout<<"Enter elements of arr 2 \n";
    for( int i = 0 ; i < m ; i++){
        cin>>arr2[i];
    }


    heapify(arr1 , arr2 , n ,m );
    di_heapify(arr1 , arr2 , n ,m );

    for( int i = 0 ; i < n ; i++){
        cout<<arr1[i]<<" ";
    }

    for( int i = 0 ; i < m ; i++){
        cout<<arr2[i]<<" ";
    }


}