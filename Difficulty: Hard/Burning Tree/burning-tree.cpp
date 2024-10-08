//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};


Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
//User function Template for C++

/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  public:
   void trav(Node* root,int target,Node* &targetNode,unordered_map<Node*,Node*> &m,Node* prev){
        if(root == NULL){
            return ;
        }
        m[root]=prev;
        if(root->data == target){
            targetNode = root;
        }
        trav(root->left,target,targetNode,m,root);
        trav(root->right,target,targetNode,m,root);
    }
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        Node* targetNode = NULL;
        Node* prev = NULL;
        unordered_map<Node*, Node*> m;
        trav(root, target, targetNode, m, prev);
        
        // Step 2: BFS to simulate the burning process
        unordered_map<Node*, bool> visited;
        queue<Node*> q;
        q.push(targetNode);
        visited[targetNode] = true;
        
        int time = 0;
        
        while(!q.empty()) {
            int size = q.size();
            bool burned = false;
            for(int i = 0; i < size; i++) {
                Node* curr = q.front();
                q.pop();
                
                if(curr->left && !visited[curr->left]) {
                    q.push(curr->left);
                    visited[curr->left] = true;
                    burned = true;
                }
                
                if(curr->right && !visited[curr->right]) {
                    q.push(curr->right);
                    visited[curr->right] = true;
                    burned = true;
                }
                
                if(m[curr] && !visited[m[curr]]) {
                    q.push(m[curr]);
                    visited[m[curr]] = true;
                    burned = true;
                }
            }
            if(burned) {
                time++;
            }
        }
        
        return time;
        
}
};

//{ Driver Code Starts.

int main() 
{
    int tc;
    scanf("%d ", &tc);
    while (tc--) 
    {    
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin>>target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout<<obj.minTime(root, target)<<"\n"; 

        cin.ignore();

    }


    return 0;
}

// } Driver Code Ends