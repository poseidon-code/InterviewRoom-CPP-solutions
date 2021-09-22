// PROBLEM: Delete N nodes after M nodes of a linked list
// https://practice.geeksforgeeks.org/problems/delete-n-nodes-after-m-nodes-of-a-linked-list/1


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
Node *delete_nodes (Node *head, int m, int n) {
    Node *c=head, *t=NULL;

    while (c) {
        int i, count;

        for (i=1; i<m && c!=NULL; i++)
            c = c->next;

        if (c==NULL) return head;

        t = c->next;
        for (count=1; count<=n && t!=NULL; count++) {
            Node *temp=t;
            t=t->next;
        }
        c->next = t;
        c=t;
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
    auto result = delete_nodes(head, 2, 5);
    ll.print(result);
    
    return 0;
}