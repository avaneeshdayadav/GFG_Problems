void inorder(Node *root, int currLvl, vector<int> &oddLvlArr)
{
    if(root == NULL)
        return;
    
    inorder(root->left, currLvl+1, oddLvlArr);
    
    if(currLvl%2 != 0)
        oddLvlArr.push_back(root->data);
        
    inorder(root->right, currLvl+1, oddLvlArr);
}

void updOddLvl(Node *root, int currLvl, vector<int> &oddLvlArr, int &indx)
{
    if(root == NULL)
        return;
    
    updOddLvl(root->left, currLvl+1, oddLvlArr, indx);
    
    if(currLvl % 2 != 0)
    {
        root->data = oddLvlArr[indx];
        indx++;
    }

    updOddLvl(root->right, currLvl+1, oddLvlArr, indx);
}

void reverseAlternate(Node *root)
{
    int lvl = 0;
    vector<int> oddLvlArr;
    
    // Store only odd lvl elements of inorder traversal in array.
        inorder(root,0,oddLvlArr);
    
    // Rev Array.
    
        int s = 0, e = oddLvlArr.size()-1;
        
        while(s<e)
        {
            swap(oddLvlArr[s],oddLvlArr[e]);
            s++;
            e--;
        }
    
    
    // Update tree using rev array and inorder traversal.
        int indx = 0;
        updOddLvl(root,0,oddLvlArr,indx);
}
