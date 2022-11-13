#include <bits/stdc++.h>
using namespace std;
#define modVal 1000000007
#define ll long long

vector<pair<int,int>> solve(vector<int>&vec, vector<int>& qs){
    deque<int>dq;
    for(int i=0;i<vec.size();i++){
        dq.push_back(vec[i]);
    }
    int n = dq.size();
    vector<pair<int,int>> initialAns(2*n+1,{0,0});
    int i =0;

        while(i<2*n && dq.size()>1){
            int a = dq.front();
            dq.pop_front();
            int b = dq.front();
            dq.pop_front();
            initialAns[i] = make_pair(a,b);
            dq.push_back(min(a,b));
            if(a!=b){
                dq.push_front(max(a,b));
            }
            i++;
        }
        
        int a = dq.front();
        dq.pop_front();
        vector<pair<int,int>> afterThat(dq.size());
        i=0;
        while(dq.size()){
            afterThat[i]={a,dq.front()};
            dq.pop_front();
            i++; 
        }
        vector<pair<int,int>>ans;
        for(int i =0;i<qs.size();i++){
            if(qs[i]<2*vec.size()){
                ans.push_back(initialAns[qs[i]]);
            }else{
                int Q = qs[i] - 2*vec.size();
                ans.push_back(afterThat[Q%afterThat.size()]);
            }
        }
    
return ans;
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
        int n = 0;cin>>n;
        vector<int>vec(n,0);
        for(int i =0;i<n;i++)cin>>vec[i];
        int q =0;cin>>q;
        vector<int>qs(q,0);
        for(int i =0;i<q;i++)cin>>qs[i];
        vector<pair<int,int>>ans = solve(vec,qs);
        for(int i =0;i<ans.size();i++)cout<<ans[i].first<<" "<<ans[i].second<<'\n';
    }

}