// int paths(char Graph[][MAXN],int N, int M , int i , int j,int p , char* word , bool** visited){

//     visited[i][j] = true ;

//     //base
//     if(word[p-1] == 'A'){
//         return 1;
//     }

//     for(int x = i-1 ; x <= i+1 ; x++){
//         for(int y = j-1 ; y <= j+1 ; y++){
//             if( x < 0 || y < 0 || x >=N || y >= M || visited[x][y]){
//                 continue;
//             }
//             if(Graph[x][y] == word[p]){
//                 int ans = paths(Graph , N , M , x , y , p+1 , word , visited);
//                 if(ans == 1){
//                     return 1;
//                 }
//             }
//         }
//     }

//     return 0 ;


// }

// int paths(char Graph[][MAXN],int N, int M , int i , int j ){

//     //we eenter this when we find a C
//     bool** visited = new bool*[N];
//     for(int i {0} ; i<N ; i++ ){
//         visited[i] = new bool[M];
//         for(int j{0} ; j<M ; j++){
//             visited[i][j] = false;
//         }
//     }

//     char word [] = {"CODINGNINJA"} ;

//     int ans = paths(Graph , N , M , i , j , 1 , word , visited);
//     for(int i = 0 ; i < N ; i++){
//         delete[] visited[i];
//     }
//     delete[] visited;
//     return ans;
// }

// int solve(char Graph[][MAXN],int N, int M)
// {
	
//    for(int i = 0 ; i < N ; i++){
//        for(int j = 0 ; j < M ; j++){

//            if(Graph[i][j] == 'C'){

//                int ans = paths(Graph , N , M , i , j );
//                if(ans == 1){
//                    return 1;
//                }
//            }
//        }
//    }

//     return 0;
// }

/*
    Coding Ninjas
    Send Feedback
    Given a NxM matrix containing Uppercase English Alphabets only. Your task is to tell if there is a path in the given matrix which makes the sentence “CODINGNINJA” .
    There is a path from any cell to all its neighbouring cells. For a particular cell, neighbouring cells are those cells that share an edge or a corner with the cell.
    Input Format :
    The first line of input contains two space separated integers N and M, where N is number of rows and M is the number of columns in the matrix. 
    Each of the following N lines contain M characters. Please note that characters are not space separated.
    Output Format :
    Print 1 if there is a path which makes the sentence “CODINGNINJA” else print 0.
    Constraints :
    1 <= N <= 1000
    1 <= M <= 1000
    Time Limit: 1 second
    Sample Input 1:
    2 11
    CXDXNXNXNXA
    XOXIXGXIXJX
    Sample Output 1:
    1
*/

#include<bits/stdc++.h>
using namespace std;

int x[8] = {-1,-1,-1,0,0,1,1,1};
int y[8] = {-1,0,1,-1,1,-1,0,1};


bool dfs(vector<vector<char>> &board, int &n, int &m ,int i ,int j , bool **visited,string s ,int ind){
	
    if(ind == s.length() -1 && board[i][j]=='A'){
        return true;
    }
    
    if(ind == s.length()){
        return true;
    }

   
    visited[i][j] = true;

    for(int k = 0 ; k<8 ; k++){
        int X = i + x[k];
        int Y = j + y[k];

        if(X < 0 || Y <0 || X>=n || Y>= m ){
            continue;
        }
        if(visited[X][Y]){
            continue;
        }
		

        bool ans = false;
        if(s.at(ind+1) == board[X][Y]){
             ans = dfs(board , n , m , X ,Y , visited , s , ind+1);
        }
        if(ans){
            return ans;
        }
    }

    visited[i][j] = false;
    return false;
    

}

bool hasPath(vector<vector<char>> &board, int n, int m) {
    // Write your code here.
    /*
    i go on a path using dfs and see if i found the word , in case i dont , then i unmark the places i have visited and look fopr anotehr c
    */

    bool**visited = new bool*[n];
        for(int i =0 ;i < n ; i++){
            visited[i] = new bool[m];
            for(int j = 0 ; j < m ; j++){ 
                visited[i][j] = false;   
            }
        }  

    string s={"CODINGNINJA"};
    bool ans = false;
    for(int i = 0 ; i < n ; i++){
        for(int j = 0 ;  j<m ; j++){
            if(board[i][j] == 'C'){
                 ans  = dfs(board , n , m , i , j , visited ,s , 0);
                if(ans){
                    // cout<<i<<"-"<<j;
                    break;
                   
                }
            }
        }
        if(ans){
            break;
        }
    }


      for(int i =0 ;i < n ; i++){
        delete [] visited[i];
    }
    delete [] visited;
    return ans;

}
int main(){
    int n = 0;
    int m = 0 ;
    cin>>n>>m;
    vector<vector<char>> board;
    for(int i = 0 ; i < n ; i++){
        vector<char> c;
        for(int j = 0 ; j < m;j++){
            char c_ = '\0';
            cin>>c_;
            c.push_back(c_);
        }
        board.push_back(c);
    }    

    cout<<hasPath(board , n , m)<<"\n";
}