//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    long long x=1;
  long long i=1;
  vector <long long>v;
    vector<long long> factorialNumbers(long long n) {
         if(x>n)
         {
             return v;
         }
            v.push_back(x);
            i++;
            x=x*i;
            return factorialNumbers(n);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        long long N;
        cin >> N;
        Solution ob;
        vector<long long> ans = ob.factorialNumbers(N);
        for (auto num : ans) {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends