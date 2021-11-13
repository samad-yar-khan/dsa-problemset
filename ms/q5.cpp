#include<bits/stdc++.h>
using namespace std;
#define ll long long

long long solve(vector<long long> arr , int n){

    // vector<pair<long long ,long long>> vec;
    vector<long long >vec = arr;


    // for(int i = 0 ; i < n; i++)
    // {
    //     vec.push_back(make_pair(arr[i],i));
    // }

    stable_sort(vec.begin(),vec.end());
    long long SGood=0 ;
    long long SBad=0;
    for(int i = 0 ;i < vec.size() ;i++){
        if(vec[i] == arr[i]){
            SGood+=vec[i];
        }else{
            SBad+=vec[i];
        }
    }
   

    return SGood-SBad;

}

int solve2(int* arr ,int n){

    int ans = -1000;
    for(int i = 0 ; i < n ; i++){
        // cout<<abs(ans)<<" ";
        if(abs(ans) > abs(arr[i])){
            ans = arr[i];
        }else if(abs(ans) == abs(arr[i])){
            if(ans < arr[i]){
                ans = arr[i];
            }
        }
    }
    return ans;
}


void mstPrims(vector<vector<int>> edges,  int V  , int E){

    bool*visited = new bool[V];
     int *parent = new int [V];
      int*wt=new int [V];
    for(int i =0 ; i < V ; i++){
        visited[i] = false;
        wt[i] = INT_MAX;
        parent[i] = -1;
    }
    

    wt[0]=-1;

    
    int edgeCount = 0 ;

    while(edgeCount < V){

        int cw = INT_MAX;
        int minVertex = 0;
        //min non viisted vertex dhundo
        for(int i = 0 ; i < V ; i++){
            if(cw > wt[i] && !visited[i]){
                cw = wt[i];
                minVertex = i;
            }
        }
        //marks it visited;
        visited[minVertex] = true;
        //go through all its non visited vertex and makeour node its parent if wt through is less than its current wt

        //we gothrough all connected vertices from our nodea and if 
        //the wt of that node is mmorpe than wt through us then,make us its parent and update wt;
        for(int i = 0 ; i<V ; i++){
            if(!visited[i] && edges[minVertex][i] != 0){
                if(edges[minVertex][i] < wt[i]){
                    wt[i] =  edges[minVertex][i] ;
                    parent[i] = minVertex;
                }
            }
        }   

        edgeCount++;

    }

    //print all nodes
    for(int i = 1 ; i < V ; i++){
        int node = i;
        int ourParent = parent[i];
        int weight = wt[i];

        cout<<min(ourParent,node)<<" "<<max(ourParent,node)<<" "<<weight<<"\n";

    }

    delete [] wt;
    delete [] parent;
    delete [] visited;

}   

void paths(vector<vector<int>> dis , int K ){

    int N= dis.size();


}


// public static void main(String[] args) {
// 	int k=2, n=4;
// 	 nums = {{0, 1, 15, 6},
// 					{2, 0, 7, 3},
// 					{9, 6, 0, 12},
// 					{10, 4, 8, 0}};
// 	System.out.println(getMinDistance(nums, k, n));
// }

int res = INT_MAX;
 int getMinDistance(vector<vector<int>>nums, int k, int n) {
	bool* visited = new bool[n];
	visited[0] = true;
	dfs(nums, visited, k, 0, 0);
    delete[] visited;
	return res;
}

void dfs(vector<vector<int>>& nums, bool* visited, int k, int cur, int tmp) {
	if(isAllVisited(visited , nums.size())) {
		tmp += nums[cur][k-1] + nums[k-1][0];
		res =min(res, tmp);
	}
	for(int i=0;i<nums.size();i++) {
		if(!visited[i]) {
			visited[i] = true;
			dfs(nums, visited, k, i, tmp + nums[cur][i]);
			visited[i] = false;
		}
	}
}

 bool isAllVisited(bool* visited ,int n) {
	for(int i = 0 ;i < n ; i++){
        if(!visited[i]){
            return false;
        }
    }
	return true;
}

//comlexity of building sieve = nloglogn;
//complexity of calculationg factors of each eleemnet n is log(n)
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r" , stdin);
        freopen("../output.txt", "w", stdout);
    #endif



    int T = 0;
    cin>>T;
    while(T--){

        // int K = 0 ;
        // int N = 0 ;
        // cin>>K;
        // cin>>N;
        
        // vector<vector<int>> distances(N, vector<int>(N,0));

        // for(int i = 0; i< N ; i++)
        // {
        //     for(int j  =0  ; j <N ; j++){
        //         cin>>distances[i][j];
        //     }
        // }

        int n = 0 ;cin>>n;
        vector<long long>vec;
        while(n--){
            long long a =0;
            cin>>a;
            vec.push_back(a);
        }
        cout<<solve(vec,vec.size())<<"\n";


    }
    
  
}

