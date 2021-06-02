#include "TreeNode.h"

int getLeafNodeCount(TreeNode<int>* root) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input and printing output is handled automatically.
     */
    if(root == NULL){
        return 0;
    }
    
    if(root->children.size() == 0){
        return 1;
    }
    
    int ans=0;
    for(int i = 0 ; i < root->children.size() ; i++){
        ans += getLeafNodeCount(root->children[i]);
    }
    
    return ans;

}
