//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
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

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
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

class Solution
{
    public:
    
    struct Node* reverse(struct Node* root){
        if(root==0 || root->next==0){
            return root;
        }
        struct Node*t=root;
        struct Node*p=0;
        struct Node*c;
        while(t){
            c=t->next;
            t->next=p;
            p=t;
            t=c;
        }
        return p;
    }

    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
    
        while(first && first->data==0){
            first=first->next;
        }
        while(second && second->data==0){
            second=second->next;
        }
        if(!first && !second) return new Node(0);
        if(!first) return second;
        if(!second) return first;
        first=reverse(first);
        second=reverse(second);
        struct Node* a=new struct Node(-1);
        struct Node*t=a;
        int r=0;
       while(first!=0 || second!=0 || r!=0){
            int sum=0;
            if(first!=NULL){
                sum+=first->data;
                first=first->next;
            }
            if(second!=NULL){
                sum+=second->data;
                second=second->next;
            }
            sum+=r;
            r=sum/10;
            Node* node=new Node(sum%10);
            t->next=node;
            t=t->next;
        }
        a->next=reverse(a->next);
        return a->next;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* num1 = buildList(n);
        
        cin>>m;
        Node* num2 = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(num1,num2);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends