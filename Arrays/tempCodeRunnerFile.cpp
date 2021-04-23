
    int time = 1;
    bool trans{false};
    int total = 0;

    for( int i = 0 ; i < m ; i++){

            for(int j = 0 ; j < n ; j++){

                if(mat[i][j] == 2){

                    if(i<m-1 && mat[i+1][j] == 1){
                        
                        trans = true;
                    }
                    if(i>0 && mat[i-1][j] == 1){
                       
                        trans = true;

                    }
                    if(j<n-1 && mat[i][j+1] == 1){
                       
                        trans = true;

                    }
                    if(j>0 && mat[i][j-1]== 1){
                       
                        trans = true;
                    }
                }
            }

    }
    if(!trans){
        return -1;
    }


    do{
        
        trans = false;
        for( int i = 0 ; i < m ; i++){

            for(int j = 0 ; j < n ; j++){

                if(mat[i][j] == 2){

                    if(i<m-1 && mat[i+1][j] == 1){
                        mat[i+1][j] = 3;
                        trans = true;
                    }
                    if(i>0 && mat[i-1][j] == 1){
                        mat[i-1][j] = 3;
                        trans = true;

                    }
                    if(j<n-1 && mat[i][j+1] == 1){
                        mat[i][j+1] = 3;
                        trans = true;

                    }
                    if(j>0 && mat[i][j-1]== 1){
                        mat[i][j-1] = 3;
                        trans = true;
                    }
                }
            }

        }
       
        for( int i = 0 ; i < m ; i++){

            for(int j = 0 ; j < n ; j++){

                if(mat[i][j] == 3){

                    mat[i][j] = 2;
                   
                }
            }

        }

        if(trans){
            total += time;
            time ++;
        }



    }while(trans);

    return total;