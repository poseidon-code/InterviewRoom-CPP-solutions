// PROBLEM: Reverse a linked list
// https://leetcode.com/problems/reverse-linked-list/
// https://www.interviewbit.com/problems/reverse-linked-list/


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
Node *reverse (Node *head) {
    Node *c = NULL;
    while (head) {
        Node *n = head->next;
        head->next = c;
        c = head;
        head = n;
    }
    return c;
}


int main() {
    // INPUT :
    LinkedList ll;
    ll.add(1);
    ll.add(2);
    ll.add(3);
    ll.add(4);
    ll.add(5);
    ll.add(6);
    auto head = ll.get_head();

    // OUTPUT :
    auto reversed = reverse(head);
    ll.print(reversed);
    
    return 0;
}