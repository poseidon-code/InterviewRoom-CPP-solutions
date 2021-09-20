// PROBLEM: Segregate even and odd valued nodes in a linked list 
// https://www.geeksforgeeks.org/segregate-even-and-odd-elements-in-a-linked-list/


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
Node *oddeven_values (Node *head) {
    if (head==NULL || head->next==NULL)
        return head;

    Node *es=NULL, *ee=NULL, *os=NULL, *oe=NULL;
    Node *c = head;

    while (c!=NULL) {
        int val = c->data;

        if (val%2 == 0) {
            if (es==NULL) {
                es = c;
                ee = es;
            } else {
                ee->next = c;
                ee = ee->next;
            }
        } else {
            if (os==NULL) {
                os = c;
                oe = os;
            } else {
                oe->next = c;
                oe = oe->next;
            }
        }

        c = c->next;
    }

    if (os==NULL || es==NULL) return NULL;

    ee->next = os;
    oe->next = NULL;

    return es;
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
    auto result = oddeven_values(head);
    ll.print(result);
    
    return 0;
}