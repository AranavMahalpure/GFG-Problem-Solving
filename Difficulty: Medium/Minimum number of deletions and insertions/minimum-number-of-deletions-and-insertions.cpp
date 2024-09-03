//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
		

	public:

    int lcs(string &s1,string &s2,int m,int n,vector<vector<int>>&v)
    {
        if(m==0 || n==0)
        {
            v[m][n]=0;
            return v[m][n];
        }
        else if(s1[m-1]==s2[n-1])
        {
            if(v[m][n]!=-1)
            return v[m][n];
            else if(v[m][n]==-1)
            {
                v[m][n]=1+lcs(s1,s2,m-1,n-1,v);
                return v[m][n];
            }
        }
        else if(s1[m-1]!=s2[n-1])
        {
            if(v[m][n]!=-1)
            {
                return v[m][n];
            }
            else if(v[m][n]==-1)
            {
                v[m][n]=max(lcs(s1,s2,m-1,n,v),lcs(s1,s2,m,n-1,v));
                return v[m][n];
            }
        }
    }
    int minOperations(string str1, string str2) 
    {   int m=str1.size();
        int n=str2.size();
        vector<vector<int>>v(m+1,vector<int>(n+1,-1));
        int length=lcs(str1,str2,m,n,v);
        int minimumUpdates=0;
        if(length==0)
        {
            return m+n;
        }
        else
        {
             minimumUpdates+=m-length;
           minimumUpdates+=n-length;;
            return minimumUpdates;
        }
        
	} 
};

//{ Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;

	    Solution ob;
	    cout << ob.minOperations(s1, s2) << "\n";
	     
    }
    return 0;
}


// } Driver Code Ends