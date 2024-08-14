//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data % 10;
        node = node->next;
    }
    cout << "\n";
}


// } Driver Code Ends
// User function template for C++

/*

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};

*/

class Solution {
public:
    Node* addOne(Node* head) {
        // Reverse the linked list
        head = reverseList(head);

        // Add one to the reversed list
        Node* temp = head;
        int carry = 1; // Initial carry is 1 since we are adding one
        while (temp != NULL) {
            int sum = temp->data + carry;
            temp->data = sum % 10; // Update the current node with the digit
            carry = sum / 10; // Calculate the carry for the next node

            if (!temp->next && carry) {
                // If carry is left after processing the last node, add a new node
                temp->next = new Node(carry);
                carry = 0; // No more carry needed
            }
            temp = temp->next;
        }

        // Reverse the list again to restore the original order
        head = reverseList(head);
        return head;
    }

private:
    Node* reverseList(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;
        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        if (arr.empty()) {
            cout << -1 << endl;
            continue;
        }

        int data = arr[0];
        struct Node* head = new Node(data);
        struct Node* tail = head;
        for (int i = 1; i < arr.size(); ++i) {
            data = arr[i];
            tail->next = new Node(data);
            tail = tail->next;
        }
        Solution ob;
        head = ob.addOne(head);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends