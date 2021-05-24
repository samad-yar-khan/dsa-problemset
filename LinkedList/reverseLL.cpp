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


 Node* reverse(Node*head){
            
        if(head == NULL|| head->next == NULL){
            return head;
        }
        
        Node* temp = head;
        
        Node*previousNode = NULL;
        Node*currentNode = head ;
        Node*nextNode = head->next;
        
        while(nextNode != NULL){
                
            currentNode->next = previousNode ;
            previousNode = currentNode ;
            currentNode=nextNode;
            nextNode = nextNode->next;
            
            
        }

        currentNode->next = previousNode;
        
        return currentNode;
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