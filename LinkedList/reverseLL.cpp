#include <iostream>
using namespace std;

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


Node* appendLastNToFirst(Node* head,int n)
{
    //write your code here
    //first calculate  the len

    int len{0};
	
     if(head == NULL ||  n==0){
        return head;
    }
    
    Node*temp = head;
    while(temp){
        temp=temp->next;
        len++;
    }   
    //edge cases , no need for computation
    if(len <= 1 || len <= n){
        return head;
    }

    int prevIndex =  len-n -1;

     temp = head;
     Node*newHead = NULL;
     int i{0};
    while(i <= prevIndex){

        if(i == prevIndex){
            newHead = temp->next;
            temp->next = NULL;
            i++;
            break;
        }

        temp = temp->next;
        i++;

    } 

    //nowe we have divided our ll into a new ll of size n and and old ll of size len - n
    //we go to the tail of oour new ll and link its tail to our old head

    Node*tail = newHead;
    while(tail != NULL &&tail->next != NULL){
        tail=tail->next;
    }

    tail->next = head;

    head = newHead;
    return head;



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
    
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
	
		head = reverse(head);
		print(head);
	}
	return 0;
}