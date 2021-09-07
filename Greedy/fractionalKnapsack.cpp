#include<bits/stdc++.h>
using namespace std;
//https://practice.geeksforgeeks.org/problems/fractional-knapsack-1587115620/1#
/*
We can destroy the ites , so why dont we divide easch object to a unit wt and then see how what is the per-unit value  of each ibject , we sort by perunit value and take objects if they are within the wt limit , else we divite it into parts and get that value of the item which we can get with the left over wt
*/

struct Item{
    int value;
    int weight;
};

 static bool comp(Item a , Item b){
        double aVal = a.value;
        double aWt = a.weight;
        
        double bVal =  b.value ;
        double bWt = b.weight;
        
        double perUnitValueA = aVal/aWt;
        double perUnitValueB = bVal/bWt;
        
        return perUnitValueA > perUnitValueB;
    }
    
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr , arr+n , comp);
        
        double ans =0;
        double wt = W;
        int i = 0;
        while(i < n && wt > 0){
            double valItem = arr[i].value;
            double wtItem = arr[i].weight;
            
            if(wt >= wtItem  ){

                ans += valItem;
                wt -= wtItem;
               
            }else{
               
                double perUnitVal = valItem/wtItem;
                ans += (wt*perUnitVal);
                wt-=wtItem;
                
            }
            i++;
        }
        
        return ans;
        
    }