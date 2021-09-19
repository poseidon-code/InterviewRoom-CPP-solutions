// PROBLEM: Segregate even and odd positioned nodes in linked list
// https://leetcode.com/problems/odd-even-linked-list/
// https://practice.geeksforgeeks.org/problems/rearrange-a-linked-list/1


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
Node *oddeven (Node *head) {
    if (head==NULL || head->next==NULL)
        return head;

    Node *odd = head, *even = head->next;

    if (even->next==NULL)
        return head;
    
    Node *c = even->next, *e;
    e = even;

    while (c!=NULL) {
        odd->next = c;
        e->next = c->next;
        odd = odd->next;
        e = e->next;

        if (e!=NULL) c = e->next;
        else break;
    }

    odd->next = even;
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
    auto result = oddeven(head);
    ll.print(result);
    
    return 0;
}