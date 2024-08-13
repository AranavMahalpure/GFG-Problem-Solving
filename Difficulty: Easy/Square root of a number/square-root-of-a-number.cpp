//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// Function to find square root
// x: element to find square root
class Solution {
  public:
    // User function Template for C
long long int floorSqrt(long long int n) {
    if(n == 0 || n == 1)
        return n;
    
    long long int start = 0;
    long long int end = n;
    long long int mid;
    long long int ans = -1;
    
    while(start <= end){
        mid = start + (end - start) / 2;
        if(mid * mid == n){
            return mid;
        }
        else if(mid * mid > n){
            end = mid - 1;
        }
        else{
            ans = mid;
            start = mid + 1;
        }
    }
    
    return ans;
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        Solution obj;
        cout << obj.floorSqrt(n) << endl;
    }
    return 0;
}

// } Driver Code Ends