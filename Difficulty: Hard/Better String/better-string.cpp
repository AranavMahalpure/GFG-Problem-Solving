//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
int countDistinctSubsequences(const string& str) {
    int n = str.length();
    vector<int> dp(n + 1, 0);
    dp[0] = 1; // The empty subsequence

    // Last occurrence map for each character
    vector<int> last(256, -1);

    for (int i = 1; i <= n; ++i) {
        dp[i] = 2 * dp[i - 1];

        // If the character has appeared before
        if (last[str[i - 1]] != -1) {
            dp[i] -= dp[last[str[i - 1]]];
        }

        // Update the last occurrence of the current character
        last[str[i - 1]] = i - 1;
    }

    // Subtract 1 to exclude the empty subsequence
    return dp[n] - 1;
}

// Function to determine the better string based on distinct subsequences
string betterString(string str1, string str2) {
    if (str1.empty()) return str2;
    if (str2.empty()) return str1;

    int count1 = countDistinctSubsequences(str1);
    int count2 = countDistinctSubsequences(str2);

    if (count1 > count2) {
        return str1;
    } else if (count2 > count1) {
        return str2;
    } else {
        return str1;  // If both have equal subsequences, return str1
    }
}
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string str1, str2;
        cin >> str1 >> str2;
        Solution obj;
        string ans = obj.betterString(str1, str2);
        cout << ans << "\n";
    }
}

// } Driver Code Ends