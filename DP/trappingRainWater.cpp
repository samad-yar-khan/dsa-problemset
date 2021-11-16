#include<bits/stdc++.h>
using namespace std;

//https://practice.geeksforgeeks.org/problems/trapping-rain-water-1587115621/1#

//so what we do here is that we mantain a stakc wth indixes and valu =if bar
//we insert barts till iur curr bar is less th or prev bar
//as soonw e encouter a larger bar ,, we popm out our smaller bars , till stakc is ove or till new bvar become smaller tha the presnet bar
//nowthis will help us add the water presnt do to maximas mocing fowatrds
//now if we run of of bars , we will justr count the wqater stored . from last bar to the curr bar
//when we are donw eith insertion s
//we now pop out bars and calc water storeed on the right aside of our maximas 
//and dur to the left over bars

long long trappingWater(int arr[], int n){
        // code here
        vector<pair<int,int>>vec;
        int i =0;
        while(i < n && arr[i]==0){
            i++;
        }
        int j = n-1;
        while(j>=0 && arr[j] ==0){
            j--;
        }
        
        for(int i_ =i;i_<=j ;i_++){
            vec.push_back({arr[i_],i_});
        }
        
        
        
        stack<pair<int,int>>s;
        s.push(vec[0]);
        long long sub =0;
        long long ans = 0;
        i=1;
        while(i<vec.size()){
                
            if(s.top().first < vec[i].first){
                pair<long long,long long> last;
                long long sub =0;
                while(!s.empty() && s.top().first < vec[i].first){
                    last=s.top();
                    s.pop();
                    sub+=last.first;
                }
                if(s.empty()){
                    long long total= (vec[i].second -last.second-1)*last.first;
                    for(int k = last.second+1 ;k<vec[i].second ; k++){
                        total-=arr[k];
                    }
                    ans+=total;
                }
                s.push(vec[i]);
            }else{
                s.push(vec[i]);
            }
            i++;
        }
        
        if(s.size()==0){
          
            return ans;
        }
        pair<long long , long long>t=s.top();
        s.pop();
        while(s.size()>0){
            pair<long long , long long>t2=s.top();
            s.pop();
            long long total= (t.second -t2.second-1)*t.first;
            for(int k = t2.second +1 ;k<t.second ; k++){
                total-=arr[k];
            }
            ans+=total;
            t=t2;
        }
        // cout<<"hey";
        return ans;
        
        
        
    }