#include<bits/stdc++.h>
using namespace std;

// https://practice.geeksforgeeks.org/problems/maximum-rectangular-area-in-a-histogram-1587115620/1
/*
Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. For simplicity, assume that all bars have the same width and the width is 1 unit.

Example 1:

Input:
N = 7
arr[] = {6,2,5,4,5,1,6}
Output: 12
Explanation: 

Input:
N = 8
arr[] = {7 2 8 9 1 3 6 5}
Output: 16
Explanation: Maximum size of the histogram 
will be 8  and there will be 2 consecutive 
histogram. And hence the area of the 
histogram will be 8x2 = 16.
*/

//O(N) logic

/*
a histogram bar can oly form areas wit histogranms of larger areas ,
we put indexes of bars in the stack
so  if we have a large bar after a small bar , the small bar ca utilise the large bar
to form some area , but the if thers a small bar after a large bar , the large bar cant use the small bar to form ant area
and we find the area for this bars ht 
so we pop off this bar and calculatcte the area for this bar
ifstack is sempty after pop , the area would be currentIndex*(ht of popped bar) 
if stack s not emty , it will utilsie the other bars by counting range form the prev lower , (stakc top)
and teh area  would be - (curr index - stack-top-1)*(ht of popped bar)
now we keep track of max , we keep doing this proces till the top bar ht becomes less than the current indexes bar
then we insert cur index

1)insert 0 into tthe stack //0th index
2)At each index , ht of curent eemnt is largrt than the elmnt represnted by stacks top idnex , push the curr index into the stack
3)if our current indices elemnt is smaller , do this till toop elemnt beomes smaller, we pop out the stacks top index and store it in topIndex  and calute area for that ht 

    -> if sttack empty after pop  => area = (ht[topIndex])*(currIndex)
    if stakc has some elmelent => area = (ht[topIndex])*(currIndex - stack.top() -1);
    now max_ht  =max(max_ht , area);
4)once top becomes saller than the current indces ht we insrt currnet_index and do 
current_index ++

5)if loop ends because currentIndex becomes eqal to array size 

we keep calculateing area for each ht as metioned above till stakc is empty 


*/

 long long getMaxArea(long long arr[], int n)
    {
        // Your code here
        long long ans = 0 ;
        
        stack<long long> heights;
        heights.push(0);
        
        int i = 1;
        while(i < n){
            
            if(arr[heights.top()] < arr[i]){
                heights.push(i);
            }else{
                while(!heights.empty() && arr[heights.top()] > arr[i]){
                    
                    int top_index = heights.top();
                    heights.pop();
                    long long thisHtsArea=0;
                    if(!heights.empty()){
                         thisHtsArea = (arr[top_index])*(i-heights.top()-1);
                    }else{
                         thisHtsArea = (arr[top_index])*(i);
                    }
                    
                    ans = max(ans , thisHtsArea);
                    
                }
                heights.push(i);
            }
            
            i++;
            
        }
        while(!heights.empty()){
             int top_index = heights.top();
            heights.pop();
                long long thisHtsArea=0;
                    if(!heights.empty()){
                         thisHtsArea = (arr[top_index])*(i-heights.top()-1);
                    }else{
                         thisHtsArea = (arr[top_index])*(i);
                    }
                    
                    ans = max(ans , thisHtsArea);
        }
        return ans;
    } 