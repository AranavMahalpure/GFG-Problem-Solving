//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int pairsum(vector<int> &arr) {
        // code here
        int n = arr.size();
    if (n < 2) {
        // If there are less than 2 elements, return -1 (or handle as per your logic)
        return -1;
    }

    int firstLargest = INT_MIN, secondLargest = INT_MIN;

    // Traverse through the array
    for (int i = 0; i < n; i++) {
        if (arr[i] > firstLargest) {
            // Update second largest before first largest
            secondLargest = firstLargest;
            firstLargest = arr[i];
        } else if (arr[i] > secondLargest && arr[i] != firstLargest) {
            // Update second largest if arr[i] is not equal to first largest
            secondLargest = arr[i];
        }
    }

    // If there is no valid second largest (all elements are the same)
    if (secondLargest == INT_MIN) {
        return -1;  // Handle this case as per your need
    }

    return firstLargest + secondLargest;
    }
};


//{ Driver Code Starts.
int main() {
    int t;

    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int n = arr.size();
        Solution ob;
        int r = ob.pairsum(arr);
        cout << r << endl;
    }
    return 0;
}
// } Driver Code Ends