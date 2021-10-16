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

    int arr[8] = {0};
    int n =0;
    cin>>n;
    int one =0;
  
    for(int i =0; i < n ; i++ ){
        int a =0;
        cin>>a ;
        if(a==5 || a==7){
            cout<<-1<<"\n";
            return 0;
        }
        arr[a]++;
    }

    bool haveAns = (arr[1] == arr[2]+arr[3])&&(arr[2]+arr[3] ==arr[6]+arr[4]);
    if(!haveAns){
        cout<<-1<<"\n";
        return 0;
    }
    vector<vector<int>> ans;

    while(arr[6] > 0 ){
        arr[1]--;
        vector<int> v;
        if(arr[3] > 0){
           
           v.push_back(1);v.push_back(3);v.push_back(6);
            arr[3]--;
        }else{ 
          v.push_back(1);v.push_back(2);v.push_back(6);
            arr[2]--;
        }
        arr[6]--;
        ans.push_back(v);
    }
      while(arr[4] > 0 ){
          arr[1]--;
        vector<int> v;
        if(arr[2] > 0){ 
          v.push_back(1);v.push_back(2);v.push_back(4);
            arr[2]--;
        }
        arr[4]--;
        ans.push_back(v);
    }

    for(int i =0 ;i < 8 ; i++){
        if(arr[i]!=0){
            cout<<"-1\n";
            return 0;
        }
    }

    for(int i =0;i<ans.size() ;i++){
        for(int j =0;j < 3 ; j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<"\n";
    }




}

