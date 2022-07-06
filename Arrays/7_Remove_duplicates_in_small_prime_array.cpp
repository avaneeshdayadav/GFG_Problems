

 // } Driver Code Ends
class Solution{
  public:
    vector<int> removeDuplicate(vector<int>& arr, int n)
    {
        // code here
        
        // code here
       int j = 1;
       unordered_set<int> st;
       st.insert(arr[0]);
       for(int i=1;i<n;i++)
       {
           if(st.find(arr[i])==st.end())
           {
               arr[j++] = arr[i];
               st.insert(arr[i]);
           }
       }
    //   for(int i=0;i<n-j;i++)
    //       arr.pop_back();
        arr.erase(arr.begin()+j,arr.end());
       return arr;
    }
};

// { Driver Code Starts.
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        vector<int> A(N);
        for(int i=0;i<N;i++)
        {
            cin>>A[i];
        }
        Solution obj;
        vector<int>result = obj.removeDuplicate(A,N);
        for(int i =0;i<result.size();i++)
            cout<<result[i]<<" ";
        cout<<endl;

    }
}
  // } Driver Code Ends
