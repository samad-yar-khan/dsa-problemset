#include<bits/stdc++.h>
using namespace std;

/*
CN LOGIC
our arr[i] shows the probability of success of a player who got the first chance with i coins in the stack
so what we know is that if there ar 1 , X or Y coins my probabilty of sucess is 100% hence as at all thes e would be 1
, now if we are at arr[i] we need to check the ans at arr[i-1] , which shoes whether person playng firstbhand at arr[i-1]
looses or wins , similiarly for arr[i-x] and arr[i-y] , we should the path where the next player looses , or indiirectly we win
 if  any of the 3 , is false , that ean the next player whos removing coins from that stack looses and we win 
 if all the thhree are true , mean the person whos playing after uss , will win no mater wwhat 
 hame aisa chalna hai ki hamara next banda hare , to ham wahi path lege jaha next bnda har rha hoga 
 if any of the paths is false , it means going down that path will lead us to vectory , and such path exist 
 soo arr[ i] becomes true 
*/

//brute
bool findWinnerHelper(int n,int x, int y){

    ///bc
    if(n == 1 || n == x || n== y ){
        return 1;
    }

    //ih
    bool case1 = findWinnerHelper(n-1 , x , y);
    bool case2 = false , case3 = false;

    if(n > x){
        case2 = findWinnerHelper(n-x,x,y);
    }
    if(n > y){
        case3 = findWinnerHelper(n-y,x,y);
    }

    return case1||case2||case3;

}

string findWinner(int n , int x , int y){
    string s1 = "Whis";
    string s2 = "Beerus";
    return findWinnerHelper(n , x, y) ? s2 : s1;
}



//memo
int findWinnerHelper_memo(int n,int x, int y ,int arr[]){

    ///bc
    if(n == 1 || n == x || n== y ){
        return 1;
    }

    if(arr[n] != -1){
        return arr[n];
    }
    //ih
    int case1 = findWinnerHelper_memo(n-1 , x , y ,arr);
    int case2 = 1 ; 
    int case3 = 1;

   if( n > x){
        case2 = findWinnerHelper_memo(n-x,x,y , arr );
   }
    if(n > y){
		case3 = findWinnerHelper_memo(n-y,x,y , arr);        
    }    
    
    if((case1==1)&&(case2==1)&&(case3==1)){
        arr[n] = 0;
    }else{
        arr[n] = 1 ;
    }
    return arr[n];

}

string findWinner_memo(int n , int x , int y ){
    
    int*arr = new int[n+1];
    for(int i = 0 ; i <= n ; i++){
        arr[i] = -1 ;
    }
    string s1 = "Whis";
    string s2 = "Beerus";
    
    string ans = (findWinnerHelper_memo(n , x, y , arr) == 1) ? s2 : s1;
    delete [] arr;
    return ans;
}

//dp

string findWinner_dp(int n , int x , int y ){
    
    bool*arr = new bool[n+1];
    for(int i = 0 ; i <= n ; i++){
        arr[i] = 0 ;
    }
    // at these eindices we can tell whether we won or loose in single operation
    arr[0] = false;
    arr[1]  = true;
    arr[x] = true;
    arr[y] = true;

    //no we buiild our ans from bottom to top 
    //from smaller values to larger values 

    for(int i = 1 ; i <= n ; i++){

        //aleady know ans to this
        if(i == 1 || i == x ||i == y){
            continue ;
        }

        bool case1 = true , case2 = true , case3 = true;
        //case1 
            case1 = arr[i-1];
        //case2 
            if(x < i){
                case2 = arr[i-x];
            }
        //case3 
        if(y < i){
            case3 = arr[i-y];
        }

        arr[i] = !(case1 && case2 && case3);

        //now these case1  , 2 ,3 tell us if the other opponent won (if they are true) , if the otehr oppeonet lost 
        //these will be false  if in all these cases my oponent widn , i ll loose 
        //if oponent loosed even ina a siglecase thn i wein

    }


    string s1 = "Whis";
    string s2 = "Beerus";
    
    string ans = (arr[n]) ? s2 : s1;
    delete [] arr;
    return ans;

}



