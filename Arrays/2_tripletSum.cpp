#include <bits/stdc++.h>

using namespace std;

//two pointer method 

int countTriplet(int arr[], int n)
{   
    //sort the array
    std::sort(arr  , arr+n);

    int triplets{0};
    //i will make sure that one of the three digits required  to make the triplet
    //arr[i] + arr[j] == arr[k] is fixed over each iteration so that we only have to wokr on setting
    //the remain two pointer in right posn to achieve the trplet
    for(int i{0} ; i < n-2 ; i++){

        int j = i+1;
        int k = i+2;
        while(k<n){

            if(arr[i] + arr[j] == arr[k]){ ///our condition
                triplets++;
                j++;
                k++;
            }else if(arr[i] + arr[j] > arr[k]){ //if the sum is greater we increment k to balance the two
                k++;
            }else{ //the sum is less the arr[k]

                //if j doesnt have any space to move forward we increment both , else we move j forward
                if(k-j<=1){
                    k++;
                    j++; //no place to move so we move both the pointers fwd
                }else{
                    j++;
                }

            }

        }

    }
    return triplets;

}

int main(){

    int n{0} ;
    cin>>n;
    int* arr = new int[n];
    for(int i {0} ; i < n ; i++){

        cin>>arr[i];

    }

    cout<<countTriplet(arr,n);
}


