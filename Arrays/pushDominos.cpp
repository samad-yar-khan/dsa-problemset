#include<bits/stdc++.h>
using namespace std;
//https://leetcode.com/problems/push-dominoes/
//bfs
    string pushDominoes_bfs(string dominoes) {
        int n = dominoes.length();
        vector<int>time(n,INT_MAX);
        string s(dominoes);
        queue<pair<pair<int,int>,char>>q;
        for(int i=0;i<n;i++){
            if(dominoes[i] != '.'){
                q.push(make_pair(make_pair(i,0),dominoes[i]));
                time[i] = 0;
            }
        }
        
        while(!q.empty()){
            pair<pair<int,int>,char> f = q.front();q.pop();
            int ind = f.first.first;
            int timec = f.first.second;
            char move = f.second;
            if(time[ind]>timec){
                time[ind] = timec;
                s[ind] = move;
            }else if(time[ind]==timec){
                if(s[ind] != move){
                    s[ind] = '.';
                    continue;
                }
            }
            
            if(move == 'L' &&ind -1 >=0 && time[ind-1] > timec){
                q.push({{ind-1,timec+1},move});
            }
             if(move == 'R' && ind +1 <n && time[ind+1] > timec){
                q.push({{ind+1,timec+1},move});
            }
        }
        return s;
    }

    //two pointer
    string pushDominoes(string dominoes) {
        int n = dominoes.length();
        int curr = 0;
        int right = -1;

        while(curr<n){

            if(dominoes[curr] == 'L'){
                int temp = curr-1;
                if(right == -1){
                    while(temp >=0 && dominoes[temp] != 'R' && dominoes[temp]!= 'L'){
                        dominoes[temp--] = 'L';
                    }
                }else{
                    right++;
                    while(right <n && temp>=0 && temp > right){
                        dominoes[temp--] = 'L';
                        dominoes[right++] = 'R';
                    }
                    right=-1;
                }
            }else if(dominoes[curr] == 'R'){
                if(right == -1){
                     right=curr;
                }else{
                    while(right<curr && right<n){
                        dominoes[right++] = 'R';
                    }
                }
               
            }
            curr ++;
        }
        if(right != -1)
        {
            while (right < n)
            {
                dominoes[right++] = 'R';
            }
        }
        return dominoes;
    }