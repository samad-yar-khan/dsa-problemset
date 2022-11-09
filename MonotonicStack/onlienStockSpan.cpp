#include<bits/stdc++.h>
using namespace std;

//https://leetcode.com/problems/online-stock-span/

class StockSpanner {
public:
    /*
        We need to calculate the continous dates from curr date where the temp is less
        We use the concept of monotonic stack
        A monotic stack which is decresing towards the top, will help us tack, how many days
        we first pop all elemnts where the price is less thane curr price . then insrt pair of price and date
        ex
        inp : 100 80 60 70 60 75 85
        op : [null,1,1,1,2,1,4,6]
        
        process:
        
        init stack = [{INT_MAX,0}]
        100 : updated stack = [{INT_MAX,0},{100,1}] -> return 1-0 = 1
        80 : updated stack = [{INT_MAX,0},{100,1},{80,2}] -> return 2-1 = 1
        60 : updated stack = [{INT_MAX,0},{100,1},{80,2},{60,3}] -> return 3-2 =1
        70 : updated stack = [{INT_MAX,0},{100,1},{80,2},{70,4}] -> return 4-2= 2
        60 : updated stack = [{INT_MAX,0},{100,1},{80,2},{70,4},{60,5}] -> return 5-4= 1
        75 : updated stack = [{INT_MAX,0},{100,1},{80,2},{75,6}] -> return 6-2= 4
        85 : updated stack = [{INT_MAX,0},{100,1},{85,7}] -> return 7-1= 6
        
    */
    stack<pair<int,int>> prices;
    int date;
    
    StockSpanner() {   
        stack<pair<int,int>>p;
        this->prices = p;
        this->prices.push({INT_MAX,0});
        date = 1;
    } 
    int next(int price) {
        int currInd = date;
        while(prices.size() && prices.top().first <= price){
            prices.pop();
        }
        int days = currInd - prices.top().second;
        prices.push({price,currInd});
        date++;
        return days;
    }

};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */