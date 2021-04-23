//shared by harshil on wa
#include<iostream>
#include<algorithm>
using  namespace std;

   int getMinDiff(int arr[], int n, int k) {
        // code here
        sort(arr , arr+n);

        int i = 0 ;
        while(i < n && arr[i] < k){
            i++;
        }

        if(i == n){// k is less than al the lements so we can only increase 
            return arr[n-1] - arr[0];
        }

        int t_min = arr[0];
        int t_max = arr[n-1] ;
        for(int j = i-1 ; j < n-1 ; j++){
            int min_left = arr[0]+k;
            int min_right = arr[j+1] - k;
            int max_left = arr[j] + k;
            int max_right = arr[n-1]-k;
            int min_here = min(min(min_left , min_right) , min(max_right , max_left));
            int max_here = max(max(min_left , min_right) , max(max_right , max_left));
            if(max_here - min_here < t_max - t_min){
                t_max = max_here;
                t_min = min_here;
            }
        }


        return t_max- t_min;
    }

    int main(){
        int k{0} , n{0} ;
        cin>>k>>n;
        int*arr = new int[n];

        for(int i{0} ; i< n ; i++){
            cin>>arr[i];
        }

        cout<<getMinDiff(arr,n,k);
        
        
        delete [] arr;
        return 0;
    }