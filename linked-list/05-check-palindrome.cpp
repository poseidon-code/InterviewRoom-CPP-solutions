// PROBLEM: Check if a linked list is palindrome
// https://leetcode.com/problems/palindrome-linked-list/
// https://www.interviewbit.com/problems/palindrome-list/

#include<iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
};

class LinkedList {
    private:
        Node *head, *tail;
    public:
        LinkedList() {
            head = NULL;
            tail = NULL;
        }

        void add(int n) {
            Node *t = new Node;
            t->data = n;
            t->next = NULL;

            if (head==NULL) {
                head=t;
                tail=t;
            } else {
                tail->next = t;
                tail = tail->next;
            }
        }

        void print(Node *start) {
            Node *p;
            p = start;
            cout<<"[";
            while (p != NULL) {
                cout<<p->data<<" ";
                p=p->next;
            }
            cout<<"\b]"<<endl;
        }

        Node *get_head() {
            return head;
        }
};


// SOLUTION
bool is_palindrome (Node *head) {
    Node *rev = NULL;
    Node *slow = head, *fast = head;

    while (fast && fast->next) {
        Node *t = rev;
        fast = fast->next->next;
        rev = slow;
        slow = slow->next;
        rev->next = t;
    }

    if (fast) 
        slow = slow->next;
    
    while (rev && rev->data == slow->data) {
        slow = slow->next;
        rev = rev->next;
    }

    return !rev;
}


int main() {
    // INPUT :
    LinkedList ll;
    ll.add(1);
    ll.add(2);
    ll.add(3);
    ll.add(3);
    ll.add(2);
    ll.add(1);
    auto head = ll.get_head();

    // OUTPUT :
    is_palindrome(head) == 1 ? cout<<"true"<<endl : cout<<"false"<<endl;
    
    return 0;
}