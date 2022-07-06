#include<bits/stdc++.h>
using namespace std;

int max_sum(int A[],int N);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        int N;
        cin>>N;
        int A[N];
        for(int i=0;i<N;i++)
        {
            cin>>A[i];
        }

        cout<<max_sum(A,N)<<endl;
        /*keeping track of the total sum of the array*/

    }
}
// } Driver Code Ends


/*You are required to complete this method*/
int max_sum(int arr[],int n)
{
//Your code here

    int arrSum = 0, currSum = 0, maxSum = 0;
    
    for(int i=0;i<n;i++)
    {
        currSum += arr[i]*i;
        arrSum += arr[i];
    }
        
    for(int i=0;i<n;i++)
    {
        currSum = currSum + arrSum - n*arr[n-i-1];
        // cout<<currSum<<endl;
        maxSum = max(currSum, maxSum);
    }
    return maxSum;
}
