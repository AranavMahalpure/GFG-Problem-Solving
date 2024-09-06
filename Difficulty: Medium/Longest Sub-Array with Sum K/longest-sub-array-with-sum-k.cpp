//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int v[],  int N, int k ) 
    { 
        // Complete the function
          unordered_map<int, int> mp;
    int sum = 0, max_len = 0;
    
    for (int i = 0; i < N; i++) {
        sum += v[i];
        
        if (sum == k) {
            max_len = i + 1;
        }
        
        if (mp.find(sum - k) != mp.end()) {
            max_len = max(max_len, i - mp[sum - k]);
        }
        
        if (mp.find(sum) == mp.end()) {
            mp[sum] = i;
        }
    }
    
    return max_len;
    } 
};

//{ Driver Code Starts.

int main() {
	//code
	
	int t;cin>>t;
	while(t--)
	{
	    int n, k;
	    cin>> n >> k;
	    int a[n];
	    
	    for(int i=0;i<n;i++)
	        cin>>a[i];
	   Solution ob;
	   cout << ob.lenOfLongSubarr(a, n , k)<< endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends