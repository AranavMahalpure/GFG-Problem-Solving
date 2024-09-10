//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
     void dfs(int node,vector<int>adj[],vector<int>&vis){
        // first visit the current node and then go for their neighbour:
        vis[node]=1;
        
        for(auto &it: adj[node]){
            if(!vis[it]){
                dfs(it,adj,vis);
            }
        }
    }
    int isCircle(vector<string> &arr) {
        vector<int>adj[26];
        vector<int>in(26,0),out(26,0);
        /*basically this part is generating directed graph and maintain the inDegree and outDegree of the respective char*/
        for(auto it:arr){
            int u=it[0]-'a';
            int v=it[it.size()-1]-'a';
            adj[u].push_back(v);
            in[v]++;
            out[u]++;
        }
        /*now check for indegree=outdegree ?? */
        for(int i=0;i<26;i++){
            if(in[i]!=out[i]) return 0;
        }
        /*now check if they are making one circle or not ?? there may be the chance of multiple cicle but we need one circle only
         1.abc ,cba,klm,mlk they are making two circle ,first will be between (abc,cba) and other (klm,mlk) so we need only one 
         circle so this would be the wrong answer for this case;*/
        //for connected components we will use dfs
        vector<int>vis(26,0);
        dfs(arr[0][0]-'a',adj,vis);
        
        // Now check for any node whose indegree or outdegree is not zero and not visited
        for(int i=0;i<26;i++){
            if(!vis[i] and in[i]) return 0;
        }    
        
        return 1;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<string> A;
        string s;

        for (int i = 0; i < N; i++) {
            cin >> s;
            A.push_back(s);
        }

        Solution ob;
        cout << ob.isCircle(A) << endl;
    }
    return 0;
}
// } Driver Code Ends