
//delete a node in linked list 

node* deletenodeRec(node *head, int i) {
    /* Don't write main().
     * Don't read input, it is passed as function argument.
     * Return output and don't print it.
     * Taking input is handled automatically.
     */
    //base case
    if (head ==NULL){
        return head;
    }
    //induction step;
    //apna delet karna hai 
    if(i==0){
        node*new_head = head ->next;
        delete head;
        head = new_head;
        return head;
    }
    
    //induction hypothesis
    //ye mujhe choti wali ll lakara deedega with appropriate deletion
	node *new_next = deletenodeRec(head->next,i-1);
    
    head->next = new_next;
    
    return head;
}


