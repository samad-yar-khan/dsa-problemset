#include<bits/stdc++.h>
using namespace std;


//here we mantain the min number of jumps we need to reach each ih step
//an unreachble step is represnted by -1
//initially steps are represnted by -1 excetpt index 0
//we start at index 0 and marks tthe elemnts it can cover , till wereached a preReached element
//while visiting at index , see if you can reach the end using it , if yes , then return (steps req to reach curr index + 1)
//if not viistable return -1;

//O(N) time and O(N) space
int jump(vector<int>& nums) {
       
        int n = nums.size();

        if(n<=1){
            return 0;
        }
      
        int* visitable = new int[n];
        
        for(int i = 0 ; i < n ; i++){
            visitable[i] = -1;
        }
        visitable[0] = 0;
        
        for(int i = 0 ; i< n ; i++){
            if(visitable[i]==-1){
                break;
            }
            int jumps=nums[i];
            if(i+jumps>=n-1){
                return visitable[i]+1;
            }
            
            while(jumps>0 && visitable[jumps+i]==-1){
                visitable[jumps+i] = visitable[i] +1;
                jumps--;
            }
        }
        
      return visitable[n-1];
}
//o1 space and on time
//https://leetcode.com/problems/jump-game-ii/discuss/18014/Concise-O(n)-one-loop-JAVA-solution-based-on-Greedy