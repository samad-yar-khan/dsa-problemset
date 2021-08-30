#include<bits/stdc++.h>
using namespace std;


/*
https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1#
the logic is that we need to accodomoate all trains , so ,make a pair of arrival and departure times ,
so we sort the trains acoordng to the arrival time , then we need to make a pq and puhs the departure time
in a queue , so i push oone train into my quque, and that acts as my stataion , iit will return me the min time at which
a platform wull get free , this is the greedy way to acodmodate more trains , now you have to get the next arriving training , and 
if the station that gets free early cant acoomodate your next tarin , you need another platform and you push this trains end time in the pq , denoting freeing time
of the station , 
incase our min time at which our station gets free , we pop it off and push this trains dpearture time in the pq , sort of updating
the station time
*/
int findPlatform(int arr[], int dep[], int n){
    	// Your code here
    	vector<pair<int,int>>trains ;
    	for(int i = 0  ; i < n ; i++){
    	    trains.push_back(make_pair(arr[i] , dep[i]));
    	}
    	
    	stable_sort(trains.begin() , trains.end());
    	priority_queue<int , vector<int> , greater<int>> pending ;
    	
        pending.push(trains[0].second);
        
        for(int i = 1 ; i < n ; i++){
            int vacantStation = pending.top();
            if(vacantStation < trains[i].first){
                pending.pop();
                pending.push(trains[i].second);
            }else{
                pending.push(trains[i].second);
            }
        }
        
    	return pending.size();
    	
}