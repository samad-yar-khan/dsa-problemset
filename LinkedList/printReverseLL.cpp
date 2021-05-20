#include <iostream>
#include<stack>
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

using namespace std;


Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
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

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		printReverse(head);
		cout << endl;
	}
	return 0;
}


//recursive
void printReverseRec(Node* head){
	
    //bc
	if(head == NULL){
        return;
    }
    
    //ih we aslk rec to print the rwts of the ll in reversr and then we print our element
    printReverseRec(head->next);
    
    cout<<head->data<<" ";

}


//iterative using stack

void printReverse(Node* head){
    	
	
    Node* temp = head ;
    
    stack<int> myStack;
    
    while(temp!=NULL){
        
        myStack.push(temp->data);
        
        temp = temp->next;
    }
    
    while(myStack.size() > 0){
        cout<<myStack.top()<<" ";
        myStack.pop();
    }
    
    cout<<"\n";
    
    
	}