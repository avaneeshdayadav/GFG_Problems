//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        Node *root = NULL;
        int preIndx = 0;
        root = buildHelper(in,pre,0,n-1,preIndx,n);
        return root;
    }
    
    
    Node* buildHelper(int in[], int pre[], int st, int end, int &preIndx, int n)
    {
        if(st > end)
            return NULL;
        
        Node *newNode = new Node(pre[preIndx]);
        preIndx++;
        
        // Search this node in inorder.
        int splitIndx = searchInArr(in,newNode->data,n);
        
        // First build left subtree then right subtree. It's imp to do this way.
        newNode->left = buildHelper(in,pre,st,splitIndx-1,preIndx,n);
        newNode->right = buildHelper(in,pre,splitIndx+1,end,preIndx,n);
        
        return newNode;
    }
    
    int searchInArr(int in[], int key, int n)
    {
        for(int i=0;i<n;i++)
            if(in[i] == key)
                return i;
        
        return -1;
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends
