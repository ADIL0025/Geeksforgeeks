//{ Driver Code Starts
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

Node* buildList() {
    vector<int> arr;
    string input;
    getline(cin, input);
    stringstream ss(input);
    int number;
    while (ss >> number) {
        arr.push_back(number);
    }
    if (arr.empty()) {
        return NULL;
    }
    int val = arr[0];
    int size = arr.size();

    Node* head = new Node(val);
    Node* tail = head;

    for (int i = 1; i < size; i++) {
        val = arr[i];
        tail->next = new Node(val);
        tail = tail->next;
    }

    return head;
}

void printList(Node* n) {
    while (n) {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

#include<stack>;
class Solution {
  public:
  Node* addTwoLists(Node* num1, Node* num2) {
    stack<int> s1, s2;
    while (num1 != nullptr) {
        s1.push(num1->data);
        num1 = num1->next;
    }
    while (num2 != nullptr) {
        s2.push(num2->data);
        num2 = num2->next;
    }

    int carry = 0;
    Node* result = nullptr;
    while (!s1.empty() || !s2.empty() || carry > 0) {
        int sum = carry;

        if (!s1.empty()) {
            sum += s1.top();
            s1.pop();
        }
        if (!s2.empty()) {
            sum += s2.top();
            s2.pop();
        }

        carry = sum / 10;
        sum = sum % 10;
        Node* newNode = new Node(sum);
        newNode->next = result;
        result = newNode;
    }
    while (result != nullptr && result->data == 0) {
        Node* temp = result;
        result = result->next;
        delete temp;
    }
    if (result == nullptr) {
        return new Node(0);
    }

    return result;
}
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // To ignore the newline character after the integer input

    while (t--) {
        Node* num1 = buildList();
        Node* num2 = buildList();
        Solution ob;
        Node* res = ob.addTwoLists(num1, num2);
        printList(res);
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends