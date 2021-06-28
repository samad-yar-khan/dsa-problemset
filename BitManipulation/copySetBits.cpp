#include<iostream>
using namespace std;
#include<stack>

void showBits(int a){
    stack<int> s;
    while(a>0){
        if(a&1){
            s.push(1);
        }else{
            s.push(0);
        }
        a=a>>1;
    }

    while(!s.empty()){
        cout<<s.top();
        s.pop();
    }

    cout<<"\n";
}

 int setSetBit(int x, int y, int l, int r){
        // code here
        l--;
        r--;
        if(r-l == 32){
            return x|y;
        }

        int ones = ~0;
        int leftMask = ones<<(r+1);
        int rightMask = (1<<l) - 1;
        int mask = (leftMask|rightMask);
        showBits(mask);
        int revMask = ~mask;


        int mask2 = revMask&y;
    
        int ans = mask2|x;
        return ans;
        // 100000000 
        // 1000000000 
        
    }

    int main(){
        cout<<setSetBit(44 , 3 , 2,5);
     
    }