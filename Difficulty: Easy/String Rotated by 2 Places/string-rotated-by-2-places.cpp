//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution
{   
    public:
    //Function to check if a string can be obtained by rotating
    //another string by exactly 2 places.
    string rotateanticlockwise(string s){

        char c=s[0];
        int i=0;
        while(i<s.size()){
            s[i]=s[i+1];
            i++;
        }
        s[s.size()-1]=c;
        return s;
    }
    string rotateclockwise(string s){
        char c=s[s.size()-1];
        int i=s.size()-2;
        while(i>=0){
            s[i+1]=s[i];
            i--;
        }
        s[0]=c;
        return s;
    }
    bool isRotated(string str1, string str2)
    {
        // Your code here
        if(str1.size()!=str2.size()){
            return 0;
        }
        string clockwise,anticlockwise;
        clockwise=rotateclockwise(str1);
        clockwise=rotateclockwise(clockwise);
        if(clockwise==str2){
            return 1;
        }
        anticlockwise=rotateanticlockwise(str1);
        anticlockwise=rotateanticlockwise(anticlockwise);
        if(anticlockwise==str2){
            return 1;
        }
        return 0;
    }

};


//{ Driver Code Starts.

int main() {
	
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		string b;
		cin>>s>>b;
		Solution obj;
		cout<<obj.isRotated(s,b)<<endl;
	}
	return 0;
}

// } Driver Code Ends