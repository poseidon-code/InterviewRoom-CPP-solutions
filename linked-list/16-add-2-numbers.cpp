// PROBLEM: Add two numbers
// https://leetcode.com/problems/add-two-numbers/
// ttps://www.interviewbit.com/problems/add-two-numbers-as-lists/


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
Node *add (Node *l1, Node *l2) {
    Node *head = new Node;
    Node *t = head;
    int c = 0;

    while (c || l1 || l2) {
        c += (l1 ? l1->data : 0) + (l2 ? l2->data : 0);
        
        Node *temp = new Node;
        temp->data = c%10;
        temp->next = NULL;
        
        t->next = temp;
        t = t->next;
        c /= 10;

        if (l1) l1 = l1->next;
        if (l2) l2 = l2->next;
    }
    
    return head->next;
}



int main() {
    // INPUT :
    LinkedList ll1, ll2;
    ll1.add(2);
    ll1.add(4);
    ll1.add(3);
    ll2.add(5);
    ll2.add(6);
    ll2.add(4);
    auto h1 = ll1.get_head();
    auto h2 = ll2.get_head();

    // OUTPUT :
    auto result = add(h1, h2);
    ll1.print(result);
    
    return 0;
}