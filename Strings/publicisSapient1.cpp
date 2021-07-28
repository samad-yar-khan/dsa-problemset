#include<bits/stdc++.h>
using namespace std;

int main(){
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

   int  n = 0 ;
   int q = 0 ;
   string s = {""};
   cin>>n;
    cin>>s>>q;
    

    int**freq =  new int*[n];
    for(int i = 0 ; i < n ; i++){
        freq[i] = new int[26];
        for(int j = 0 ; j < 26 ; j++){
            freq[i][j] = 0;
        }
    }
    

    for(int i = 0 ; i < n ; i++){

        int a = (int)(s[i] - 'a');
        
        freq[i][a] = 1; 
        if(i > 0){
            for(int j = 0 ; j < 26 ; j++){
                freq[i][j] += freq[i-1][j];
            }
        }
    }
 
    while(q>0){

        int l = 0 ;
        int r = 0;

        cin>>l>>r;
        int diff = r-l+1;
        int prevIndex = l-2;
        int lastIndex = r-1;

        int freq2[26] = {0};
        if(prevIndex == -1){
            for(int i = 0 ; i < 26 ; i++){
                freq2[i] = freq[lastIndex][i];
            }    
        }else{
            for(int i = 0 ; i < 26 ; i++){
                freq2[i] = freq[lastIndex][i] - freq[prevIndex][i];
            }  
        }

        int odd = 0;
        int even = 0;

        for(int i = 0 ; i <26 ; i++){
            if(freq2[i]%2 == 0){
                even++;
            }else{
                odd++;
            }
        }

        //no palindormes
        if(diff%2 == 0){
            if(odd!=0){
                q--;
                continue;
            }
        }else if(diff%2!=0){
            if(odd%2==0){
                q--;
                continue;
            }
        }
        int start = l-1 ;
        int end = r-1;
        
        string str(diff , '\0');


        for(int i = 0  ; i < 26 ; i ++){
            
            if(freq2[i] %2 != 0){
                s[(end-start)/2] = (char)(i+'a');
            }
            freq2[i] --;
            for(int j = 0 ; j < freq2[i] ; j+=2){
                s[start++] = (char)(i+'a');
                s[end--] = (char)(i+'a');
            }
        }


  
       cout<<s<<"\n";
        q--;

    }

    for(int i = 0 ; i < n ;  i++){
        delete [] freq[i];
    }
    delete [] freq;

}
