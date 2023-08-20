#include<bits/stdc++.h>
using namespace std;

/*
My initital approaches
- I thought I would just use something like topological sort. I would treat beforeItems as a graph.
- We would perform DFS from 0 to n for non visited nodes, in each call, I would let recursion fill the final_array with elemnts that belong before me
and then I would add my intiger to the final array. Then I would call dfs on the numbers of my group. 
- This method was incorrect because although it ensured that order is preserved it would not ensure that elements of the same group stay together.

Final Approach
- Something like doing topoligical sort twice. I would make two graphs, one for individual elments and the other for our groups.
- I would first call DFS and make sure that items of indivual groups have corect order by calling dfs on each groupsd and obtaining arrays for each groups.
- Then I would treat these groups  as items and try to arrange them based on our component graph.
- Finally, replace these component indexes with actual arrays of each group. 
- Our formation would fail if any of the dfs leads to a cycle. 
*/

bool dfs_comps(int curr, vector<bool>&down, vector<bool>&vis, vector<set<int>>&g, vector<int>&final_array){

    if(vis[curr] || down[curr]){
        return !(vis[curr] && down[curr]);
    }
    vis[curr] = true;
    down[curr] =true;

    bool is_v = true;
    for(auto i =g[curr].begin();i!=g[curr].end();i++){
        is_v = dfs_comps(*i, down, vis, g, final_array);
        if(!is_v){
            break;
        }
    }
    final_array.push_back(curr);
    down[curr] =false;
    return is_v;
}
bool dfs(int curr, vector<bool>&down, vector<bool>&vis, vector<vector<int>>&g, vector<int>&final_array, set<int>&curr_set){

    if(vis[curr] || down[curr]){
        return !(vis[curr] && down[curr]);
    }
    vis[curr] = true;
    down[curr] =true;

    bool is_v = true;
    for(int i =0;i<g[curr].size();i++){
        if(curr_set.find(g[curr][i]) == curr_set.end()){
            continue;
        }
        is_v = dfs(g[curr][i], down, vis, g, final_array, curr_set);
        if(!is_v){
            break;
        }
    }
    final_array.push_back(curr);
    down[curr] =false;
    return is_v;
}

vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems){
    
    set<int> blank_set;
    vector<set<int>>group_items(m,set<int>());
    for(int i=0;i<n;i++){
        if(group[i]==-1){
            set<int>new_set;
            new_set.insert(i);
            group_items.push_back(new_set);
            group[i] = group_items.size()-1;
        }else{
            group_items[group[i]].insert(i);
        }
    }

    vector<set<int>>component_graph(group_items.size(),set<int>());

    for(int i =0;i<n;i++){
        for(int j =0;j<beforeItems[i].size();j++){
            if(group[beforeItems[i][j]] == group[i]){
                continue;
            }
            component_graph[group[i]].insert(group[beforeItems[i][j]]);
        }
    }
    int components = component_graph.size();
    
    vector<bool>vis(n,false);
    vector<bool>down(n,false);
    vector<vector<int>>lists(components,vector<int>(0));
    bool is_v = true;
    for(int i =0;i<group_items.size();i++){
        vector<int>final_arr;
        set<int>curr_set = group_items[i];
        for(auto e = curr_set.begin(); e!=curr_set.end();e++){
            if(vis[*e]){
                continue;
            }
            is_v = dfs(*e,down, vis, beforeItems, final_arr,curr_set);
            if(!is_v){
                break;
            }
        }
        if(!is_v){
            break;
        }
        lists[i] = final_arr;
    }
    if(!is_v){
        return vector<int>(0);
    }
    vector<bool>vis2(components,false);
    vector<bool>down2(components,false);
    vector<int>fa1;
    for(int i =0;i<component_graph.size();i++){
        if(vis2[i]){
            continue;
        }
        is_v = dfs_comps(i,down2, vis2, component_graph,fa1);
        if(!is_v){
            break;
        }
    }
    if(!is_v){
        return vector<int>(0);
    }
    vector<int>fa;
    for(int i =0;i<fa1.size();i++){
        int c = fa1[i];
        for(int j =0;j<lists[c].size();j++){
            fa.push_back(lists[c][j]);
        }
    }
    return is_v?fa:vector<int>();
}

int main(){
     
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    fflush(stdout);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r" , stdin);
        freopen("../output.txt", "w", stdout);
    #endif

    int T=0;cin>>T;
    cout<<T<<" ";

    while(T--){
        
        int n=0;cin>>n;
        int m =0;cin>>m;
        vector<int>group(n,0);
        for(int i=0;i<n;i++){
            cin>>group[i];
        }

        vector<vector<int>>before;
        for(int i =0;i<n;i++){
            int number_items =0;
            cin>>number_items;
            vector<int>before_items(number_items);
            for(int j=0;j<number_items;j++){
                cin>>before_items[j];
            }
            before.push_back(before_items);
        }

        vector<int>ans = sortItems(n, m,group, before);
        for(int i=0;i<n;i++){
            cout<<ans[i]<<" ";
        }
        cout<<"\n";

    }
}