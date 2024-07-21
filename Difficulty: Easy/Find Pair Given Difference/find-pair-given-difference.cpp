//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Array {
  public:
    template <class T>
    static void input(vector<T> &A, int n) {
        for (int i = 0; i < n; i++) {
            scanf("%d ", &A[i]);
        }
    }

    template <class T>
    static void print(vector<T> &A) {
        for (int i = 0; i < A.size(); i++) {
            cout << A[i] << " ";
        }
        cout << endl;
    }
};


// } Driver Code Ends

class Solution {
  public:
    int findPair(int n, int target, vector<int> &nums) {
        // code here 
        sort(nums.begin(),nums.end());
         int start = 0, end = 1;

    while (end < n) {
        int diff = nums[end] - nums[start];
        
        if (diff == target && start != end) {
            return 1;
        } 
        
        if (diff > target) {
            start++;
        } else {
            end++;
        }

        // Ensure that end is always ahead of start
        if (start == end) {
            end++;
        }
    }
    
    return -1;
}
};
   

//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        int n;
        scanf("%d", &n);

        int x;
        scanf("%d", &x);

        vector<int> arr(n);
        Array::input(arr, n);

        Solution obj;
        int res = obj.findPair(n, x, arr);

        cout << res << endl;
    }
}

// } Driver Code Ends