#include<bits/stdc++.h>
using namespace std;


//https://binarysearch.com/room/Kadane's-Room-IVvA8yd7eg?questionsetIndex=0
string solve(string s, int k) {
    if(s.length() == 0){
        return s;
    }
    if(k<=1){
        string ans;
        return ans;
    }
    stack<pair<char,int>>st;
    int i =0;
    while(i<s.length()){

        if(st.size() == 0){
            st.push({s[i],1});
        }else{

            if(st.top().first == s[i]){
                int c  = st.top().second;
                c++;
                st.pop();
                if(c<k){
                    st.push({s[i],c});
                }
            }else{
                st.push({s[i],1});
            }

        }
        i++;
    }
    string ans{""};
    while(st.size()>0){
        pair<char,int>p=st.top();st.pop();
        string t(p.second,p.first);
        ans+=t;
    }
    reverse(ans.begin(),ans.end());
    return ans;
}