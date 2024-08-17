//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    vector<int> replaceWithRank(vector<int> &arr, int N){
         // Create a copy of the original array and sort it
    vector<int> sortedArr = arr;
    sort(sortedArr.begin(), sortedArr.end());

    // Create a map to store the rank of each element
    unordered_map<int, int> mp;
    int rank = 1;

    // Assign ranks based on sorted order, only assigning a new rank to unique elements
    for (int i = 0; i < N; i++) {
        if (mp.find(sortedArr[i]) == mp.end()) {
            mp[sortedArr[i]] = rank++;
        }
    }

    // Replace original array elements with their respective ranks
    for (int i = 0; i < N; i++) {
        arr[i] = mp[arr[i]];
    }

    return arr;
    }

};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        vector<int> ans = obj.replaceWithRank(vec,n);
        for(int i = 0;i<n;i++) cout << ans[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends