#include<iostream>

using namespace std;

class node{

    public:
        int data ;
        node* next;

    node(){
        this->data = 0 ;
        this->next = NULL;
    }

    node(int data){
        this->data = data ;
        this->next = NULL;
    }

};


void printLL(node*head){

    node*HEAD = head;

    while(HEAD!=NULL){
        cout<<HEAD->data<<" , ";
        HEAD = HEAD->next;
    }

}

void deleteALL(node*head){

    while(head!=NULL){

        node*temp = head->next;
        delete head;
        head = temp;

    }
}

int length(node*head){

    node*HEAD = head;
    
    int len{0};
    while(HEAD!=NULL){

        len++;
        HEAD=HEAD->next;

    }
    return len;
}

node *input(){

    int inp{0};
    cin>>inp;

    node* head = NULL ;
    node* tail =NULL; 

    while(inp != -1){

        // create a nw node
        node*temp = new  node(inp);

        //if heads null we initalise the ll
        if(head == NULL){
            head = temp;
            tail = temp;
        }else{
            //lls already initialised

            tail->next = temp;
            tail=tail->next;

        }

        cin>>inp;
    }

    return head;

}

node* deleteNode(node*head , int i){
     if(i ==  0 ){
        	
        node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return head;
        
    }
    
    //calculate length
    //edge case if index is out of bound
    int len{0};
    node* temp=head;
    while(temp!=NULL){
        temp=temp->next;
        len++;
    }
    
    if(i>=len){
        return head;
    }
    
    int itr{0};
    temp = head;
    while(itr < i-1){
        
        temp = temp->next;

        itr++;
    }
	
    node*myNext = temp->next;
    temp->next = myNext->next;
    myNext->next = NULL;
    delete myNext;
    
    return head;
}


int main(){

  
    //node ptr to store the adress of head
    node*head = input();

    

    printLL(head);


    cout<<"\nLength of LL : "<<length(head)<<"\n";

}