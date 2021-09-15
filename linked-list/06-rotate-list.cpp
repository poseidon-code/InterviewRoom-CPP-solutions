// PROBLEM: Rotate a linked list
// https://leetcode.com/problems/rotate-list/
// https://www.interviewbit.com/problems/rotate-list/


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
Node *rotate (Node *head, int k) {
    if (!head) return head;

    int l = 1;
    Node *new_head = head, *tail = head;

    while (tail->next) {
        tail = tail->next;
        l++;
    }
    tail->next = head;

    if (k %= l)
        for (int i=0; i<l-k; i++)
            tail = tail->next;

    new_head = tail->next;
    tail->next = NULL;
    
    return new_head;
}


int main() {
    // INPUT :
    LinkedList ll;
    ll.add(1);
    ll.add(2);
    ll.add(3);
    ll.add(4);
    ll.add(5);
    auto head = ll.get_head();

    // OUTPUT :
    auto rotated = rotate(head, 2);
    ll.print(rotated);
    
    return 0;
}