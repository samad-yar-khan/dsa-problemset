//https://www.spoj.com/problems/BUSYMAN/
#include <bits/stdc++.h>
using namespace std;

int main() {
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
		
	int T = 0 ;
	cin>>T;
	while(T--){
			
		int n = 0;
        cin>>n;
		pair<int , int>* arr = new pair<int ,int>[n];
			
		for(int i = 0 ; i< n ; i++){
			
            int s = 0,e=0;
            cin>>s>>e;
           	pair<int,int>p(e ,s);
            arr[i] = p;
		}
		
        sort(arr , arr+n);
        int et =0 ;int c =0;
        for(int i = 0 ; i < n ; i++){
            if(et <= arr[i].second){
                et = arr[i].first;
                c++;
            }
        }


        cout<<c<<"\n";
		delete [] arr;
	}
	
	return 0;
}