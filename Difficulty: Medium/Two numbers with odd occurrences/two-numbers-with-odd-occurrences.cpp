//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        // code here
        long long int xor_all = 0;

    // Step 1: XOR all the elements in the array
    for (long long int i = 0; i < N; ++i) {
        xor_all ^= Arr[i];
    }

    // Step 2: Find a bit that is set in xor_all (this bit must differ between the two numbers)
    long long int set_bit = xor_all & ~(xor_all - 1);

    // Step 3: Divide elements into two groups based on the set_bit and find the two odd occurring numbers
    long long int x = 0, y = 0;
    for (long long int i = 0; i < N; ++i) {
        if (Arr[i] & set_bit) {
            x ^= Arr[i];
        } else {
            y ^= Arr[i];
        }
    }

    // Ensure the numbers are returned in descending order
    if (x > y) {
        return {x, y};
    } else {
        return {y, x};
    }
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
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
// } Driver Code Ends