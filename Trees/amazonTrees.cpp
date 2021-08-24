#include<bits/stdc++.h>
using namespace std;
//we hace to return the noe with the highets  value of speed
//speed sum of all nodes of subtree(atleast 2 nodes)/num noodes

class componentNode {

    public:

        int value;
        vector<componentNode> components;
        componentNode(){

        }
        componentNode(int l){
            value = l;
        }

};


class ans{

    public:

        componentNode* ansNode ;
        double speedVal;
        int sumNodes;
        int numNodes;

    ans(){}

    ans(componentNode* a , double s , int s2 , int n){
        ansNode = a;
        speedVal= s;
        sumNodes=s2;
        numNodes = n;
    }
};

ans solve(componentNode* root){

    //bc
    if(root==NULL){
        ans a(NULL , INT_MIN , 0 , 0);
        return a;
    }

    //edge node 
    if(root->components.size() == 0){
        ans a(root , INT_MIN , root->value , 1 );
        return a;
    }

    //ih

    componentNode*ansNode = NULL ;
    double speedVal = INT_MIN;
    int sumNodes = 0 ;
    int numNodes = 0 ;

    for(int i = 0 ; i < root->components.size() ; i++){

        ans temp = solve(&(root->components[i]));
        if(temp.speedVal > speedVal){
            ansNode = &(root->components[i]);
            speedVal = temp.speedVal;
        }
        numNodes+=temp.numNodes;
        sumNodes+=temp.sumNodes;
    }

    numNodes+=1;
    sumNodes+=(root->value);

    double speedValMine = ((double)sumNodes/(double)numNodes);

    if(speedValMine > speedVal) {
        speedVal = speedValMine;
        ansNode = root;
    }

    ans ourA(ansNode , speedVal , sumNodes ,  numNodes);
}

componentNode* getFastestComponent(componentNode* root){
    return solve(root).ansNode;
}







