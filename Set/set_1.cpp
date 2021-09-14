#include<bits/stdc++.h>
using namespace std;

int  main()
{

    // int arr[] = {1,2,3,4,1,2,3,4,1,2,4,7,24};

    // set<int> s;
    // for(int i = 0 ; i<13 ; i++){
    //     s.insert(arr[i]);
    // }

    // for(set<int>::iterator i =s.begin() ; i!=s.end() ; i++){
    //     cout<<*(i)<<" ";
    //     // cout<<*(s.lower_bound(i))<<" ";
    //     auto it = s.find(3);
    //     cout<<*it<<"\n";

    // }
    set<pair<int , int>> arr;
    arr.insert({1,2});
    arr.insert({1,3});
    arr.insert({1,4});
    arr.insert({2,2});
    arr.insert({2,2});
    arr.insert({1,2});
    arr.insert({1,2});
    arr.insert({3,2});
    for(auto i:arr){
        cout<<i.first<<" "<<i.second<<'\n';
    }
    auto a = arr.upper_bound({1,2});//ye hame {1,3} dega kyuki 1 same rakh ke secodn num badad dhundega wwow
    cout<<a->first<<" "<<a->second<<"\n";
    set<pair<int , int>>::iterator b = arr.upper_bound({1,INT_MAX});//ye 1 wale sare chodke next dhudnega
    cout<<b->first <<" "<<b->second<<"\n";

}




