//{ Driver Code Starts


#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution{
	public:
	bool prime(int num){
	     if(num<=1){
	         return false;
	     }
	     if(num<=3){
	         return true;
	     }
	     if(num%2==0 || num%3==0){
	          return false;
	     }
	     for(int i=5;i<num;i++){
	         if(num%i==0 || num%i+2==0){
	             return false;
	         }
	     }
	     return true;
	     
	     
	}
	vector<int>AllPrimeFactors(int num) {
	    // Code here
	    vector<int>v;
	    for (int i=2;i<=num;i++){
	        if(num%i==0){
	            if(prime(i)){
	                v.push_back(i);
	            }
	        }
	    }
	    return v;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		long long int N;
		cin >> N;
		Solution ob;
		vector<int>ans = ob.AllPrimeFactors(N);
		for(auto i: ans)
			cout << i <<" ";
		cout <<"\n";
	}  
	return 0;
}
// } Driver Code Ends