#include<bits/stdc++.h>
using namespace std;

//https://practice.geeksforgeeks.org/problems/maximum-product-subarray3604/1

//thus problem  can be done in easily in n2/n3 time and we can do this bby calculatingg the products of each subse and the get the max at the end  . we cant reall use a preprod , becaue , of all the zeros,
// now we can actaully opimsie this to on by seinddg what we need , when i a m at i  , i need a ki wwhas the max till now , i can see what is the max that is endin at me , what is the min that ednig at me , 
// now using my value , i relcaultlate and , min and max , we need min and max at each sep becasue eitehr of thsoe can convet into a max or a miin , by a multiplaation with angetaive number
//ex -1999 and we get -1 , it gets changed to 199 and rachees mac , similiarly max to min amd wet the and
//zero will disrupt things and hence we handle for zero

	long long maxProduct(vector<int> arr, int n) {
	    // code here
	       
	       long long m = arr[0];//min till min i-1th index 
	       long long M = arr[0];//max till my i-1th index 
	       long long ans = arr[0];//ans till now 
	       for(int i = 1 ; i < n ; i++){

                long long z = 0;
                //0  pe kya hoga , ki mere mere min max 0 hojayenge , but unhe 1 raakhne zada helpful hoga,taki mujhe agey nehative milpaye
                if(arr[i] == 0){
                    ans=max(z,ans);
                    m=1;
                    M=1;
                    continue;
                }
                                
	            long long num = arr[i];
	            long long a = num*m;//the min continius product till [i],including i
	            long long b = num*M;//the max continues till i,including i
	            
	            ans = max(max(ans,a),max(num,b));
	            M = max(a,max(num,b));//final max product till ith
	            m = min(a,min(num,b));//final min prroduct till ith index
	            
	           
	       }
	       
	       return ans;
	       
	       
	}



