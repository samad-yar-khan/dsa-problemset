//https://practice.geeksforgeeks.org/problems/count-occurences-of-anagrams5839/
#include<iostream>
#include<string>
using namespace std;


int search(string pat, string txt) {
	// code here
    int pattern_char_frequencies[26]{0};
    int text_char_frequencies[26]{0};

    if(pat.length() > txt.length()){
        return 0;
    }

    for(int i = 0 ; i < pat.length() ; i++){
        int index = (int)pat.at(i) - (int)'a';
        pattern_char_frequencies[index]++;
    }

    int ptr1 = 0;
    int ptr2 = 0;

    while(ptr2 < pat.length()){
        int index = (int)txt.at(ptr2) - (int)'a';
        text_char_frequencies[index]++;
        ptr2++;
    } 

    ptr2--;
    int count = 0;
    while(ptr2 < txt.length()){

        int matches = 0 ;
        for(int i = 0 ; i < 26 ; i++){
            if(text_char_frequencies[i] == pattern_char_frequencies[i]){
                matches++;
            }
        }
        if(matches == 26){
            count ++;
        }
        //slide the window
        int index_ptr1 = (int)txt.at(ptr1) - (int)'a';
        text_char_frequencies[index_ptr1]--;
        ptr1++;

        
        ptr2++;
        if(ptr2 < txt.length()){
            int index_ptr2 = (int)txt.at(ptr2) - (int)'a';
            text_char_frequencies[index_ptr2]++;     
        }
         
    }

    return count ;


}

int main(){


    string pat , str ;
    cin>>pat>>str;
    cout<<search(pat,str);

}