//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
   long long countPairs(vector<int> &a, vector<int> &b) {
        // Your Code goes here.
        int n=(int)a.size();
        int m=(int)b.size();
        long long res=0;
        sort(b.begin(),b.end());
        map<int,int>mp;
        for(auto it:b)
        {
            mp[it]++;
        }
        for(int i=0;i<n;i++)
        {
            if(a[i]==1)
            continue;
            int x=a[i];
            if(a[i]==2)
            x+=2;
            int rem=upper_bound(b.begin(),b.end(),x)-b.begin();
            
            rem=m-rem;
            
            rem+=mp[1]*1LL;
            
            if(a[i]==3)
            rem+=mp[2]*1LL;
            // cout<<rem<<endl;
            res+=rem*1LL;
        }
        return res;
        
   }
};

//{ Driver Code Starts.

int main() {
    int T;
    cin >> T;
    cin.ignore();
    while (T--) {
        vector<int> ex;
        vector<int> a, b;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int num;
        while (ss >> num)
            ex.push_back(num);
        a = ex;
        getline(cin, input);
        ss.clear();
        ss.str(input);
        int num2;
        while (ss >> num2)
            b.push_back(num2);

        Solution ob;
        cout << ob.countPairs(a, b) << endl;
    }
}
// } Driver Code Ends