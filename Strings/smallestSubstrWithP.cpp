 #include<bits/stdc++.h>

using namespace std;

//https://practice.geeksforgeeks.org/problems/smallest-window-in-a-string-containing-all-the-characters-of-another-string-1587115621/1#

  string smallestWindow (string s, string p)
    {
        
vector<int> v(26,0);
        int n=s.size();
        int m=p.size();
        for(int i=0;i<m;i++){
            v[p[i]-'a']++;
        }
       string ans="-1";
       int lenA = INT_MAX;
       
       int j=0;
       int x=0;
       int a ='a';
       for(int i =0;i<n ;i++){
           
           if(v[s[i]-a]>0){
               x++;
           }
           v[s[i]-a]--;
           
           if(x==m){
               
               while(j<i && v[s[j]-a]<0){
                   v[s[j]-a]++;
                   j++;
               }
               
               if(lenA > i-j+1){
                   lenA=i-j+1;
                   ans = s.substr(j,lenA);
               }
               
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
        int T=0;
        cin>>T;
        while(T--){
            string s ,p;
            cin>>s>>p;
            cout<<smallestWindow(s,p)<<"\n";
        }
    }