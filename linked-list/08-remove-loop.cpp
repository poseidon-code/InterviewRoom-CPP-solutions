// PROBLEM: Detect and remove loop in linked list
// https://leetcode.com/problems/linked-list-cycle-ii/
// https://www.interviewbit.com/problems/list-cycle/

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

void loop (Node *head, int p) {
    if (!head->next) return;
    if (p==-1) return;

    Node *tail = head, *node = head;
    while (tail->next) tail = tail->next;
    for (int i=0; i<p; i++) node = node->next;
    
    tail->next = node;
}


// SOLUTION
Node *remove_loop (Node *head) {
    if (head==NULL || head->next==NULL)
        return NULL;

    Node *slow = head, *fast = head, *entry = head;

    while (fast->next && fast->next->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow==fast) {
            while (slow != entry) {
                slow = slow->next;
                entry = entry->next;
            }
            return entry;
        }
    }

    return NULL;
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
    loop(head, 3);

    // OUTPUT :
    auto removed = remove_loop(head);
    removed == 0 ? 
        cout<<"no cycle"<<endl :
        cout<<"cycle at node valued "<<removed->data<<endl;
    
    return 0;
}