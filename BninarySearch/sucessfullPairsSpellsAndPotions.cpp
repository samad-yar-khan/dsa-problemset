#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/successful-pairs-of-spells-and-potions
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(),potions.end());
        vector<int>ans;
        for(int i =0;i<spells.size();i++){
            long long num = success/(1LL*spells[i]);
            if(success%(1LL*spells[i])) num++;
            int ind = potions.end()-lower_bound(potions.begin(),potions.end(), num);
            ans.push_back(ind);
        }
        
        return ans;
    }
    