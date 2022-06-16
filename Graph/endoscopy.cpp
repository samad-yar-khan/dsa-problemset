//https://www.hackerearth.com/problem/algorithm/question-7-4/


#include <bits/stdc++.h>
using namespace std;

int X[8][4]={{0,0,0,0},
	{-1,1,0,0},
	{-1,1,0,0},
	{0,0,0,0},
	{-1,0,0,0},
	{0,1,0,0},
	{0,1,0,0},
	{-1,0,0,0}
};

int Y[8][4] = {{0,0,0,0},
{0,0,-1,1},
{0,0,0,0},
{0,0,-1,1},
{0,0,0,1},
{0,0,0,1},
{0,0,-1,0},
{0,0,-1,0}
};


int W[4][4] = {{1,2,5,6},{1,2,4,7},{1,3,4,5},{1,3,6,7}};


int main() {
	
	int T=0;cin>>T;
	while(T--){

		int N=0,M=0,R=0,C=0,L=0;
		cin>>N>>M>>R>>C>>L;

		vector<vector<int>>g(N,vector<int>(M,0));
		for(int i =0;i<N;i++){
			for(int j =0;j<M;j++){
				cin>>g[i][j];
			}
		}
		vector<vector<bool>>vis(N,vector<bool>(M,false));
		queue<pair<pair<int,int>,int>>p;
		p.push(make_pair(make_pair(R,C),L));
		if(L==0){
			cout<<0<<"\n";
			continue;
		}
		vis[R][C] = true;
		int c =0;
		while(p.size()){
		
			pair<pair<int,int>,int>t=p.front();
			p.pop();
			
			int x=t.first.first;
			int y=t.first.second;
			int l=t.second;

			// cout<<x<<"-"<<y<<"-"<<l<<"\n ";
			l--;
			
			if(g[x][y] ==0){
				continue;
			}
			c++;

			if(l==0){
				
				continue;
			}
				
			int el=g[x][y];
			for(int i =0;i<4;i++){

				int x_=x+X[el][i];
				int y_=y+Y[el][i];
			
				bool ins=false;
				if(x_>=0 && y_ >=0 && x_<N && y_<M &&  !vis[x_][y_] && g[x_][y_]!=0){
					for(int j=0;j<4;j++){
						if(g[x_][y_] == W[i][j]){
							ins=true;
						}
					}

					if(ins){
						vis[x_][y_] = true;
						p.push(make_pair(make_pair(x_,y_),l));
					}
				}
			}
			
			
		}
		cout<<c<<'\n';
		


	}

}