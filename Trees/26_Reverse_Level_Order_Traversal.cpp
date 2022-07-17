// Problem Link : https://practice.geeksforgeeks.org/batch-problems/reverse-level-order-traversal/0/?track=amazon-trees&batchId=192#
vector<int> reverseLevelOrder(Node *root)
{
    
    stack<int> st;
    queue<Node *> Q;
    vector<int> ans;
    
    Q.push(root);
    
    while(!Q.empty())
    {
        Node * front = Q.front();
        Q.pop();
        
        st.push(front->data);
        
        // Traverse right first and then left. So that while poping from stack left comes first.
        if(front->right)
            Q.push(front->right);
        
        if(front->left)
            Q.push(front->left);
    }
    
    while(!st.empty())
    {
        ans.push_back(st.top());
        st.pop();
    }
    
    return ans;
}
