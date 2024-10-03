//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   vector<int> findMajority(vector<int>& nums) {
    vector<int> ans;
    int n = nums.size();
    unordered_map<int, int> mp;

    // Count the frequency of each element
    for (int num : nums) {
        mp[num]++;
    }

    // Check for elements that appear more than n/3 times
    for (auto it : mp) {
        if (it.second > n / 3) {
            ans.push_back(it.first);
        }
    }
     sort(ans.begin(),ans.end());
    // Return {-1} if no majority elements are found
    return ans.size() == 0 ? vector<int>{-1} : ans;
}
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<int> ans = ob.findMajority(nums);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends