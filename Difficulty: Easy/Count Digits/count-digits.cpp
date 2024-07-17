//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    int evenlyDivides(int N){ 
        vector<int> ans;
        int c=N;
        int res=0;
        while(N>0){
            int digit=N%10;
            N=N/10;
            ans.push_back(digit);
            
        }
        
        for(auto it:ans){
            if(it==0){
                continue;
            }
            else{
                
             if(c%it==0 && it!=0){
                res++;
            }   
            
            }
            
        }
        return res;
        //code here
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int N;
        cin>>N;
        Solution ob;
        cout << ob.evenlyDivides(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends