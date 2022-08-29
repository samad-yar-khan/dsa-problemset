#include<bits/stdc++.h>
using namespace std;

long long getTotalEfficiency(vector<long long>skill) {
    // Write your code here

    sort(skill.begin(),skill.end(),greater<int>());
    long long left = 0, right = skill.size()-1;
    long long sum = 0;
    for(int i =0;i<skill.size();i++){
        sum+=skill[i]*1LL;
    }
    sum/=(skill.size()/2);
    long long efficiencySum = 0;
    while (left < right) {
        if (skill[left] + skill[right] != sum) return -1;
        efficiencySum += skill[left] * skill[right];
        left++;
        right--;
    }
    return efficiencySum;
}

int main(){
    int t =0;
    cin>>t;
    while(t--)
    {
        int n =0;
        cin>>n;
        vector<long long>v(n,0);
        for(int i =0;i<n;i++){
            cin>>v[i];
        }
        cout<<getTotalEfficiency(v)<<"\n";
    }
    return 0;
}