// PROBLEM: Remove nth node from the end
// https://leetcode.com/problems/remove-nth-node-from-end-of-list/
// https://www.interviewbit.com/problems/remove-nth-node-from-list-end/


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
Node *remove_nth (Node *head, int n) {
    Node *slow = head, *fast = head;

    for (int i=0; i<=n; i++)
        fast = fast->next;

    while (fast != NULL) {
        slow = slow->next;
        fast = fast->next;
    }

    slow->next = slow->next->next;
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
    auto head = ll.get_head();

    // OUTPUT :
    auto new_head = remove_nth(head, 2);
    ll.print(new_head);

    return 0;
}