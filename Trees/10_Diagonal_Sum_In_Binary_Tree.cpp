#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

vector<int> diagonalSum(Node*root);

int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
        Node* root = buildTree(s);
        vector <int> res = diagonalSum(root);
        for (int i : res) cout << i << " ";
        cout<<endl;
    }
    return 1;
}// } Driver Code Ends


/*Complete the function below
Node is as follows:
struct Node{
    int data;
    Node *left,*right;
};
*/

void diagonalUtil(Node *root, map<int,int> &dgSumMp, int currHt)
{
    if(root == NULL)
        return;
    
    // Travel all way to right without incrementing the height.
    diagonalUtil(root->right,dgSumMp, currHt);
    
    // Once traversed all right of this node add this node value to map[currHt]
    dgSumMp[currHt] += root->data;
    
    // Go left by incrementing height by one.
    diagonalUtil(root->left,dgSumMp, currHt+1);
    
}


vector <int> diagonalSum(Node* root) {
    
    map<int,int> dgSumMp;
    diagonalUtil(root,dgSumMp,0);
    
    int n = dgSumMp.size();
    
    vector<int> ans(n);
    
    for(auto it : dgSumMp)
        ans[it.first] = it.second;
        
    
    return ans;
}
