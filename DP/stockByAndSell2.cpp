//https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/

#include<bits/stdc++.h>
using namespace std;

//https://www.geeksforgeeks.org/maximum-difference-between-two-elements/
void printArr(int *arr , int  n){
    cout<<"----ARRAY-----\n";
     cout<<"\n[ ";
    for(int i =0;i< n ; i++){
       
        cout<<arr[i]<<",";
       
    }
     cout<<" ]\n";
}

//the logic was to buy at minimas and selll at local maximas .
//but the logic can be simplifies . if the price the dau before was smaller than todat,then we just buy the day before and sell today
//so if we are on an increaisng curve , we can buy and sell evenry day and it woulnt make a diff becaue we recah the same profit , just in steps
//ex  [5 2 3 4 8 5 6 10]
//here the local minimaa is 2(buy) and then the maxima is 8 (we sell here) , then the stock falla md the mimina , the netx minima is 5 (buy) and we sell at 10
//so ans - (8-2) + (10-5) = 11
//but what if we sell , and buy whenever w can make profit , becasue at the nd it will accumulate the same way
//(3-2) + (4-3) + (8-4) => 6 and now for the otehr upwards curve (6-5) + (10-6) => 5 , in total the aans is 11  

  int maxProfit(vector<int>& p) {
        int n = p.size();
        int ans=0;
        for(int i = 1 ;i < n ; i++){   
            if(p[i]-p[i-1] > 0){
                ans += (p[i]-p[i-1]);
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

    
}
