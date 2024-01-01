#include <bits/stdc++.h>
using namespace std;
#define modVal 1000000007
#define ll long long

// https://leetcode.com/problems/find-longest-special-substring-that-occurs-thrice-ii/

void fill_grid(vector<vector<int>>& grid, char c, int len){
    int ind = c-'a';
    int l = len;
    int count = 1;
    while(l>0){
        grid[ind][l] += count;
        count+=1;
        l-=1;
    }
}

int max_len(vector<vector<int>>& grid, int c){
    int ans =-1;
    for(int i =0;i<grid.size();i++){
        for(int j=0;j<grid[0].size();j++){
            if(grid[i][j]>=c){
                ans = max(ans,j);
            }
        }
    }
    return ans;
}

int maximumLength(string &s) {
    int n = s.length();
    vector<vector<int>>grid(26,vector<int>(n+1,0));
    int i =0;
    while(i<n){
        int j =i;
        while(s[i] == s[j] && j<n){
            j++;
        }
        fill_grid(grid,s[i], j-i);
        i=j;
    }
    return max_len(grid, 3);


}

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r" , stdin);
        freopen("../output.txt", "w", stdout);
    #endif
    

    int T= 0 ;
    cin>>T;
   
    while(T--){
        string s;
        cin>>s;
        cout<<maximumLength(s)<<"\n";
    }

}