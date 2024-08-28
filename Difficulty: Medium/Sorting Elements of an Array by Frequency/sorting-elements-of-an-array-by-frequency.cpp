//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // Complete this function
    // Function to sort the array according to frequency of elements.
    vector<int> sortByFreq(vector<int>& arr) {
        // Your code here
          map<int, int> m;
        for(auto i:arr){
            m[i]++;
        }
        vector<pair<int, int> > vp;
        for(auto i:m){
            vp.push_back(i);
        }
        stable_sort(vp.begin(), vp.end(), [](auto &left, auto &right) {
            return right.second < left.second;
        });
        vector<int> v;
        for(auto& p : vp) {
            while(p.second--){
                v.push_back(p.first);
            }
        }
        return v;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string input;
        int num;
        vector<int> arr;

        getline(cin, input);
        stringstream s2(input);
        while (s2 >> num) {
            arr.push_back(num);
        }
        Solution obj;
        vector<int> v;
        v = obj.sortByFreq(arr);
        for (int i : v)
            cout << i << " ";
        cout << endl;
    }

    return 0;
}

// } Driver Code Ends