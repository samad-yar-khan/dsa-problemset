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



int main(){

  
    //node ptr to store the adress of head
    node*head = input();

    

    printLL(head);

    cout<<"\nLength of LL : "<<length(head)<<"\n";

}