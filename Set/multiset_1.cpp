#include<bits./stdc++.h>
using namespace std;


int main(){
    
    multiset<int> a;//here we ca store multiiple values of same value
    set<int> b;
    for(int i=10 ; i>=0 ; i--)
    {
        a.insert(i);a.insert(i);
        b.insert(i);b.insert(i);
    }

    for(set<int>::iterator itr=a.begin() ;  itr!=a.end() ; itr++){
        cout<<(*itr)<<" ";
    }
    cout<<"\n";
    for(multiset<int>::iterator itr=b.begin() ;  itr!=b.end() ; itr++){
        cout<<(*itr)<<" ";
    }
}