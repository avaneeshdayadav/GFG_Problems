

/*Structure of Node of the linked list is as
struct Node
{
	int data;
	struct Node *next;
	
	Node(int x){
	    data =x;
	    next = NULL;
	}
};
*/
// your task is to complete this function

Node* rev(Node *node, Node *&finalHeadNode)
{
    if(node->next == NULL)
    {
        finalHeadNode = node;
        return node;
    }
        
    rev(node->next, finalHeadNode)->next = node;
    return node;
}

//Function to merge two sorted linked list.
Node* sortedMerge(Node* head1, Node* head2)  
{  
    // O(N) time and O(1) space.
    // If any one head is null return the other head.
    if(head1 == NULL)
        return head2;
    
    if(head2 == NULL)
        return head1;
        
    Node *newHead, *trav, *stoped;
    
    
    // Decide the newHead that you will return as answer. Newhead will point to a list with low value at 0th index.
    if(head1->data > head2->data)
    {
        newHead = trav = head2;
        stoped = head1;
    }
    else
    {
        newHead = trav = head1;
        stoped = head2;
    }
    
    
    // trav will keep traversing the list with smaller values and compare it with list pointed by stopped pointer.
    // Trav goes till it's next is not null, i.e loop will stop when trav is at some last node.
    while(trav->next != NULL)
    {
        // If trav next is less than stopped list first value then increment trav.
        if(trav->next->data < stoped->data)
            trav = trav->next;
        // Else make stoped point to trav->next and make trav->next point where stop was pointing. i.e swap(trav->next, stopped).
        // Increment trav to trav->next.
        else
        {
            Node *temp = stoped;
            stoped = trav->next;
            trav->next = temp;
            trav = trav->next;
        }
    }
    
    // Now trav is at last node. Make it's next point to stopped list.
    trav->next = stoped;
    
    // Return the newHead that you made earlier.
    return newHead;
    
}  


void sort(Node **head)
{
     // Code here
     
    if(!(*head) or !(*head)->next)
        return;
    
    Node *list1H = *head;
    Node *list2H = (*head)->next;
    
    Node *trav = list1H;
    
    // Seperate both list.
    while(trav and trav->next)
    {
        Node *temp = trav->next;
        trav->next = temp->next;
        trav = temp;
    }
     
    
    Node *finalHeadNode = list2H;
    rev(list2H, finalHeadNode)->next = NULL;
    
    list2H = finalHeadNode;
    
    // Merge both the list.
    (*head) = sortedMerge(list1H, list2H);

}
