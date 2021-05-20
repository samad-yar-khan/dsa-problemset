#include <iostream>
#include<string>
using namespace std;

/**
 * This solution runs in O(N) time and O(1) space 
 * logic is thta we diviide the ll into two parts
 * the we reverse the second half of the ll
 * then we compare the first and second half 
 * then if furts and scodn half are not identical our an is false , else true 
 * then we re-reverse the rveese half
 * attack the linnked list again
 * return ans
 * */

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};


Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}


Node* reverse(Node*head){
            
        if(head == NULL|| head->next == NULL){
            return head;
        }
        
        Node* temp = head;
        
        Node*last = NULL;
        Node*mid = head ;
        Node*front = head->next;
        
        while(front != NULL){
                
            mid->next = last ;
            last = mid ;
            mid=front;
            front = front->next;
            
            
        }

        mid->next = last;
        
        return mid;
    }
    
    
    bool isPalindrome(Node *head)
    {
        //Your code here
        if(head==NULL ||head->next == NULL){
            true;
        }
        
        int len{0};
        
        Node* temp = head ;
        while(temp!=NULL){
            temp=temp->next;
            len++;
        }
        
        Node*mid = head;
        for(int i = 0 ; i < (len/2) - 1; i++){
            mid=mid->next;
        }
        Node*realMid = mid->next;
        
        mid->next = NULL;
        //reverse the next half
        Node*revHead = reverse(realMid);
         Node*revHead2 = revHead;
        Node*myHead = head;
        bool ans{true};
        while(myHead!=NULL && revHead2!=NULL){
                
            if(myHead->data!=revHead2->data){
                ans=false;
                break;
            }
            myHead=myHead->next ;
            revHead2=revHead2->next;
            
        }
         revHead = reverse(revHead);
        
        mid->next = revHead;
        return ans;
        
        
        
        
    }

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
        string y{" yes"} , n{" no"};
        
		cout<<"IS PALINDROME : "<<(isPalindrome(head)?y:n)<<"\n";
		print(head);
	}
	return 0;
}
