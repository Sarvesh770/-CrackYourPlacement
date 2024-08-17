//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// Node Class
class Node {
public:
    int data;
    Node* next;

    Node(int val) : data(val), next(NULL) {}
};

// Linked List Class
class LinkedList {
public:
    Node* head;
    Node* tail;

    LinkedList() : head(NULL), tail(NULL) {}

    // creates a new node with given value and appends it at the end of the linked list
    void insert(int val) {
        if (head == NULL) {
            head = new Node(val);
            tail = head;
        } else {
            tail->next = new Node(val);
            tail = tail->next;
        }
    }
};


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    Node* subLinkedList(Node* head1, Node* head2) {
        // Your implementation of subLinkedList goes here
        // Make sure to return the head of the resulting linked list
        while(head1 && head1->data==0) head1 = head1->next;
        
        while(head2 && head2->data==0) head2 = head2->next;
        
        if(head1==0 && head2==0) return new Node(0);
        if(head1==0) return head2;
        if(head2==0) return head1;
        
        int f = -1; // if the first digit of head1 > head2
        
        
        
        stack<int>st1, st2;
        while(head1 || head2) {
            
            if(head1 && head2){
                if(f==-1){
                    if(head1->data<head2->data){
                        f = 0;
                    }
                    else if(head1->data>head2->data) {
                        f = 1;
                    }
                }
            }
            
            if(head1){
            st1.push(head1->data);
            head1 = head1->next;
            }
            
            if(head2){
            st2.push(head2->data);
            head2 = head2->next;
            }
        }
        
        
        if(st1.size()<st2.size()) swap(st1,st2);
        else if(st1.size()==st2.size() && f==0) swap(st1,st2);
        
        // Now st1 is Big number and st2 is small.  perform st1 - st2
        
        Node* ans = new Node(0);
        
        int borrow = 0;
        while(!st1.empty()){
            
            int val = st1.top() + borrow;
            borrow = 0;
            st1.pop();
            if(!st2.empty()) {
                val -= st2.top(); st2.pop();
            }
            
            if(val<0){
                borrow = -1;
                val+=10;
            }
            
            Node * newNode = new Node(val);
            newNode->next = ans->next;
            ans->next = newNode;
            
        }
        
        
        while(ans->next && ans->data==0) ans = ans->next;
        
        return ans;
        return NULL;
    }
};

//{ Driver Code Starts.

// prints the elements of linked list starting with head
void printList(Node* n) {
    while (n) {
        cout << n->data;
        n = n->next;
    }
    cout << endl;
}

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; ++i) {
        int n;
        cin >> n;
        LinkedList LL1;
        string l1,l2;
        cin>>l1;
        for (int j = 0; j < n; ++j) {
            int x=(l1[j]-'0');
            LL1.insert(x);
        }

        int m;
        cin >> m;
        LinkedList LL2;
        cin>>l2;
        for (int j = 0; j < m; ++j) {
            int x=(l2[j]-'0');
            LL2.insert(x);
        }

        Solution ob;
        Node* res = ob.subLinkedList(LL1.head, LL2.head);
        printList(res);
    }

    return 0;
}

// } Driver Code Ends