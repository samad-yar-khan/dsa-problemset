#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll modVals = 10e9 + 7;


//the logic negine it was that , till we have more than one odd we cant have  apalindrom
//if we have evns , we make the remove the max frreq evenm chat
//else male the max freq odd char even

int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
     #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r" , stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    int n =0 , m =0, k=0;
    cin>>n>>m>>k;
    vector<vector<int>> mat(n , vector<int>(m,0));

    vector<int> row_ind(n,0);
    vector<int> col_ind(m,0);
    for(int i =0 ; i< n ; i++){
        for(int j =0; j < m ; j++){
            cin>>mat[i][j];
        }
    }
    for(int i =0;i<n;i++){
        row_ind[i] = i ;
    }
    for(int j  =0 ;j < m;j++){
        col_ind[j] =j;
    }
    vector<int> ans;
    for(int i =0; i < k ; i++){
        char op;
        int x=0;int y =0;
        cin>>op>>x>>y;
        if(op=='r'){
            swap(row_ind[x-1],row_ind[y-1]);
        }else if(op == 'c'){
            swap(col_ind[x-1],col_ind[y-1]);
        }else{
            ans.push_back(mat[row_ind[x-1]][col_ind[y-1]]);
        }
    }

    for(int i =0;i<ans.size() ;i++){
        cout<<ans[i]<<"\n";
    }
   

}