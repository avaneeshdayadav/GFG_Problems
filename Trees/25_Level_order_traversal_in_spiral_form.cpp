// Problem Link : https://practice.geeksforgeeks.org/batch-problems/level-order-traversal-in-spiral-form/0/?track=amazon-trees&batchId=192#
//Function to return a list containing the level order traversal in spiral form.
vector<int> findSpiral(Node *root)
{
    // Using two stack.
    
        // stack<Node *> s1,s2;
        // vector<int> ans;
        
        // if(root == NULL)
        //     return ans;
    
        // s1.push(root);
        
        // while(!s1.empty() || !s2.empty())
        // {
            
        //     while(!s1.empty())
        //     {
        //         Node *top = s1.top();
        //         ans.push_back(top->data);
        //         s1.pop();
                
        //         // Push right first in s2 stack.
        //         if(top->right)
        //             s2.push(top->right);
                
        //         if(top->left)
        //             s2.push(top->left);
    
        //     }
            
        //     while(!s2.empty())
        //     {
        //         Node *top = s2.top();
        //         ans.push_back(top->data);
                
        //         s2.pop();
                
        //         // Push left stack in S1 first.
        //         if(top->left)
        //             s1.push(top->left);
        //         if(top->right)
        //             s1.push(top->right);
        //     }
        // }
        
        // return ans;
        
    






    // Dequeu soln with flag.
    
    /*
    
        The idea is to use a deque. While travelling left to right we can poll and print the elements from the 
        front and insert their children(left child first followed by the right child) at the back.
        While travelling right to left we can poll and print the elements from the back and insert their
        children(right child first followed by the left child) at the front of the deque.


    */
    
        deque<Node *> dq;
        vector<int> ans;
        
        if(root == NULL)
            return ans;

        dq.push_back(root);
        
        // We will be moving right to left now.
        int flag = 0;
        
        while(!dq.empty())
        {
            int dqSize = dq.size();
            for(int i=0;i<dqSize;i++)
            {
                Node * f;
                if(flag == 1)
                {
                    f = dq.front();
                    dq.pop_front();
                    if(f->left)
                        dq.push_back(f->left);
                    if(f->right)
                        dq.push_back(f->right);
                }
                else
                {
                    f = dq.back();
                    dq.pop_back();
                    if(f->right)
                        dq.push_front(f->right);
                    if(f->left)
                        dq.push_front(f->left);
                }
                
                ans.push_back(f->data);
            }
            flag = !flag;
        }
        
        return ans;
}

