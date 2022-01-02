#include<bits/stdc++.h>
using namespace std;

// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/

//the logic is that we only need ti del with moduosof 60 of eaach number , becaus ethe rest part of the numbers is aleady divible by 60
/*

    [[30,20,150,100,40]]=>%60=> [[30,20,30,40,40]]

    THIS TELLS IS THAT WE ONLY NEED TO DEAL WITH THE PARTY OF THE NUMBER WHICH IS NON DIVICVLE BY 60

    NOW WE SORT THE ARRAY AND TRY TO USE TWO POINTER TO GET THE SUM TO 60

    THE EXCEPTION IS WHEN THE NUMBER ITSELF IS DIVISBLE BY 60 , THEN WE CAN TAKE ANY OF THOSE 2 NUMBERS,  THE MOD OF THESE NUMBERS WITH 60 WILL BE ZERO

    HENCE IN OUR final array if the number of zeros is n_z , we have n_zC2 pairs of numebr divisble 60 , dute to these,
    theese wont go with any other value to form a num divivbke by 60

    the sepocnd exception is to fin d the number of 30s , and if number of 30s is n_t

    we add n_tC2 to our ans

    the rest we ca,lculate using two pointe on the sprted array


    THE SECOND E

*/

int numPairsDivisibleBy60(vector<int>& time) {
                
        int n = time.size();
        int zeros=0;
        int thirties =0;
        
        for(int i = 0 ; i < time.size() ;i++){
            time[i]%=60;
           if(time[i] == 30){
               thirties++;
           }
            if(time[i] == 0){
                zeros++;
            }
        }        
        
        int ans =0;
        ans+=((zeros*(zeros-1))/2);
        ans+=((thirties*(thirties-1))/2);
        
        sort(time.begin(),time.end());
        int count =0;
        int i =0;
        int j =n-1;
        
        vector<int>freq(501,0);
        while(i<n && time[i]==0){
             i++;
        }
        while(i<=j){
            
         
            if(time[i] ==30 || time[j] == 30){
                while(i<n && time[i] == 30){
                    i++;
                }
                while(j>=0 && time[j] == 30){
                    j--;
                }
            }else{
                
                            
                if(time[i]+time[j] == 60){
                    int c1=0;
                    int c2=0;
                    int i_=i;
                    int j_ = j;
                    while(i_<n && time[i_]==time[i]){
                        i_++;
                        c1++;
                    }
                    while(j_>=0 && time[j_]==time[j]){
                        j_--;
                        c2++;
                    }
                    ans+=(c1*c2);
                     i=i_;
                     j=j_;
                }else if(time[i]+time[j] > 60){
                    int j_=j;
                    while(j_>=0 && time[j_]==time[j]){
                        j_--;
                    }
                    j=j_;
                }else{
                    
                    int i_=i;
                    while(i_<n && time[i_]==time[i]){
                        i_++;
                    }
                   i=i_;
                }
               
                
            }

            
        }
        return ans;
    }