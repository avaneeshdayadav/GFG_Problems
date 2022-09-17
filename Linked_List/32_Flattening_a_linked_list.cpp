/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

Node* sortedMergeFor2List(Node* head1, Node* head2)  
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
    while(trav->bottom != NULL)
    {
        // If trav next is less than stopped list first value then increment trav.
        if(trav->bottom->data < stoped->data)
            trav = trav->bottom;
        // Else make stoped point to trav->next and make trav->next point where stop was pointing. i.e swap(trav->next, stopped).
        // Increment trav to trav->next.
        else
        {
            Node *temp = stoped;
            stoped = trav->bottom;
            trav->bottom = temp;
            trav = trav->bottom;
        }
    }
    
    // Now trav is at last node. Make it's next point to stopped list.
    trav->bottom = stoped;
    
    // Return the newHead that you made earlier.
    return newHead;
    
} 

Node *flatten(Node *root)
{
   // Your code here
   
    Node *trav = root->next, *finalList = root;
  
  
    while(trav != NULL)
    {
      finalList = sortedMergeFor2List(finalList, trav);
      trav = trav->next;
       
    }
    return finalList;
   
}

