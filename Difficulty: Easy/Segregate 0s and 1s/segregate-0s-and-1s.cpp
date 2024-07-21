//{ Driver Code Starts
// Initial template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  void swap(int &x, int &y) {
    int temp = x;
    x = y;
    y = temp;
}

void segregate0and1(std::vector<int> &a) {
    int st = 0, end = a.size() - 1;
    while (st < end) {
        if (a[st] == 0) {
            st++;
        }
        else if (a[end] == 1) {
            end--;
        }
        else {
            swap(a[st], a[end]);
            st++;
            end--;
        }
    }
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
        ob.segregate0and1(arr);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends