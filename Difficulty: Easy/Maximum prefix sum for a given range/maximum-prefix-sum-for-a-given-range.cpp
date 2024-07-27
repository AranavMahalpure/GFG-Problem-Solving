//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution{
  public:
    vector<int> maxPrefixes(int a[], int l[], int r[], int N, int q) {
    vector< int > ms( q );
    for ( int i=0; i < q; ++i ) {
        int ps{ ms[ i ] = a[ l[ i ]] };
        while ( ++l[ i ] <= r[ i ] )
            ms[ i ] = max( ms[ i ], ps += a[ l[ i ]] );
    }
    return ms;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, q;
        cin >> n >> q;
        int a[n], L[q], R[q];
        
        for (int i = 0; i < n; i++) cin >> a[i];

        for (int i = 0; i < q; i++) cin >> L[i] >> R[i];
        Solution obj;
        vector<int> ans = obj.maxPrefixes(a, L, R, n, q);
        for (auto it : ans) 
            cout << it << " ";
        cout << endl;
    }
}

// } Driver Code Ends