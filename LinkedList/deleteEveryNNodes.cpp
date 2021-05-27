#include<iostream>
using namespace std;
#include "linkedList.cpp"

/*
Delete every N nodes
Send Feedback
You have been given a singly linked list of integers along with two integers, 'M,' and 'N.' Traverse the linked list such that you retain the 'M' nodes, then delete the next 'N' nodes. Continue the same until the end of the linked list.
To put it in other words, in the given linked list, you need to delete N nodes after every M nodes.
Note :
No need to print the list, it has already been taken care. Only return the new head to the list.
Input format :
The first line contains an Integer 't' which denotes the number of test cases or queries to be run. Then the test cases follow.

The first line of each test case or query contains the elements of the singly linked list separated by a single space.

The second line of input contains two integer values 'M,' and 'N,' respectively. A single space will separate them.
 Remember/Consider :
While specifying the list elements for input, -1 indicates the end of the singly linked list and hence, would never be a list element
Output format :
For each test case/query, print the elements of the updated singly linked list.

Output for every test case will be printed in a seperate line.
Constraints :
1 <= t <= 10^2
0 <= P <= 10^5
Where P is the size of the singly linked list.
0 <= M <= 10^5
0 <= N <= 10^5 

Time Limit: 1sec
Sample Input 1 :
1
1 2 3 4 5 6 7 8 -1
2 2
Sample Output 1 :
1 2 5 6
Sample Input 2 :
2
10 20 30 40 50 60 -1
0 1
1 2 3 4 5 6 7 8 -1
2 3
Sample Output 2 :
1 2 6 7
Explanation of Sample Input 2 :
For the first query, we delete one node after every zero elements hence removing all the items of the list. Therefore, nothing got printed.

For the second query, we delete three nodes after every two nodes, resulting in the final list, 1 -> 2 -> 6 -> 7.
*/

void  del(Node* head){

    while(head!=NULL){

        Node*temp = head;
        head= head->next;
        temp->next = NULL;
        delete temp;

    }

}

Node* skipMdeleteN(Node* head , int m , int n){

    Node*temp = head;
    int i = 0,j=0;    

    if(n == 0 || head == NULL){
        return head;
    }

    if(m==0){
        del(head);
        return NULL;
    }

    while(temp != NULL){

        while(temp!=NULL && i < m-1)
        {
            i++;temp=temp->next;
        }
        //now from my next i ll iterate n-1 time to find head which i goott link to my this node
        //suppose we run out of the ll at a time while iterating
        if(temp==NULL || temp->next == NULL){
            return head;
        }

        Node*t = temp;
        Node*hD = temp->next; //head of the ll which is to be deleted ;
        temp = temp->next;
        while (temp!=NULL && j < n-1)
        {
            /* code */
            j++;temp=temp->next;
        }
        Node*secondHead = temp->next;
        temp->next = NULL;
        del(hD);
        t->next = secondHead;

        temp = secondHead;
        i=0;j=0;
    }

    return head;
}