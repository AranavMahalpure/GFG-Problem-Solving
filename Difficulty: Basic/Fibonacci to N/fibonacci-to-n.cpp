//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
    public:
    vector <int> nFibonacci(int N){
        //code here 
        std::vector<int> result;
        if (N < 0) {
            return {0};
            
        }

        long long a = 0, b = 1;
        result.push_back(a);
        if (N == 0) {
            return result;
        }
        result.push_back(b);
        while (true) {
            long long next = a + b;
            if (next > N) {break;}
            result.push_back(next);
            a = b;
            b = next;
        }

        return result;
    }
};

//{ Driver Code Starts.
int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        Solution ob;
        vector <int> ans=ob.nFibonacci(N);
        for(int u:ans)
         cout<<u<<" ";
        cout<<"\n"; 
    }
}
// } Driver Code Ends