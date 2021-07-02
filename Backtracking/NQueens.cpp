#include<iostream>
#include<vector>
using namespace std;

bool isSafe (int x , int y , vector<vector<int>>& board){

    //check if there is any queen in any column
    for(int i = 0 ; i <= x ; i++){
        if(board.at(i).at(y) == 1){
            return false;
        }
    }

    // check left diagonal for queens
    int r = x ;
    int c = y;
    while( r >=0 && c >=0){

        if(board.at(r).at(c) == 1){
            return false;
        }

        r--;c--;

    }

    //check right diaogonal for queens 
    r=x;
    c=y;
     while( r >=0 && c < board.size()){
        if(board.at(r).at(c) == 1){
            return false;
        }

        r--;c++;

    }

    return true;


}

void placedQueens(int n , int row , vector<vector<int>>& ans , vector<vector<int>>& board){

    //base case
    if(row >= n ){

        vector<int> positions ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                if(board[i][j] == 1){
                    positions.push_back(j+1);
                }
            }
        }
        ans.push_back(positions);

        return ;

    }

    //induction hypothesis
    for(int j = 0 ; j < n ; j++){

        if(isSafe(row,j,board)){

            //place queen
            board.at(row).at(j) = 1;

            //place rest of the queens in subsequent rows
            placedQueens(n , row+1 , ans , board);
           
            //remove queen //baktrack and place queen in next col
            board.at(row).at(j) = 0;
        }

    }

}

vector<vector<int>> nQueen(int n) {

    vector<vector<int>> ans ; //ans stores the array of cols where queens are places from row 0 to n in each config

    vector<vector<int>> board(n , vector<int>(n , 0)) ;

    placedQueens(n , 0 , ans , board);
    return ans;

}



int main(){

    int n = 0 ;
    cin>>n;
    vector<vector<int>> ans = nQueen(n);
    for(int i = 0 ; i < ans.size() ; i++){
        for(int j = 0 ; j < ans.at(i).size() ; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }


}   
