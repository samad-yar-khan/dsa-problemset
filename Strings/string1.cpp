#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

bool myComparator(string a , string b){

    if(a.length() == b.length()){
        return a<b;
    }

    return a.length() < b.length();

}

int main(){

    string arr[100];
    int n{0};
    cin>>n;
    for(int i = 0 ; i < n ; i++){
       cin>>arr[i];
    }
    sort(arr , arr+n , myComparator);
    for(int i = 0 ; i < n ; i++){
        cout<<arr[i]<<"\n";
    }




}



