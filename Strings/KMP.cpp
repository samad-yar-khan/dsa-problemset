#include<bits/stdc++.h>
using namespace std;

string solve(string s) {
    
    int stringLength = s.length(); 
    vector<int> longestPreSuff(stringLength+1,0);

    int currPrefixlen = 0;
    int index = 1;

    while(index < stringLength){

        if(s.at(currPrefixlen) == s.at(index)){

            currPrefixlen++;
            longestPreSuff[index] = currPrefixlen;
            index++;

        }else{

            if(currPrefixlen == 0){
            //we have no matchings till now

                longestPreSuff[index++] = currPrefixlen;

            }else{

                currPrefixlen= longestPreSuff[currPrefixlen-1];


            }

        }

    }

    return s.substr(0,longestPreSuff[index-1]);

}