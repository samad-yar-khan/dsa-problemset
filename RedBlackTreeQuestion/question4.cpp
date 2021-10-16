#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

//TreeNode Class 
class TreeNode{

    public:

        char data;
        char colour;
        TreeNode* parent;
        TreeNode* leftChild;
        TreeNode* rightChild;

    TreeNode(){
        data = '\0';
        colour = 'R';
        parent = NULL;
        leftChild = NULL;
        rightChild = NULL;
    }

    
    TreeNode(char data,TreeNode* parent , char colour ,TreeNode*leftChild=NULL, TreeNode* rightChild = NULL){
        this->data = data;
        this->colour = colour;
        this->parent = parent;
        this->leftChild = leftChild;
        this->rightChild = rightChild;
    }

    ~TreeNode(){
        delete this->leftChild;
        delete this->rightChild;
    }

};

//RedBlackTree
class RedBlackTree{

    public:

        TreeNode* root;
        TreeNode* TNULL;

        RedBlackTree(){
            TNULL = new TreeNode;
            TNULL->colour = 'B';
            root= TNULL;
        }

        void rotateLeft(TreeNode* currNode) {
         
            TreeNode* temp = currNode->rightChild;
            currNode->rightChild = temp->leftChild;
            if (temp->leftChild != TNULL) {
                temp->leftChild->parent = currNode;
                  
            }
                temp->parent = currNode->parent;
            if (currNode->parent == NULL) {
                this->root = temp;
              
            } else if (currNode ==  currNode->parent->leftChild) {
                currNode->parent->leftChild = temp;
            } else {
                currNode->parent->rightChild = temp;
            }
            temp->leftChild = currNode;
            currNode->parent = temp;
            
        }

        void rotateRight(TreeNode* currNode) {
            TreeNode* temp = currNode->leftChild;
            currNode->leftChild = temp->rightChild;
          
            if (temp->rightChild != TNULL) {
                temp->rightChild->parent = currNode;
            }
           
            temp->parent = currNode->parent;
           
            if (currNode->parent == NULL) {
                this->root = temp;       
            } else if (currNode == currNode->parent->rightChild) {
                currNode->parent->rightChild = temp;
            } else {
                currNode->parent->leftChild = temp;
            }
            temp->rightChild = currNode;
            currNode->parent = temp;
        }

         void switchRedBlackNode(TreeNode* node1, TreeNode* node2) {
            if (node1->parent == NULL) {
            root = node2;
            } else if (node1 == node1->parent->leftChild) {
            node1->parent->leftChild = node2;
            } else {
            node1->parent->rightChild = node2;
            }
            node2->parent = node1->parent;
        }


        void balanceRBT(TreeNode* currentNode){
            TreeNode* temp;

            while(currentNode->parent->colour=='R'){

                if(currentNode->parent == currentNode->parent->parent->rightChild){
                    temp = currentNode->parent->parent->leftChild;

                    if(temp!=NULL && temp->colour == 'R'){
                        currentNode->parent->parent->colour= 'R';
                        temp->colour = 'B';
                        currentNode->parent->colour = 'B';
                        
                        currentNode = currentNode->parent->parent;
                    }
                else{
                    if(currentNode == currentNode->parent->leftChild){
                        currentNode=currentNode->parent;
                        rotateRight(currentNode);
                    }

                    currentNode->parent->parent->colour='R';
                    currentNode->parent->colour='B';
                    rotateLeft(currentNode->parent->parent);
                }

            }else{

                temp= currentNode->parent->parent->rightChild;

                if(temp->colour == 'R'){
                    currentNode->parent->colour = 'B';
                    currentNode->parent->parent->colour='R';
                    temp->colour = 'B';
                    currentNode=currentNode->parent->parent;
                } else {
                    if (currentNode == currentNode->parent->rightChild) {
                        currentNode = currentNode->parent;
                        rotateLeft(currentNode);
                    }
                    currentNode->parent->colour = 'B';
                    currentNode->parent->parent->colour = 'R';
                    rotateRight(currentNode->parent->parent);
                }

            }
            if(currentNode==root){
                 root->colour='B';
                 return;

            }
        }
           root->colour='B';
        }

        void insert(char data){
            TreeNode* newNode = new TreeNode;
            newNode->data = data;
            newNode->colour = 'R'; //Red 
            newNode->leftChild = TNULL;
            newNode->rightChild = TNULL;
            newNode->parent=NULL;

            TreeNode* parentNode = NULL;
            TreeNode* currentNode = this->root;

            //traverse the bst in DFS manner to find the current position to place the node
            while(currentNode != TNULL){
                parentNode = currentNode;
                if(newNode->data > currentNode->data){
                    currentNode=currentNode->rightChild;
                }else{
                    currentNode=currentNode->leftChild;
                }
            }

            //here we have found a placee for our new node

            newNode->parent = parentNode;
            //checcurrentNode if its the first node or not
            if(parentNode==NULL){
                //set colour as blaccurrentNode as our root must be blaccurrentNode
              
                newNode->colour = 'B';
                this->root = newNode;
                return;
            }

            //if its not the root then we nee to set it as the child of our parent

            if(parentNode->data > newNode->data){
                parentNode->leftChild = newNode;
            }else{
                parentNode->rightChild = newNode;
            }
        //  cout<<" "<<newNode->data<<" ";
            //we dont need to balance when we are direct below the root;
            if(newNode->parent->parent == NULL){
                return;
            }
           
            balanceRBT(newNode);

        }
    
        TreeNode* getMin(TreeNode* node) {
            while (node->leftChild != TNULL) {
            node = node->leftChild;
            }
            return node;
        }

         void balanceRBT_deletion(TreeNode* currNode) {
    TreeNode* tempNode;
    while (currNode != root && currNode->colour == 'B') {
      if (currNode == currNode->parent->leftChild) {
        tempNode = currNode->parent->rightChild;
        if (tempNode->colour == 'R') {
          tempNode->colour = 'B';
          currNode->parent->colour = 'R';
          rotateRight(currNode->parent);
          tempNode = currNode->parent->rightChild;
        }

        if (tempNode->leftChild->colour == 'B' && tempNode->rightChild->colour == 'B') {
          tempNode->colour = 'R';
          currNode = currNode->parent;
        } else {
          if (tempNode->rightChild->colour == 'B') {
            tempNode->leftChild->colour = 'B';
            tempNode->colour = 'R';
            rotateRight(tempNode);
            tempNode = currNode->parent->rightChild;
          }

          tempNode->colour = currNode->parent->colour;
          currNode->parent->colour = 'B';
          tempNode->rightChild->colour = 'B';
          rotateRight(currNode->parent);
          currNode = root;
        }
      } else {
        tempNode = currNode->parent->leftChild;
        if (tempNode->colour == 'R') {
          tempNode->colour = 'B';
          currNode->parent->colour = 'R';
          rotateRight(currNode->parent);
          tempNode = currNode->parent->leftChild;
        }

        if (tempNode->rightChild->colour == 'B' && tempNode->rightChild->colour == 'B') {
          tempNode->colour = 'R';
          currNode = currNode->parent;
        } else {
          if (tempNode->leftChild->colour == 'B') {
            tempNode->rightChild->colour = 'B';
            tempNode->colour = 'R';
            rotateRight(tempNode);
            tempNode = currNode->parent->leftChild;
          }

          tempNode->colour = currNode->parent->colour;
          currNode->parent->colour = 'B';
          tempNode->leftChild->colour = 'B';
          rotateRight(currNode->parent);
          currNode = root;
        }
      }
    }
    currNode->colour = 'B';
  }

        void deleteNode(TreeNode* node, int key) {
            TreeNode* temp1 = TNULL;
            TreeNode* temp2=NULL;
            TreeNode* temp3=NULL;

            while (node != TNULL) {
            if (node->data == key) {
                temp1 = node;
            }

            if (node->data <= key) {
                node = node->rightChild;
            } else {
                node = node->leftChild;
            }
            }

            if (temp1 == TNULL) {

            return;
            }

            temp3 = temp1;
            char Temp1OriginalColor = temp3->colour;
            if (temp1->leftChild == TNULL) {
            temp2 = temp1->rightChild;
            switchRedBlackNode(temp1, temp1->rightChild);
            } else if (temp1->rightChild == TNULL) {
            temp2 = temp1->leftChild;
            switchRedBlackNode(temp1, temp1->leftChild);
            } else {
            temp3 = getMin(temp1->rightChild);
            Temp1OriginalColor = temp3->colour;
            temp2 = temp3->rightChild;
            if (temp3->parent == temp1) {
                temp2->parent = temp3;
            } else {
                switchRedBlackNode(temp3, temp3->rightChild);
                temp3->rightChild = temp1->rightChild;
                temp3->rightChild->parent = temp3;
            }

            switchRedBlackNode(temp1, temp3);
            temp3->leftChild = temp1->leftChild;
            temp3->leftChild->parent = temp3;
            temp3->colour = temp1->colour;
            }
            delete temp1;
            if (Temp1OriginalColor == 'B') {
            balanceRBT_deletion(temp2);
            }
        }

        void deleteKey(char key){
            deleteNode(root,key);
        }

        private:
         bool searchNode(TreeNode*node , char element){
            if(node==TNULL){
                return true;
            }

            if(node->data == element){
                return true;
            }

            if(node->data > element){
                return searchNode(node->leftChild , element);
            }else{
                return searchNode(node->rightChild , element);
            }
        }

        void inOrder(TreeNode*node){
            // cout<<node->data<<" ";
            if(node==TNULL || node==NULL){
                return;
            }
          
            inOrder(node->leftChild);
            string color;
            if(node->colour=='B'){
                color="Black";
            }else{
                color="Red";
            }
            cout<<"\nKey : "<<node->data<<", Colour: "<<color<<"\n";
            inOrder(node->rightChild);

        }

        public:
        void printTree(){
            inOrder(this->root);
        }

       

        bool findNode(char element){
            return searchNode(this->root , element);
        }



};



string removeDublicates(string input){

    int frequency[256]={0};
    char space =' ';
    string output{""};
    for(int i =0;i<input.length() ;i++){
        if(frequency[input[i] - space] >0){
            continue;
        }else{
            frequency[input[i] - space]++;
            output+=input[i];
        }
    }
    return output;
    

}

int main(){
    cout << "\nEnter string :\n";
    string str;
    cin>>str;
    str = removeDublicates(str);
    
    cout << "\nString after removing duplicates is :\n";
    cout << str << "\n\n";
    RedBlackTree RBT;

    for(int i=0;i<str.length();i++){
        str[i];
        RBT.insert(str[i]);
    }

    cout << "-----------------\n\n";
    cout << "All elemnts inserted in tree\n";
   
    RBT.printTree();
    
    cout << "\n-----------------\n\n";
    cout << "Deleting every even position character of string\n";
    
    for(int i=0;i<str.length();i++){
        if(i%2 != 0){
            RBT.deleteKey(str[i]);
        }
    }

    cout << "----------------\n";
    cout << "After deletion of every even position character of string\n";
    cout << "The tree looks like this\n";
    RBT.printTree();

    cout << "\n------------------\n";


}


