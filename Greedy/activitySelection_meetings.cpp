#include<bits/stdc++.h>
using namespace std;
/*
Now here we are given st and et . we need to fit oin max meeting , to wo meeting lo jo jaldi khatam ho .taki agli shuru karpao . So , we pake pairs of st an det , and sort meetings by et , we eant et to be min , kyuki jiutnui jaldi khtama ham utni meetimg karpayneg . we iniotiallyt set et = 0 , and update et whenever starting time of next meeting is is larger tha ouyr et , ie m nexct meetig , starts afte rus , now  as we hav sorted it, we klnow that optimally spekaing this would actuallt be our shorted meeting starting at that time. if starting tim eof this meetig is less than et of last meeting we , skip it
*/

//https://practice.geeksforgeeks.org/problems/n-meetings-in-one-room-1587115620/1#
 int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        pair<int , int > arr[100000];
        
        for(int i = 0 ; i <n ; i++){
            int a = end[i];
            int b = start[i];
            pair<int , int> p(a,b);
            arr[i] = p;
        }
        sort(arr, arr+n);
        
        int et = 0;
        int c = 0 ;
        int i = 0;
        while(i < n){
            if(arr[i].second > et){
                c++;
                et = arr[i].first;
            }
            i++;
        }
        return c;
        

        
        
    }

    