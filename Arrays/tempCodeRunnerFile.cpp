 int partition (int arr[], int low, int high)
    {
           // Your code here


       int i = low-1 , j=low , p{high};
       
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


int kthSmallest(int arr[], i