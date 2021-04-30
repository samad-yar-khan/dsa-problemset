#include<iostream>
using namespace std;


int keypad_ans(int num , string output[] , string keys[]){

    if(num<=1){//on keypad 0 and 1 dont have characters
        output[0] = "";
        return 1;
    }


    //nowe we devide the work
    int our_digit = num%10;
    int remaining_num = num/10;

    //ih
    int small_output = keypad_ans(remaining_num , output , keys ); //ths will give m numbe rof combination 
    //now we check hoe many chars our digit hsas
    int our_chars = keys[our_digit].length(); //n

    //is

    //we will have m*n ans 
    //abc hai hamra to ehele bc ko append karte hai
    int current_index = small_output;
    for(int i = 1  ; i < our_chars ;  i++){//to go through our keys
        for(int j = 0 ; j < small_output ; j ++){//to go through small_outputs 
            output[current_index] = output[j] + keys[our_digit].at(i);
            current_index++;
        }
    }

    for(int j = 0 ; j < small_output ; j ++){//to go through small_outputs 
            output[j] = output[j] + keys[our_digit].at(0);
           
    }

    return small_output*our_chars;



}



int keypad(int num, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    string key [] = {"" , "" , "abc" , "def" , "ghi" , "jkl" , "mno" , "pqrs" , "tuv" , "wxyz" };
    return keypad_ans(num , output , key);
}


int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
