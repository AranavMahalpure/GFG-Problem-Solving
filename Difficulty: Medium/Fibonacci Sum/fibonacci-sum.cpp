//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
public:
    long long int fibSum(long long int N){
        //code her
        if (N > 100000)
        return -1; // Return -1 for invalid input

    int f[N + 1]; // Using vector to dynamically allocate array

    f[0] = 0;
    f[1] = 1;
    long long int sum = f[0] + f[1]; // Start sum with initial values

    for (int i = 2; i <= N; i++) {
        f[i] = (f[i-1] + f[i-2])%1000000007;
        sum = (sum + f[i])%1000000007;
    }
  
    return sum;
        
        
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        Solution ob;
        cout << ob.fibSum(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends