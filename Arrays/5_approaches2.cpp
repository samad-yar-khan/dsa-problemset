#include<iostream>
using namespace std;
#include<cmath>

void merge2(long long arr1[], long long arr2[], int n, int m) 
    { 
        //insertion sort technique
        int it1 = 0 ;
        int it2 = 0 ;

        long long*array1 = arr1;
        long long*array2 = arr2;

        int len1 = n;
        int len2 = m ;
        
        while(it1 < len1 ){
            if(array1[it1] > array2[it2]){

                int temp = array1[it1];
                array1[it1] = array2[it2];
                array2[it2] = temp;

                //now we llook for the right position for our nw elemnt of array 2
                //we need to check for all elemnte less than our element to our right , and shift them backwwasa and move ours to the correct pos
                int my_itr = it2+1;

                while( my_itr < len2 && array2[my_itr] < array2[it2]){
                    my_itr++;
                }

                if(my_itr!=it2+1){

                    int temp = array2[it2];
                    int new_itr = it2;

                    while(new_itr < my_itr-1){
                        array2[new_itr] = array2[new_itr+1];
                        new_itr++;
                    }

                    array2[new_itr] = temp;

                }
                it1++;
            }else{
                it1++;
                it2++;
            }            
        }

    } 


//method 2
//gap theorem
//refer to striver vid
void merge(long long arr1[], long long arr2[], int n, int m) 
    { 

       

        int len1 = n;
        int len2 = m ;
        int gap = ceil((double)(len1+len2)/(2));
        

        while( gap >= 1){
           cout<<"\n*****"<<gap<<"******\n";
           
            int it1 = 0 ;
            int it2 =  gap ;

            long long*array1 = arr1;
            long long*array2 = arr2;

           
            
            while(it2 < len1 + len2){
             
                int a_it1 = (it1<len1) ? it1 : it1-len1;
                int a_it2 = (it2<len1) ? it2 : it2-len1;

                array1 = (it1<len1) ? arr1: arr2;
                array2 = (it2<len1) ? arr1: arr2;

                if(array1[a_it1] > array2[a_it2]){
                    cout<<it1<<"--it1 , it2 ---"<<it2<<"\n";
                    cout<<array1[a_it1]<<" "<<array2[a_it2]<<"\n";
                    long long temp = array1[a_it1];
                    array1[a_it1] = array2[a_it2];
                    array2[a_it2] = temp;
                }
                it1++;
                it2++; 
            }


            if(gap == 1 ){
                return;
            }

            gap = ceil((double)gap/2);

        }


    }

int main(){

    int m{0} , n{0};
        
    cin>>m>>n;

    long long *arr1  = new long long[m];
    long long *arr2  = new long long[n];

    cout<<"Enter array1 elemnts :  \n";
    for(int i = 0 ; i < m ; i++){
        cin>>arr1[i];
    }

    cout<<"Enter array2 elemnts :  \n";
    for(int i = 0 ; i < n ; i++){
        cin>>arr2[i];
    }

    merge(arr1 , arr2 , m , n);

   
    for(int i = 0 ; i < m ; i++){
        cout<<arr1[i]<<" ";
    }

    for(int i = 0 ; i < n ; i++){
        cout<<arr2[i]<<" ";
    }

}

