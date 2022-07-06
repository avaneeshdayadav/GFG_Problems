//Initial Template for C

#include <stdio.h>

int convertFive(int n);

// Driver program to test above function
int main() {
    int T;
    scanf("%d",&T);
    while (T--) {
        int n;
        scanf("%d",&n);
        printf("%d\n",convertFive(n));
    }
}
// } Driver Code Ends


//User function Template for C

int convertFive(int num) {
    // code here
if(num == 0)
return 5;

int temp = num,i=0;

while(temp){
 
    int ld = temp%10;
    
    if(ld ==0)
       num += 5*pow(10,i);

    temp /= 10;
    i++;
}
return num;
}
