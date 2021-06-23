/*

You are given two 32 bit numbers , M and N , and two bit positions i and j .Write a method to set all bits between i and j in N equal to M (eg . M becomes a substring of N starting at pos i and ending at j )

ex 
N = 1000000000,
M = 10101
i = 2 , j =  6
output => N = 10001010100

*/

#include<iostream>
using namespace std;


int setBits(int N , int M , int i , int j ){

    //to clear bits in N from range i to j
    int ones = (~0);
    int mask1 = (ones<<(j+1)); //111100000
    int mask2 = (1<<i) - 1; //2^i - 1;
    int mask = mask1 | mask2;

    int cleared_n = N&mask; //will crear bits in the range i to j
    //now we need to insert M
    //to insert M from inex i , we gotta shift M i times
    int m = M << i;
    //now we do an or op
    int ans = m|cleared_n;
    return ans;

}

int main(){
    int M = 0 , N= 0 , i = 0 , j = 0;

    int T = 0 ;
    cin>>T;
    while(T--){
        cin>>N>>M>>i>>j;
        cout<<setBits(N,M,i,j);
        cout<<"\n";
    }


}



