
// Prateek Bhaiya decided to give 100% scholarships to the needy students by taking an admission test. However in order to avoid any losses at the institute, he came up with a solution. Coding Blocks has N students and M discount coupons. A student will get 100% waiver if he gets X discount coupons.
// However in order to get more discount coupons in addition to those M , Bhaiya decided that some students who perform badly in the admission tests, need to pay additional amount equivalent to Y discount coupons, i.e. good students earn discount coupons and weak students need to pay coupons to get admission.
// Find out the maximum number of students who can get 100% waiver in their admission fees.
// Note : Bhaiya will try his best to give 100% discount to maximum students possible.

// Input Format
// The first line contains 4 integers N M X Y

// Constraints
// 1 ≤ N,M,X,Y ≤ 10^9​​

// Output Format
// The output should contain a single integer representing the maximum number of students who can get 100% discount.

// Sample Input
// 5 10 2 1
// Sample Output
// 5
// Explanation
// File 1: Since there are 5 students, and 10 available coupons, and each student needs just 2 coupons to get 100% discount, so Bhaiya already has the needed number of coupons, so all 5 students will get 100% waiver on their fees.
// File 2: There are 3 students. Bhaiya will give 100% discount to 2 students using the initial number of discounts, i.e. 8 out of 10 will get used. We need atleast 2 more coupons to give discount to the third student. Now if the third student pay additional amount equivalent to Y=2 coupons, we will get a total of 4 coupons in hand, however we can not use them for giving discount as all 3 students have been considered (2 for getting discount and 1 for paying additional amount).


#include<bits/stdc++.h>
#define ll long long
using namespace std;


int main(){

    ll N = 0 , M = 0 , X = 0 , Y = 0 ;


    cin>>N>>M>>X>>Y;

    ll si  = 0 ; //min umber of students who can get schlarship
    ll ei  = N ; //max number of scholarhsip a pperson can get
    ll ans = 0;

    while(si <= ei){
        ll mid = si + ((ei-si)/2) ;        
        //check if midnumer od  stsudnts can get scholarship
        //number of tickets needed for mid numbee of chilren
        ll numTokensNeeded = mid*X;

        ll tokensWeHave = M;
        //now take the coupond from children who didnt get scholarship
    	tokensWeHave = tokensWeHave + ((N-mid)*Y);

        if(numTokensNeeded <= tokensWeHave){
            ans = mid;
            si=mid+1;
        }else{
            ei=mid-1;
        }
    }

    cout<<ans<<"\n";
    return 0;

}