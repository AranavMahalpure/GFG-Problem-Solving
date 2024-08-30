//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<int>> res;
    bool check( int x, int y, int n, vector<vector<int>> &chessBoard ){
        int i, j;
        i = x-1; j = y;
        while ( i >= 0 ) if ( chessBoard[i--][j] == 1 ) return false;
        i = x+1; j = y;
        while ( i < n ) if ( chessBoard[i++][j] == 1 ) return false;
        i = x; j = y-1;
        while ( j >= 0 ) if ( chessBoard[i][j--] == 1 ) return false;
        i = x-1; j = y-1;
        while ( i >= 0 && j >= 0 ) if ( chessBoard[i--][j--] == 1 ) return false;
        i = x+1; j = y-1;
        while ( i < n && j >= 0 ) if ( chessBoard[i++][j--] == 1 ) return false;
        return true;
    }
    void rec( int j, int n, vector<int> &pos, vector<vector<int>> &chessBoard ){
        if ( j == n ){
            res.push_back(pos);
            return;
        }
        for ( int i = 0; i<n; i++ ){
            if ( check(i, j, n, chessBoard) ) {
                pos.push_back(i+1);
                chessBoard[i][j] = 1;
                rec(j+1, n, pos, chessBoard);
                chessBoard[i][j] = 0;
                pos.pop_back();
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> chessBoard(n+1, vector<int>(n+1, 0));
        vector<int> pos; rec(0, n, pos, chessBoard);
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends