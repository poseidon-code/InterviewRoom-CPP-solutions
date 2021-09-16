// PROBLEM: Reverse list in a group of given size k
// https://leetcode.com/problems/reverse-nodes-in-k-group/
// https://www.interviewbit.com/problems/k-reverse-linked-list/


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
Node *reverse (Node *first, Node *last) {
    Node *p = last;
    while (first!=last) {
        auto t = first->next;
        first->next = p;
        p = first;
        first = t;
    }
    return p;
}

Node *reverse_group (Node *head, int k) {
    Node *node = head;
    for (int i=0; i<k; i++) {
        if (!node)
            return head;
        node = node->next;
    }

    auto new_head = reverse(head, node);
    head->next = reverse_group(node, k);
    
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
    auto reversed = reverse_group(head, 2);
    ll.print(reversed);
    
    return 0;
}