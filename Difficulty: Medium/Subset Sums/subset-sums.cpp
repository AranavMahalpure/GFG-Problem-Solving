//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   void findSubsetSums(int index, int n, int currentSum, vector<int>& arr, vector<int>& result) {
    if (index == n) {
        result.push_back(currentSum);
        return;
    }
    // Include the current element in the sum
    findSubsetSums(index + 1, n, currentSum + arr[index], arr, result);
    // Exclude the current element from the sum
    findSubsetSums(index + 1, n, currentSum, arr, result);
}

vector<int> subsetSums(vector<int> arr, int n) {
    vector<int> result;
    findSubsetSums(0, n, 0, arr, result);
    return result;
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
        Solution ob;
        vector<int> ans = ob.subsetSums(arr, N);
        sort(ans.begin(), ans.end());
        for (auto sum : ans) {
            cout << sum << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends