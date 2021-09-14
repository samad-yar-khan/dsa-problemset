#include<bits./stdc++.h>
using namespace std;


int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("../input.txt", "r" , stdin);
        freopen("../output.txt", "w", stdout);
    #endif
   
    //set vs multiset

    /*
    multiset<int> a;//here we ca store multiiple values of same value
    set<int> b;
    for(int i=10 ; i>=0 ; i--)
    {
        a.insert(i);a.insert(i);
        b.insert(i);b.insert(i);
    }

    for(set<int>::iterator itr=a.begin() ;  itr!=a.end() ; itr++){
        cout<<(*itr)<<" ";//we see only unique elemnts 
    }
    cout<<"\n";
    for(multiset<int>::iterator itr=b.begin() ;  itr!=b.end() ; itr++){
        cout<<(*itr)<<" ";//we see multiple elemnts of samer value
    }
    
    */

    //erase func - if we want to delete something from a  multiset and this is occuring multiple times , then we all occurances of the num gets erased

    int arr[] = {1,2,3,4,5,5,4,3,2,1};

    multiset<int> m(arr,arr + 10);

    for(auto i = m.begin() ; i != m.end() ; i++){
        cout<<*(i)<<" ";
    }

    m.erase(3);
    cout<<"\n--after erasing 3--\n";//all occurance sof 3 gets erased from set

    for(auto i = m.begin() ; i != m.end() ; i++){
        cout<<*(i)<<" ";
    }

    cout<<"\n--after inmserting 8 and 9-\n";
    m.insert(9);
    m.insert(8);

    for(auto i = m.begin() ; i != m.end() ; i++){
        cout<<*(i)<<" ";
    }

    //we cant get count of a number aswell 

    cout<<"\nCount of 4 in the multiset is "<<m.count(4)<<'\n';

    //find functions helps us get the first iterator to the first occurance of the elemnt in the mutiset

    multiset<int>::iterator pos = m.find(4);
    cout<<"first occurance of 4 is at posn "<<(*pos)<<'\n';

    //get all elemnts eqal to 4 and get two iterartors to get the range in whcih they exist

    pair<multiset<int>::iterator , multiset<int>::iterator> p=m.equal_range(4);
    m.insert(3);
    m.insert(4);
    m.insert(4); m.insert(4); m.insert(4);
    for(auto itr = p.first ; itr != p.second ; itr++){
        cout<<*itr<<" ";
    }

    //loeert bound and upper bound

    cout<<"\n";
    cout<<"[2,5)\n";
    for(auto itr = m.lower_bound(2) ; itr!= m.lower_bound(5) ; itr++){
        cout<<*itr<<' ';
    }
    cout<<"\n[2,5]\n";
    for(auto itr = m.lower_bound(2) ; itr!= m.upper_bound(5) ; itr++){
        cout<<*itr<<' ';
    }
}
