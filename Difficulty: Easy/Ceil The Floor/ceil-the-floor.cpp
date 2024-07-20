//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User code template

class Solution {
  public:
     vector<int> getFloorAndCeil(int x, vector<int> arr) {
        // code here
        int n=arr.size();
        int c=-1,f=-1;
        for(int i=0;i<n;i++){
            if(arr[i]==x) return {x,x};
            if(c==-1 && arr[i]>x){
                c=arr[i];
            }else if(arr[i]>x && c>arr[i]){
                c=arr[i];
            }
            if(x>arr[i] && arr[i]>f) f=arr[i];
        }
        return {f,c};
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        vector<int> arr;
        int x;
        string input;
        cin >> x;
        cin.ignore();

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.getFloorAndCeil(x, arr);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends