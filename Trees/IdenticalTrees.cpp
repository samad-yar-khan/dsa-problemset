/*
Structurally identical
Send Feedback
Given two generic trees, return true if they are structurally identical. Otherwise return false.
Structural Identical
If the two given trees are made of nodes with the same values and the nodes are arranged in the same way, then the trees are called identical.  
Input format :
The first line of input contains data of the nodes of the first tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.  
The following line of input contains data of the nodes of the second tree in level order form. The order is: data for root node, number of children to root node, data of each of child nodes and so on and so forth for each node. The data of the nodes of the tree is separated by space.
Output format :
The first and only line of output contains true, if the given trees are structurally identical and false, otherwise.
Constraints:
Time Limit: 1 sec
Sample Input 1 :
10 3 20 30 40 2 40 50 0 0 0 0 
10 3 20 30 40 2 40 50 0 0 0 0
Sample Output 1 :
true
Sample Input 2 :
10 3 20 30 40 2 40 50 0 0 0 0 
10 3 2 30 40 2 40 50 0 0 0 0
Sample Output 2:
false
*/

#include "TreeNode.h"
using namespace std;
#include <queue>

bool areIdentical(TreeNode<int>* root1 , TreeNode<int>* root2 ){

    queue<TreeNode<int> *> pendingNodes1 ;
    queue<TreeNode<int> *> pendingNodes2 ;
    
    pendingNodes1.push(root1);
    pendingNodes2.push(root2);

    while (!pendingNodes1.empty() && !pendingNodes2.empty())
    {
        TreeNode<int>* node1 = pendingNodes1.front();
        pendingNodes1.pop();
        TreeNode<int>* node2 = pendingNodes2.front();
        pendingNodes2.pop();

        if(node1->data != node2->data || node1->children.size() != node2->children.size()){
            return false;
        }


        for(int i = 0 ; i < node2->children.size() ; i++){
            pendingNodes1.push(node1->children[i]);
            pendingNodes2.push(node2->children[i]);
        }

    }
    
    return true;

}

