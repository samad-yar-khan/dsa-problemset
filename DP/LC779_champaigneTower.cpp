#include <bits/stdc++.h>
using namespace std;

double champagneTower(int poured, int query_row, int query_glass) {
        
        double zero = 0;
        
        vector<double>curr(101,zero);
        vector<double>prev(101,zero);

        int r = query_row;
        int c = query_glass;
        prev[0] = poured;
        double two = 2;
        
        for(int i =1 ; i<=query_row ; i++){
            for(int j=0;j<=i;j++){
                double right = max((prev[j]-double(1))/two,zero);
                double left = 0;
                if(j-1 >= 0){
                    left = max((prev[j-1]-double(1))/two,zero);
                }
                 curr[j] = left + right;   
            }
            for(int j=0;j<=i;j++){
                prev[j]=curr[j];
            }
        }
        
        return min(double(1),prev[c]);
    }