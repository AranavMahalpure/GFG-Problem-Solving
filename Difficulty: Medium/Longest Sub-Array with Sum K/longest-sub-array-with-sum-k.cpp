//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    int lenOfLongSubarr(int A[],  int N, int K) 
    { 
        // Complete the function
        unordered_map<int,int> m;
        m[0]=0;
        int i = 0;
        int prefixSum = 0;
        int size = 0;
        while(i<N)
        {
            prefixSum+=A[i];
            
            
            if(m.count(prefixSum-K))
            {
                
                int j= m[prefixSum-K];
                
                size = max(size,i-j+1);
                
            }
            if(!m.count(prefixSum))
            m[prefixSum]=i+1;
            i++;
        }
        return size;
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