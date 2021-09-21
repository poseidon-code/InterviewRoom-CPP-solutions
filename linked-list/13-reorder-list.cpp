// PROBLEM: Reorder list
// https://leetcode.com/problems/reorder-list/
// https://www.interviewbit.com/problems/reorder-list/


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
Node *reorder (Node *head) {
    if (head==NULL || head->next==NULL)
        return head;

    Node *prev=NULL, *slow=head, *fast=head, *l1=head, *l2=NULL;

    while (fast!=NULL && fast->next!=NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = NULL;

    Node *p=NULL, *c=slow, *n=NULL;
    while (c!=NULL) {
        n=c->next;
        c->next=p;
        p=c;
        c=n;
    }
    l2 = p;

    while (l1!=NULL) {
        Node *n1=l1->next, *n2=l2->next;
        l1->next = l2;

        if (n1==NULL) break;

        l2->next=n1;
        l1=n1;
        l2=n2;
    }

    return head;
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
    ll.add(7);
    ll.add(8);
    ll.add(9);
    auto head = ll.get_head();

    // OUTPUT :
    auto result = reorder(head);
    ll.print(result);
    
    return 0;
}