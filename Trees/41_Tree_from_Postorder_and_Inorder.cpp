/* program to construct tree using inorder and postorder traversals */
#include <bits/stdc++.h>
using namespace std;

/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


/* Tree node structure

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x){
        data = x;
        left = right = NULL;
    }
};*/

int searchInArr(int in[], int key, int n)
{
    for(int i=0;i<n;i++)
        if(in[i] == key)
            return i;
    
    return -1;
}


Node* buildHelper(int in[], int post[], int st, int end, int &preIndx, int n)
{
    if(st > end)
        return NULL;
    
    Node *newNode = new Node(post[preIndx]);
    preIndx--;
    
    // Search this node in inorder.
    int splitIndx = searchInArr(in,newNode->data,n);
    
    // First build right subtree & then left subteee it's imp to this way.
    newNode->right = buildHelper(in,post,splitIndx+1,end,preIndx,n);
    newNode->left = buildHelper(in,post,st,splitIndx-1,preIndx,n);

    return newNode;
}

Node *buildTree(int in[], int post[], int n) {
    // Your code here
    Node *root = NULL;
    int preIndx = n-1;
    root = buildHelper(in,post,0,n-1,preIndx,n);
    return root;
}

