// Problem Link : https://practice.geeksforgeeks.org/batch-problems/check-if-subtree/0/?track=amazon-trees&batchId=192#
class Solution
{
  public:
    //Function to check if S is a subtree of tree T.
    bool isSubTree(Node* T, Node* S) 
    {
        // Your code here
        
        if(!T && !S)
            return NULL;
        
        if((!T && S) || (T && !S))
            return false;
        
        
        // If data equal then may be it can be subtree.
        if(T->data == S->data)
        {
            // So see if tree from here is subtree i.e same. If yes return true but don't return false if not same. We have to try remaining tree.
            if(isSame(T,S))
                return true;
        }
            
        
        return isSubTree(T->left,S) || isSubTree(T->right,S);

    }
    
    
    bool isSame(Node *n1, Node *n2)
    {
        if(!n1 && !n2)
            return true;
        
        if((!n1 && n2) || (n1 && !n2))
            return false;

        
        if(n1->data != n2->data)
            return false;

        
        return (isSame(n1->left,n2->left) && isSame(n1->right, n2->right));
    }
};

