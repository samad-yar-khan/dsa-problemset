template <typename T>

class BinaryTreeNode {

    public :
        T data ;
        BinaryTreeNode<T>* left;
        BinaryTreeNode<T>* right;

    BinaryTreeNode(){
        data = 0 ;
        left = NULL;
        right = NULL;
    }

    BinaryTreeNode(T data){
        this->data = data ;
        left = NULL;
        right = NULL;
    }

    ~BinaryTreeNode(){
        delete left ;
        delete right ;
    }

};