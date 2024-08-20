//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int minimumEnergy(vector<int>& height, int n) {
     if (n == 1) return 0;  // No energy needed if there's only one stair.
    vector<int> dp(n, 0);
    dp[0] = 0;
    dp[1] = abs(height[1] - height[0]);
    for (int i = 2; i < n; i++) {
        int oneStep = dp[i-1] + abs(height[i] - height[i-1]);
        int twoStep = dp[i-2] + abs(height[i] - height[i-2]);
        dp[i] = min(oneStep, twoStep);
    }

    return dp[n-1];
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends