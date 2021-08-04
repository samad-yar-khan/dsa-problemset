#include<bits/stdc++.h>
using namespace std;
/*

aaabb
aab 0 10
0 9
9 - ei

si = 0 + 9
si%=size 
ei = 9 
ei%=size

aab aab aab aab

1-11
0-10
10-0+1 = 11/3 = 3 *3
si = 0+9%3 =0
 ei = 10 =1

si=11%3 = 2
ei = 12%3=0

si>ei
1 2 - 3
0 0

10^9
10^9

aab aab aab a
matrix[n][26];
index - size 01234
           a 12333
           b 00012    

           l = 0 r = 56
           (r-l+1)/n - full string
           (r-l+1)%n - partial   

            ans fs  = arr[n-1][c]*fs  2*3
           si = l + full
*/
int soln(string str , int q , vector<vector<string>>){

    

}