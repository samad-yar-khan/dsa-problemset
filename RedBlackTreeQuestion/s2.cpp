#include<iostream>
#include <string>

using namespace std;

/* Write a program that reads a string as input (without
any space). Check the string for any duplicates, if found
any remove them. Insert each character of remaining
string into a Red-Black tree. After creating the Red-Black
tree delete every even position character of string from
the Red-Black tree.
*/

string removeDups(string s){
    int freq[256];
    for(int i=0;i<256;i++){
        freq[i] = 0;
    }
    int idx1 = 0;
    int idx2 = 0;
    char temp;

    while(idx1<s.length()){
        temp = s[idx1];
        if(!freq[temp]){
            freq[temp] = 1;
            s[idx2] = s[idx1];
            idx2++;
        }
        idx1++;
    }
    return s.substr(0, idx2);
}

class Node
{
    public:
       int key;
       Node *parent;
       char color;
       Node *left;
       Node *right;
};
class RBtree
{
    private:
        Node *root;
        Node *q;
    public:
    RBtree()
    {
        q=NULL;
        root=NULL;
    }
    void insert(int x);
    void insertfix(Node *);
    void leftrotate(Node *);
    void rightrotate(Node *);
    void del(int x);
    Node* successor(Node *);
    void delfix(Node *);
    void disp();
    void show(Node *);
};
void RBtree::insert(int z)
{
    int i=0;
    Node *p,*q;
    Node *t=new Node;
    t->key=z;
    t->left=NULL;
    t->right=NULL;
    t->color='r';
    p=root;
    q=NULL;
    if(root==NULL)
    {
        root=t;
        t->parent=NULL;
    }
    else
    {
        while(p!=NULL)
        {
            q=p;
            if(p->key<t->key)
                p=p->right;
            else
                p=p->left;
        }
        t->parent=q;
        if(q->key<t->key)
            q->right=t;
        else
            q->left=t;
    }
    insertfix(t);
}
void RBtree::insertfix(Node *t)
{
    Node *u;
    if(root==t)
    {
        t->color='b';
        return;
    }
    while(t->parent!=NULL&&t->parent->color=='r')
    {
        Node *g=t->parent->parent;
        if(g->left==t->parent)
        {
            if(g->right!=NULL)
            {
                u=g->right;
                if(u->color=='r')
                {
                    t->parent->color='b';
                    u->color='b';
                    g->color='r';
                    t=g;
                }
            }
            else
            {
                if(t->parent->right==t)
                {
                    t=t->parent;
                    leftrotate(t);
                }
            t->parent->color='b';
            g->color='r';
            rightrotate(g);
            }
        }
        else
        {
            if(g->left!=NULL)
            {
                u=g->left;
                if(u->color=='r')
                {
                    t->parent->color='b';
                    u->color='b';
                    g->color='r';
                    t=g;
                }
            }
            else
            {
                if(t->parent->left==t)
                {
                    t=t->parent;
                    rightrotate(t);
                }
                t->parent->color='b';
                g->color='r';
                leftrotate(g);
            }
        }
        root->color='b';
    }
}

void RBtree::del(int x)
{
    if(root==NULL)
    {
        cout<<"\nEmpty Tree.";
        return;
    }
    Node *p;
    p=root;
    Node *y=NULL;
    Node *q=NULL;
    int found=0;
    while(p!=NULL&&found==0)
    {
        if(p->key==x)
            found=1;
        if(found==0)
        {
            if(p->key<x)
                p=p->right;
            else
                p=p->left;
        }
    }
    if(found==0)
    {
        // cout<<"\nElement Not Found.";
        return;
    }
    else
    {
        // cout<<"\nDeleted Element: "<<char(p->key);
        // cout<<"\nColour: ";
        // if(p->color=='b')
        //     cout<<"Black";
        // else
        //     cout<<"Red";

        // if(p->parent!=NULL)
        //     cout<<"\nParent: "<<char(p->parent->key);
        // else
        //     cout<<"\nThere is no parent of the node.  ";
        // if(p->right!=NULL)
        //     cout<<"\nRight Child: "<<char(p->right->key);
        // else
        //     cout<<"\nThere is no right child of the node.  ";
        // if(p->left!=NULL)
        //     cout<<"\nLeft Child: "<<char(p->left->key);
        // else
        //     cout<<"\nThere is no left child of the node.  ";
        
        // cout<<"\nNode Deleted.";

        if(p->left==NULL||p->right==NULL)
            y=p;
        else
            y=successor(p);
        if(y->left!=NULL)
            q=y->left;
        else
        {
            if(y->right!=NULL)
                q=y->right;
            else
                q=NULL;
        }
        if(q!=NULL)
            q->parent=y->parent;
        if(y->parent==NULL)
            root=q;
        else
        {
            if(y==y->parent->left)
                y->parent->left=q;
            else
            y->parent->right=q;
        }
         if(y!=p)
         {
             p->color=y->color;
             p->key=y->key;
         }
         if(y->color=='b')
             delfix(q);
     }
     cout << "\n";
}

void RBtree::delfix(Node *p)
{
    Node *s;
    while(p!=root&&p->color=='b')
    {
        if(p->parent->left==p)
        {
            s=p->parent->right;
            if(s->color=='r')
            {
                s->color='b';
                p->parent->color='r';
                leftrotate(p->parent);
                s=p->parent->right;
            }
            if(s->right->color=='b'&&s->left->color=='b')
            {
                s->color='r';
                p=p->parent;
            }
            else
            {
                if(s->right->color=='b')
                {
                    s->left->color=='b';
                    s->color='r';
                    rightrotate(s);
                    s=p->parent->right;
                }
                s->color=p->parent->color;
                p->parent->color='b';
                s->right->color='b';
                leftrotate(p->parent);
                p=root;
            }
        }
        else
        {
            s=p->parent->left;
            if(s->color=='r')
            {
                s->color='b';
                p->parent->color='r';
                rightrotate(p->parent);
                s=p->parent->left;
            }
            if(s->left->color=='b'&&s->right->color=='b')
            {
                s->color='r';
                p=p->parent;
            }
            else
            {
                if(s->left->color=='b')
                {
                    s->right->color='b';
                    s->color='r';
                    leftrotate(s);
                    s=p->parent->left;
                }
                s->color=p->parent->color;
                p->parent->color='b';
                s->left->color='b';
                rightrotate(p->parent);
                p=root;
            }
          }
    p->color='b';
    root->color='b';
    }
}

void RBtree::leftrotate(Node *p)
{
    if(p->right==NULL)
        return;
    else
    {
        Node *y=p->right;
        if(y->left!=NULL)
        {
            p->right=y->left;
            y->left->parent=p;
        }
        else
            p->right=NULL;
        if(p->parent!=NULL)
            y->parent=p->parent;
        if(p->parent==NULL)
            root=y;
        else
        {
            if(p==p->parent->left)
                p->parent->left=y;
            else
                p->parent->right=y;
        }
        y->left=p;
        p->parent=y;
    }
}
void RBtree::rightrotate(Node *p)
{
    if(p->left==NULL)
        return;
    else
    {
        Node *y=p->left;
        if(y->right!=NULL)
        {
            p->left=y->right;
            y->right->parent=p;
        }
        else
            p->left=NULL;
        if(p->parent!=NULL)
            y->parent=p->parent;
        if(p->parent==NULL)
            root=y;
        else
        {
            if(p==p->parent->left)
                p->parent->left=y;
            else
                p->parent->right=y;
        }
        y->right=p;
        p->parent=y;
    }
}

Node* RBtree::successor(Node *p)
{
    Node *y=NULL;
    if(p->left!=NULL)
    {
        y=p->left;
        while(y->right!=NULL)
            y=y->right;
    }
    else
    {
        y=p->right;
        while(y->left!=NULL)
            y=y->left;
    }
    return y;
}

void RBtree::disp()
{
    show(root);
}
void RBtree::show(Node *p)
{
    if(root==NULL)
    {
        return;
    }
    if(p!=NULL)
    {
       
    if(p->left)
    {

        show(p->left);
    }
     cout<<"\nKey : "<<char(p->key);
        cout<<", Colour: ";
    if(p->color=='b')
        cout<<"Black";
    else
        cout<<"Red";
        cout<<"\n";
    if(p->right)
    {
        show(p->right);
    }
    }
}

int main()
{
    cout << "\nEnter string :\n";
    string str;
    cin>>str;
    str = removeDups(str);
    int n = str.length();
    cout << "\nString after removing duplicates is :\n";
    cout << str << "\n\n";
    RBtree obj;

    for(int i=0;i<n;i++){
        char temp = str[i];
        int tempno = int(temp);
        obj.insert(tempno);
    }

    cout << "-----------------\n\n";
    cout << "All elemnts inserted in tree\n";
    obj.disp();
    
    cout << "\n-----------------\n\n";
    for(int i=0;i<n;i++){
        if(i%2!=0){
            char temp = str[i];
            int tempno = int(temp);
            obj.del(tempno);
        }
    }
    cout << "After deletion of every even position character of string\n";
    cout << "The tree looks like this\n";
    obj.disp();

    cout << "\n------------------\n";
   
    return 0;
}