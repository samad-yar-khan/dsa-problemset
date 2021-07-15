#include<bits/stdc++.h>
using namespace  std;

//logic
/*

we use a min prioirity where we at first insert elements of each row 
we maintin the min and mav , and curr min and max value
now in each iteration we remove the min valur of our pq and enter the enxt elemnt of the same row in our ppq
if this elemnt is larger than our our max then we change our curr max to this number
now w eupdate the currmin to b ethe min elemnt in the pq 
now we calulate the diff(range) between curr max and curr min
if the the diff between our new min and max values is smaller than we uodate the val8ue of our 
overall min and max 
we will quit the loop as soon as we  reach the end of a loop as beyond that point , we cant do any change
to our ans because last elemnt of that row will be there and it cant be removed to cause a change 

beyond this point we cant change min as this elment and we must have atleast one elemnt from each row


*/

class compare{

    public:

    bool operator()(pair<int , pair<int,int>> p1 , pair<int , pair<int,int>>p2){ ///first elemnt is num , second is row , third is idndex

        return p1.first > p2.first;

    }

};

pair<int , pair<int , int>> makeElement(int value , int row , int index){

    pair<int,int> coordinates(row, index);
    pair<int , pair<int , int> > element (value , coordinates);
    return element;
}

pair<int,int> findSmallestRange(int arr[][N], int n, int k)
{

    int minVal = INT_MAX;
    int currMin = INT_MAX;
    int maxVal = INT_MIN ;
    int currMax = INT_MIN;

    int diff=0;
    priority_queue<pair<int , pair<int,int>> , vector<pair<int , pair<int,int>>> , compare> pq;
    for(int i = 0 ; i < k ; i++ ){
        minVal = min(arr[i][0] , minVal);
        maxVal = max(arr[i][0] , maxVal);
        pq.push(makeElement(arr[i][0] , i , 0));
        
    }
    
    diff=maxVal - minVal;
    currMin=minVal;
    currMax = maxVal;

    while(!pq.empty()){

        int topVal = pq.top().first;
        int row = pq.top().second.first;
        int col = pq.top().second.second;
        pq.pop();
       
        col ++;
        if(col >= n){
            break;
        }
        int nextNum = arr[row][col];
        pq.push(makeElement(nextNum , row , col));
        currMin = pq.top().first;
        currMax = max(currMax , nextNum);
        if(currMax  - currMin < diff){
            minVal = currMin;
            maxVal=currMax;
            diff = maxVal-minVal;
        }

    }

    pair<int,int> Ans(minVal , maxVal);
    return Ans;


}
    
    