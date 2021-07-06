#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

    int uniquePtr(int itr , int *arr  , int s){
        while(itr < s-1 && arr[itr]==arr[itr+1]){

            itr++;

        }
        return itr;
    }


       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {

            //code here
            vector<int> ans ;

            // int i = 0 ;
            // while(i < n1){

            //     int a = A[i];
            //     int foundB = binary_search(B , B+n2 , a);
            //     int foundC = binary_search(C , C+n3 , a);

            //     if(foundB && foundC){
            //         ans.push_back(a);
            //     }
            //     while (i < n1-1 && A[i] == A[i+1])
            //     {
            //         i++;
            //     }
                

            //     i++;

            // }

            int i = 0 , j  = 0, k=0;

            while(i<n1 && j <n2 && k <n3 ){

                if(A[i] == B[j] && B[j] == C[k] && C[k] == A[i]){
                    ans.push_back(A[i]);
                    i = uniquePtr(i , A , n1);
                    j = uniquePtr(j , B , n2);
                    k = uniquePtr(k , C, n3);

                    i++;j++;k++;
                }else{

                    if(A[i] < B[j] && A[i]<C[k]){
                        i++;
                    }else if(B[j] < A[i] && B[j] < C[k] ){
                        j++;
                    }else{
                        k++;
                    }

                }
                

            }

            return ans;

        }


int main(){


    

    // int arr[] = {1,2,3,4,5,6,6,7};zssss

    // cout<<binary_search(arr , arr+8 , 9)<<"\n";
    // cout<<binary_search(arr , arr+8 , 3)<<"\n";

}