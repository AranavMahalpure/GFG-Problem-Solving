//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    // Function to reverse words in a given string.
    string reverseWords(string str) {
        // code here
    stack<string> st;
    int i = 0;
    int n = str.length();
    while (i < n) {
        string s;
        while (i < n && str[i] != '.') { 
            s += str[i];
            i++;
        }
        st.push(s);
        i++; 
    }
    
    string ans;
    while (!st.empty()) {
        ans += st.top();
        st.pop();
        if (!st.empty()) {
            ans += '.'; 
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
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
// } Driver Code Ends