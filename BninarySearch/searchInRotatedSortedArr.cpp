/*
https://practice.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1

Search in a Rotated Array 
Easy Accuracy: 50.95% Submissions: 14419 Points: 2
Given a sorted and rotated array A of N distinct elements which is rotated at some point, and given an element key. The task is to find the index of the given element key in the array A.

Example 1:

Input:
N = 9
A[] = {5, 6, 7, 8, 9, 10, 1, 2, 3}
key = 10
Output:
5
Explanation: 10 is found at index 5.
Example 2:

Input:
N = 4
A[] = {3, 5, 1, 2}
key = 6
Output:
-1
Explanation: There is no element that has value 6.
Your Task:
Complete the function search() which takes an array arr[] and start, end index of the array and the K as input parameters, and returns the answer.

Can you solve it in expected time complexity?

Expected Time Complexity: O(log N).
Expected Auxiliary Space: O(1).

Constraints:
1 ≤ N ≤ 107
0 ≤ A[i] ≤ 108
1 ≤ key ≤ 108

*/

#include<bits/stdc++.h>
using namespace std;


//te logic is tht we get two sorted halves
/*
[ 5 6 7 1 2 3 4 ]
this an be seen as pts on a graps and two line signembts whih themselve are sorted
[5 6 7 ] and [1 2 3 4]
our start =0 and end = len-1
now we need to calcaalte mid 
mid = (s+e)/2;

now mid can either lie in part 1 or part 2
if mid lies in part 1  (part 1 -> arr[mid] >= arr[s])
    now if(key < arr[mid] && key >= arr[s]){
        this will meean that my key definetly lies in the left half od segment 1 
        and we put e =  mid -1 
    }else{
        key is in unsirted segmnet
        s = mid+1
    }
if mid lies in segment 2 
    if(k > arr[mid] and k <= arr[e]){
        s = mid+1
    }else{
        e = mid-1
    }
*/


 int search(int arr[], int l, int h, int k){
       int s = l ,  e = h ;
    
    while(s <= e){
            
        int mid = (s+e)/2;
        
        //specia case
        if(arr[mid] == k){
            return mid;
        }
        
        if(arr[mid]>=arr[s]){ //middle eemnt in left sorted part
            if(arr[mid] > k && arr[s]<=k ){
                e=mid-1;
            }else{ //oes not lie in left soretd segment
                s = mid+1;
            }
        }else{//mid in second sorted segmenr
            if(arr[mid] < k && arr[e] >= k ){
                s=mid+1;
            }else{
                e=mid-1;
            }
        }
    }
     
     return -1;   
    }




