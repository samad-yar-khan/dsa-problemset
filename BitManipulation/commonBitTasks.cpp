
#include<iostream>
using namespace std;

bool isOdd(int a){
    return a&1;
}

int getBit(int number , int index){

    int mask = 1<<index; //index = 3 => 00001000 or 2^3
    int bit = (number & mask ) == 0 ? 0 : 1;
    return bit;
}

int setBit(int number , int index){
    int mask = 1<<index;
    int ans = number | mask;
    return ans;
}

int clearBit(int n , int i){
    int mask = ~(1<<i) ; //i =3 => ~(1000) => 0111
    int ans = mask&n;
    return ans;
}

int updateBit(int n ,  int i , int val){ 
    //n is the  number , i is the index , val is val 1/0 we wnat to update at index i

    //first we clear the bit at index i 
    int mask = ~(1<<i);
    int cleared_n = n&mask;
    // suppose n equals 10 => 1010 and i = 2 and val = 1
    //as its already 0 , here ot becomes 1010

    //now we set the bitat position i
    // now we do val<<i , if val=0 0<<i = 0 and there would be no change with or
    //if val ==1 , 1<<i (take i = 2 ) => 100 and 1010 | 100 == 1110 , ie what we needed 
    int set_bit = cleared_n | (val <<i);
    return set_bit;

}

//this will clear bits from indices i+1 to 0 (inclusve)
//or clears last i digits
int clearLastIBits(int n , int i){

    //cretae a maskk
    int mask = (~0) << i; //we can also do -1<<i and ~0 gives -1
    // int mask = (-1<<i);
    return mask & n;

}

//clearing bits in the range i to j 
int clearBits_i_to_j(int n , int  i , int j ){

    int ones = (~0); //all 1s
    int mask_part_1 = (ones<<(j+1)); //1111000000
    int mask_part_2 = (1<<i) -1; //   00000000011
    int mask = mask_part_1|mask_part_2; //11110000001
    int ans = n&mask;
    return ans;
}


int main(){
    // cout<<isOdd(7)<<"\n";
//     cout<<setBit(10,0);

    cout<<clearLastIBits(15 , 2); //1111 -> 1100
    cout<<'\n';
    cout<<sizeof(int)<<"size";
    cout<<clearBits_i_to_j(31 , 1, 3);

    return 0;
}