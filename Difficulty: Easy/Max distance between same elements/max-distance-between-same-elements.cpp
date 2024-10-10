//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        // Code here
           unordered_map<int,int> m;
        
        int maxi = 0;
        
        for (int i = 0; i < arr.size(); i++) {
           if (m.find(arr[i]) != m.end()) {

            maxi = max(maxi, i - m[arr[i]]);
        } else {
            m[arr[i]] = i;
        }
    }
return maxi;
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

        stringstream s1(input);
        int num;
        while (s1 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.maxDistance(arr) << endl;
    }
    return 0;
}
// } Driver Code Ends