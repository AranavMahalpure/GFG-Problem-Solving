//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int a[],  int n, int k) 
    { unordered_map<int, int> sumMap;
        int sum = 0;
        int maxLength = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i];
            if (sum == k) {
                maxLength = i + 1;
            }
            
            if (sumMap.find(sum) == sumMap.end()) {
                sumMap[sum] = i;
            }
            
            if (sumMap.find(sum - k) != sumMap.end()) {
                maxLength = std::max(maxLength, i - sumMap[sum - k]);
            }
        }
        return maxLength;
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