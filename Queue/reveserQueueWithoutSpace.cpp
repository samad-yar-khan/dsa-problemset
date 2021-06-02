#include<queue>
#include<iostream>
using namespace std;

    void reverseQueue(queue<int> &q) {

        //bc
        if(q.size() ==1 || q.size() == 0)
        {
            return ;
        }

        //inductin hypostheses 
        //take out you queue and then ask recursion to revers ethe smaller queue and expect this to work

        int qTop = q.front();
        q.pop();

        reverseQueue(q) ;

        // now our q is reversed so we just put our front elemet at the end 

        q.push(qTop);

        return;
    }
