//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};

// Function to Build Tree


// } Driver Code Ends
/*
// Tree Node
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution {
    
  public:
  
    vector<Node*>arr1;
    vector<Node*>arr2;
    
    void traverse(Node* node,vector<Node*>&arr,Node* n1,Node* n2){
        //  cout<<node->data<<endl;
         arr.push_back(node);
        //  for(auto e:arr){
        //      cout<<e->data<<" ";
        //  }
        //  cout<<endl;
         if(node->data==n1->data) arr1=arr;
         if(node->data==n2->data) arr2=arr;
         if(node->left){
         traverse(node->left,arr,n1,n2);
         
         }
         if(node->right){
         traverse(node->right,arr,n1,n2);
         
         }
         arr.pop_back();
         
    }
    Node* LCA(Node* root, Node* n1, Node* n2) {
        // code here
        vector<Node*>arr;
        traverse(root,arr,n1,n2);
        map<int,int>mp;
        Node* answer;
        // cout<<endl;
        
        for(int i=arr1.size()-1;i>=0;i--){
            // cout<<arr1[i]->data<<" ";
            mp[arr1[i]->data]=1;
        }
        // cout<<endl;
        for(int i=arr2.size()-1;i>=0;i--){
            // cout<<arr2[i]->data<<" ";
            if(mp[arr2[i]->data]) {answer=arr2[i]; 
            // cout<<arr2[i]->data<<endl;
            break;
                
            }
        }
        return answer;
        
        
    }
};


//{ Driver Code Starts.

Node* buildTree(string str) {
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
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
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

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

int main() {

    int t;
    scanf("%d ", &t);
    while (t--) {
        string s;
        int l, h;
        getline(cin, s);
        scanf("%d ", &l);
        scanf("%d ", &h);
        Node* n1 = new Node(l);
        Node* n2 = new Node(h);
        Node* root = buildTree(s);
        Solution sol;
        int ans = sol.LCA(root, n1, n2)->data;
        cout << ans << endl;
        cout << "~"
             << "\n";
    }
    return 1;
}
// } Driver Code Ends