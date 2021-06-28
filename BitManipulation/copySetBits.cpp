//https://practice.geeksforgeeks.org/problems/copy-set-bits-in-range0623/
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


    l--;r--; //indixes
    if(r-l+1 == 32){
        return (x|y);
    }
        //now we have to create a mask o length r-l+1 and shift it  l indice sy the left
    int mask= (1<<(r-l+1))  - 1; // 2^(r-l+1) - 1 // 11111 r-l+1 ttimes
        // no left /shift this mask
    mask = mask << (l);
        
    int maskWithSetBits = y&mask;
    int xWithSetBits= x|maskWithSetBits;
    return xWithSetBits;
       
        
}

        //15 11111111
        //2
        //
    int main(){
        
     
    }