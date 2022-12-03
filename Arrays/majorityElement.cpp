#include<bits/stdc++.h>
using namespace std;

//boyer moores voting algo
/*
    Think of this array as a collection of votes from the voters for different political parties.
Now as we know the party which has >50% votes can form the government.

So , our above question is analogous to this situation.
Now , if we are certain that one party has > 50% votes . Then , if :

We increment a count variable every time we see the vote from the majority party and decrement it whenever a vote from some other party is occured , we can guarantee that ,
count>0.

Using the above logic ,

Create a count=0 and a majority variable that stores the current majority element.
Traverse the array , and if count =0 , then store the current element as the majority element and increment the count.
Else , if the current element is equal to the current majority element , increment count , else decrement it.
At the end return the majority element.
This approach works because ,

We simply know that the majority element has a frequency greater than half of the total elements.
So , the value of count > 0.
But whenever it becomes 0 , it means that till now the majority element has either not occured , or if it has then the its frequency is equal to the sum of frequency of rest of the others. So , the next element will be the majority element till now . But eventually by the end , the final answer will always be the majority element of the array , as when the "count" becomes 0 for the final time , the next element will be the majority element.

*/

    int majorityElement(vector<int>& nums) {
        
        int majorityElement = nums[0];
        int elementFrequency = 1;
        
        for(int i = 1 ; i < nums.size() ; i++){
            if(majorityElement!=nums[i]){
                elementFrequency--;
            }else{
                elementFrequency++;
            }    
            if(elementFrequency<=0){
                //reset
                majorityElement = nums[i];
                elementFrequency=1;
            }
        }
        int freq = 0;
        for(int i =0 ;i< nums.size() ; i++){
            if(majorityElement==nums[i]){
                freq++;
            }
        }
        
        
        if(freq > nums.size()/2){
            return majorityElement;
        }
        return -1;
        
    }