//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
    void leftRotate(vector<int>& arr, int d) {
        // code here
         int n = arr.size();
        if (n == 0 || d == 0 || d == n) return;
        
        // Normalize d to ensure it is within the bounds of the array length
        d = d % n;
        
        // Reverse the first d elements
        std::reverse(arr.begin(), arr.begin() + d);
        
        // Reverse the remaining n - d elements
        std::reverse(arr.begin() + d, arr.end());
        
        // Reverse the entire array
        std::reverse(arr.begin(), arr.end());
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        vector<int> arr;
        int d;
        string input;

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore(); // Ignore the newline character after d
        Solution ob;
        ob.leftRotate(arr, d);
        for (int x : arr) {
            cout << x << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends