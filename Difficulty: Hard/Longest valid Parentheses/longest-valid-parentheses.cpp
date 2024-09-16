//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maxLength(string& s) {
        // code here
          std::stack<int> stk;
    stk.push(-1);  // Base for the beginning of a valid substring
    int maxLength = 0;

    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            stk.push(i);
        } else {
            stk.pop();  // Pop the last unmatched '('
            if (stk.empty()) {
                stk.push(i);  // If stack is empty, push the current index as the base for future substrings
            } else {
                maxLength = std::max(maxLength, i - stk.top());  // Update maxLength
            }
        }
    }

    return maxLength;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.maxLength(S) << "\n";
    }
    return 0;
}
// } Driver Code Ends