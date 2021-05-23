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

    ~Node(){

        delete(this->next);

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

//when overall operator outisde class  we need to pass both params 
//output stream
ostream& operator<<(ostream &os , Node* head){

    print(head);
    return os;

}

//input stream
istream& operator>>(istream &is , Node*&head){//referance to head * because we need to save new value of head after input 

    head = takeinput();
    return is;

}

int main(){

    Node* head1 =NULL;
     Node* head2=NULL;
     cin>>head1>>head2;
    cout<<head1<<head2;

}