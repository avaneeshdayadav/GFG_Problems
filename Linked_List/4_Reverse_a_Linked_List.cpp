class Solution
{
    public:
    //Function to reverse a linked list.
    Node *gHead;
    struct Node* reverseList(struct Node *head)
    {
        // return head of reversed list
        
        if(head == NULL or head->next == NULL)
            return head;
        
        // Make global head = this head for now.
        gHead = head;
        
        // Make this head as last node by making it's next NULL.
        helper(head)->next = NULL;
        
        // Return gHead as new head as it was changed in recursion & now it will be pointing to last node which is now first node.
        return gHead;
        
    }
    
    struct Node* helper(struct Node* node)
    {
        // If we reached last node then point gHead at this node to make it new start node and return this node.
        if(node->next == NULL)
        {
            gHead = node;
            return node;
        }
        
        
        // If not last node, then call helper on this nodes's next & when it return that node back again then point that node's next to this curr node to reverse the link.
        helper(node->next)->next = node;
        
        // Then return this node to prev called function where it will make this node's next point to it's curr node for reversing link.
        return node;
    }
};
