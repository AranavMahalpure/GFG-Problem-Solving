//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

bool isSubSequence(vector<int> &v1, vector<int> &v2) {
    int m = v2.size();
    int n = v1.size();
    int j = 0; // For index of v2

    // Traverse v1 and v2
    for (int i = 0; i < n && j < m; i++) {
        if (v1[i] == v2[j]) {
            j++;
        }
    }
    return (j == m);
}


// } Driver Code Ends
// Function to find three numbers in the given array
// such that arr[smaller[i]] < arr[i] < arr[greater[i]]

class Solution {
  public:
    vector<int> find3Numbers(vector<int> &arr) {
        // Code here
         int n = arr.size();
        // preprocessing to get the left minimum and right maximum for every index i
        vector<int> left(n, -1), right(n, -1);
        int li = 0, ri=n-1;
        for(int i=1; i<n; ++i){
            // calculating left minimum
            if(arr[li]<arr[i]){
                left[i] = li;
            }else{
                li = i;
            }
            // calculating right maximum
            if(arr[ri]>arr[n-i-1]){
                right[n-i-1] = ri;
            }else{
                ri = n-i-1;
            }
        }
        for(int i=1; i<n; ++i){
            if(left[i]!=-1 && right[i]!=-1){
                return {arr[left[i]], arr[i], arr[right[i]]};
            }
        }
        return {};
    }
};

//{ Driver Code Starts.

// Driver program to test above function
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
        Solution obj;
        auto res = obj.find3Numbers(arr);
        // wrong format output
        if (!res.empty() and res.size() != 3) {
            cout << -1 << "\n";
        }

        if (res.empty()) {
            cout << 0 << "\n";
        } else if ((res[0] < res[1] and res[1] < res[2]) and isSubSequence(arr, res)) {
            cout << 1 << "\n";
        } else {
            cout << -1 << "\n";
        }
    }

    return 0;
}
// } Driver Code Ends