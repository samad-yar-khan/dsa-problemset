
long long countPairs(int X[], int Y[], int M, int N)
{
    //Your code here
    sort(X , X+M);
    sort(Y , Y+N);
    long long count{0};
    int freq[5]{0};
    
    for(int i = 0 ; i < M ; i++){
        if(Y[i]<5){
        freq[Y[i]]++;
        }
    }
    
    int zero_count {0};
    while(X[zero_count] == 0){
        zero_count++;
    }

    int i = 0 , j = 0 ;

    while(i<M && X[i] <= 1){
        i++;
    }
    //our lofic works after 4 as that it where our specias cases witll end 
    
    while(j<N && Y[j] <= 4){
        j++;
    }
    
    //count when y is 0
    count += (M-zero_count)*freq[0];
    //count for when y is 1;
    count += (M-i)*freq[1];
    //count 1;
    int first2_index = i;
    
    int freq2X{0} , freq3X{0};
   while(X[i] <= 3){
       if(X[i] == 2){
           freq2X++;
       }
       if(X[i] == 3){
           freq3X++;
       }
       
        i++;
    }
    
    count += freq3X*(freq[2] + freq[4]);//special cases handled
    //we got back to where 2s start
    i = first2_index; //back to 2
    //count 3s
    

    while( i < M && j <N){
    
        if(X[i] >= Y[j]){
            j++;

        }else{

                count += (N-j);    
                i++;
        
        }

    }

    return count;

}