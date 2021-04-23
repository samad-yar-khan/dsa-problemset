int getMinDiff(int arr[], int n, int k) {
        // code here
        sort(arr , arr+n);
        int arr1[100000];
        
        int i = 0 ;
        while(i < n && arr[i] < k){
            i++;
        }
        if(i == n){// k is less than al the lements so we can only increase 
            return arr[n-1] - arr[0];
        }

        if(i == 0){
            return arr[n-1] - arr[0] - 2*k;
        }

        int j = 0 ;
        while( j < n ){

            if(j < i){
                arr1[j] = arr[j]+k;
            }else{
                arr1[j] = arr[j] - k;
            }
            j++;
  
        }


        int min_left = arr[0];
        int min_right = arr[i];
        int max_left = arr[i-1];
        int max_right = arr[n-1];
        int minhere = min(min_left , min_right);
        int maxhere = max(max_left , max_right);


    
        return maxhere - minhere;
    }