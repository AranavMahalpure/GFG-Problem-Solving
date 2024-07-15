//{ Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    string is_palindrome(int num) {
        // Handle single-digit numbers
        if (num >= 0 && num <= 9) {
            return "Yes";
        }

        // Handle negative numbers
        if (num < 0) {
            return "No";
        }

        // Reverse the number
        long original = num;
        long reversed = 0;
        while (num > 0) {
            int rem = num % 10;
            num /= 10;
            if (reversed > (LONG_MAX - rem) / 10) {
                // Handle potential overflow
                return "No";
            }
            reversed = reversed * 10 + rem;
        }

        // Check if the original number is equal to the reversed number
        if (original == reversed) {
            return "Yes";
        }
        return "No";
    }
};


//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n;
    	cin >> n;
    	Solution ob;
    	string ans = ob.is_palindrome(n);
    	cout << ans <<"\n";
    }
	return 0;
}

// } Driver Code Ends