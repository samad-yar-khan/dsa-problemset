#include<bits/stdc++.h>
using namespace std;
//https://www.hackerearth.com/problem/algorithm/wine-bottles-8df9effe/

//we need to beat our friend ans maximise our chances by playing optially hence we choose bakctracking and dp
//instead of a greedy approach

int maxWine(int*arr , int i , int j , int**dp , int turn , int* presum){

	//edge case 
	if(i > j ){
		return INT_MAX;
	}

	//only one bottle
	if(i==j){
		return arr[i];
	}

	if(dp[i][j]!=-1){
		return dp[i][j];
	}

    int case1 = maxWine(arr ,i+1 , j, dp , turn+1 , presum);
    int case2 = maxWine(arr , i , j-1 , dp ,turn+1  , presum);
	
    //c1 and c2 willbe what my opponent can make 
    //i will try to minimise his amount
    int x = i-1;
    int s = 0 ;
    if(x<0){
        s=presum[j];
    }else{
        s=presum[j] - presum[x];
    }
    dp[i][j] =  s -min(case1 , case2);
    return dp[i][j];
}

int main(){

	ios_base::sync_with_stdio(false);;
	cin.tie(NULL);

	int T = 0 ;
	cin>>T;
	while(T--){

		int N = 0 ;
		cin>>N;
		int*arr = new int [N];
		for(int i=0 ;i < N ; i++){
			cin>>arr[i];
		}

        int*preSum =  new int[N];
        int s=0;
        for(int i =  0 ; i < N; i++){
            s+=arr[i];
            preSum[i] = s;
        }
        int**dp = new int*[N];
        for(int i = 0 ; i < N; i++){
            dp[i] = new int[N];
            for(int j = 0 ; j < N ; j++){
                dp[i][j] = -1;
            }
        }

        cout<<maxWine(arr , 0 , N-1 , dp , 0  , preSum)<<'\n';


		// cout<<L<<"\n"
        delete [] preSum;
		delete [] arr;
        for(int i = 0 ; i < N ;i++){
            delete [] dp[i];
        }
        delete [] dp;   
	}

	return 0;

}