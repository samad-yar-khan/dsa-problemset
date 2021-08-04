#include<bits/stdc++.h>
using namespace std;
//https://www.spoj.com/submit/PRATA/
/*
question says that we have to find the minimum time req ro make paratas 
so we start with a case where we see how many pratas we can make with teh stipulated time , given the cooks ranks , so min  time = 0 , no prata made by anyone
max time = all paratas made by slowest cook = time -> (p(p+1)/2)*Rank
*/


int makePrata(int *cooks , int n ,int time ){

    int totalPrata= 0;
    for(int i = 0 ; i < n ; i++){

        int R = cooks[i];
        int t = time;

        //solving quadfratic
        int d = sqrt(1 + ((4*(t*2))/R));

        int numPrata = (-1+d)/2;
        totalPrata+=numPrata;
    }

    return totalPrata;

}

int solve(int *cooks , int n , int p){


    int max_rank = 0 ;
    for(int i = 0 ; i< n ; i++){
        max_rank = max(max_rank , cooks[i]);
    }

    int si = 0;
    int ei = max_rank*((p*(p+1))/2);
    int ans = INT_MAX;
    while(si <= ei){
        int mid = si + (ei-si)/2;
        int time = mid/n;
        int pratasMade = makePrata(cooks ,  n , time );

        if(pratasMade < p){
            si = mid+1;
        }else if(pratasMade>=p){
            ei = mid-1;
            ans = min(ans , time);
        }


    }

    return ans;
}

int main(){

    int T= 0;
    cin>>T;
    while(T--){

        int P = 0 ;
        int N = 0 ;
        cin>>P>>N;

        int *cooks = new int[N];

        for(int i = 0 ; i < N; i++){
            cin>>cooks[i];
        }

        cout<<solve(cooks ,N , P)<<"\n";

        delete [] cooks;

    }

}