#include <iostream>
using namespace std;

class node
{
public:
	int data;
	node *next;
	node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};


node *takeinput()
{
	int data;
	cin >> data;
	node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		node *newnode = new node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
		}
		cin >> data;
	}
	return head;
}

void print(node *head)
{
	node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}


node* appendLastNToFirst(node* head,int n)
{
    //write your code here
    //first calculate  the len

    int len{0};
	
     if(head == NULL ||  n==0){
        return head;
    }
    
    node*temp = head;
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
     node*newHead = NULL;
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

    node*tail = newHead;
    while(tail != NULL &&tail->next != NULL){
        tail=tail->next;
    }

    tail->next = head;

    head = newHead;
    return head;



}
int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		node *head = takeinput();
		int n;
		cin >> n;
		head = appendLastNToFirst(head, n);
		print(head);
	}
	return 0;
}