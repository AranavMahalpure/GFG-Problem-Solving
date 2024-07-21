//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
  public:
    int findPairs(long long a[], long long n)
    {
        //code here.
          unordered_set<int>s;
        for(int i=0;i<n;i++)
        {
            int key1=a[i];
            for(int j=i+1;j<n;j++)
            {
                int key2=a[j];
                if(s.find(key1+key2)==s.end())
                {
                    s.insert(key1+key2);
                }
                else
                {
                    return 1;
                }
            }
        }
        return 0;
    }
};

//{ Driver Code Starts.
int main() {
	long long t;
	
	cin >> t;
	
	while(t--){
	    long long n;
	    cin >> n;
	    long long a[n];
	    for(long long i = 0;i<n;i++){
	        cin >> a[i];
	        // um[a[i]]++;
	    }
	    Solution ob;
	    cout << ob.findPairs(a, n) << endl;   
	    }
	return 0;
}

// } Driver Code Ends