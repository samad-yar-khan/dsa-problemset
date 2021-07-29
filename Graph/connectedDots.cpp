#include<bits/stdc++.h>
using namespace std;
/*
Connecting Dots
Send Feedback
Gary has a board of size NxM. Each cell in the board is a coloured dot. There exist only 26 colours denoted by uppercase Latin characters (i.e. A,B,...,Z). Now Gary is getting bored and wants to play a game. The key of this game is to find a cycle that contain dots of same colour. Formally, we call a sequence of dots d1, d2, ..., dk a cycle if and only if it meets the following condition:
1. These k dots are different: if i ≠ j then di is different from dj.
2. k is at least 4.
3. All dots belong to the same colour.
4. For all 1 ≤ i ≤ k - 1: di and di + 1 are adjacent. Also, dk and d1 should also be adjacent. Cells x and y are called adjacent if they share an edge.
Since Gary is colour blind, he wants your help. Your task is to determine if there exists a cycle on the board.
Input Format :
The first line of input contains two space separated integers N and M, where N is number of rows and M is the number of columns of the board. 
Each of the following N lines contain M characters. Please note that characters are not space separated. Each character is an uppercase Latin letter.
Output Format :
Print true if there is a cycle in the board, else print false.
Constraints :
2 <= N <= 1000
2 <= M <= 1000
Time Limit: 1 second
Sample Input 1:
3 4
AAAA
ABCA
AAAA
Sample Output 1:
true
*/

/*
int check_circle(char board[][MAXN],int n, int m , char color , pair<bool, int>** visited  , int i , int j );
int check_circle_2(char board[][MAXN],int n, int m , char color , pair<bool, int>** visited , int i , int j , int position);
int solve(char board[][MAXN],int n, int m);


int solve(char board[][MAXN],int n, int m){

    //my visited matrix will have a  bool and index value , to tell what is the index of that 
    //visited positon in my seqeunce , this wll help us maintain o(M*N)complexity , avoid repettion
	 pair<bool , int >** visited = new pair <bool , int >*[n];
    for(int i = 0 ; i < n ; i ++ ){

        visited[i] = new pair<bool , int >[m];
        for( int j = 0 ; j < m ; j++ ){

            visited[i][j].first=false;
            visited[i][j].second=0;
        }
    }
    int ans = 0 ;
    bool break_loop= false;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ; j < m ; j++){

            if(!visited[i][j].first){
                ans = check_circle(board , n , m , board[i][j] , visited , i , j );
                if(ans == 1){
                    break_loop= true;
                    break;
                }
            }
        }
        if(break_loop){
            break;
        }
    }

    for(int i{0} ; i < n ; i++){
        delete[] visited[i];
    }
    delete[] visited;
    return ans ;
}


//basccia;;y whata happens it wit visited we also strore the posiition of that elmenst in the color que
//if the queue runs into itself , by subtracting the positions we can isntanty tell if the diiif or position is equal to 4 or not
//and we can  give the aswe accordngy
int check_circle_2(char board[][MAXN],int n, int m , char color , pair<bool, int>** visited , int i , int j , int position)
{

    visited[i][j].first= true ;
    visited[i][j].second = position ;
    
    
    int x[4] ={-1,0,1,0};
    int y[4] ={0,-1,0,1};

    for(int k = 0 ; k < 4 ; k++){

        int new_i = i + x[k];
        int new_j = j + y[k];

        if(new_i >=0 && new_i <n && new_j >=0 && new_j < m  && board[new_i][new_j] == color){
            int num_positions = position - visited[new_i][new_j].second + 1 ;
            if(visited[new_i][new_j].first && num_positions >=4){
                return 1;
            }
        }
    }

    int ans = 0 ;

    for(int k = 0 ; k < 4 ; k++){

        int new_i = i + x[k]; //this is basically the next adjacent cell
        int new_j = j + y[k];

        if(new_i >=0 && new_i <n && new_j >=0 && new_j < m && board[new_i][new_j]==color){//this check if the coordinate we are lookng up are wihin bounds

            if(!visited[new_i][new_j].first){
                
                ans = check_circle_2(board , n , m , color , visited , new_i , new_j , position+1);
                if(ans == 1){
                    return 1;
                }

            }

        }
    }


    return 0 ;

}

int check_circle(char board[][MAXN],int n, int m , char color , pair<bool, int>** visited , int i , int j ){

    int ans = check_circle_2(board , n , m , color , visited , i , j , 0 );
    return ans;
}



*/

#include<bits/stdc++.h>
using namespace std;

int x []= {0,0,-1,1};
int y []= {-1,1,0,0};

bool findCycle(vector<vector<char>> &board , int n , int m , int i , int j ,vector<vector<int>> &visited  ,int distance ,char paint){
    
    //mark
    visited[i][j] = distance;
    bool ans=false;
    for(int itr = 0 ; itr < 4 ; itr++ ){
        int X = i + x[itr];
        int Y = j + y[itr];
        
        if(X<0 || X>=n || Y <0 || Y >=m){
            continue ;
        }
        
        if(board[X][Y] == paint){
            if(visited[X][Y] == 0){
                ans = findCycle(board , n , m , X , Y , visited,distance+1,paint);
            }else if(visited[X][Y] > 0){
                int diff = abs(distance - visited[X][Y]) + 1;
                if(diff>=4){
                    ans =true;
                }
            }
            
            if(ans){
                return ans;
            }
        }
    }
    
    visited[i][j] = -1;
    return false;
    
    
}

bool hasCycle(vector<vector<char>> &board, int n, int m) {
    // Write your code here.
    vector<vector<int>> visited (1000,vector<int>(1000 , 0));
    //visited[i][j] = 0 , means unvoisted , 
    //viisted[i][j] = x , where x!= -1 signifirs distance of point from origin pt
    //if x = -1 , then visited and no path found , skip
    bool ans = false;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0;j < m ; j++){
            if(visited[i][j] == 0){
                ans = findCycle(board , n , m , i , j , visited,1,board[i][j]);
                
    			if(ans){
                    return ans;
                }
            }
        }
    }
    return ans;  
                        
}