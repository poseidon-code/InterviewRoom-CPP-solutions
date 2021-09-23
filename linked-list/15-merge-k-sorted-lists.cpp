// PROBLEM: Merge k sorted lists
// https://leetcode.com/problems/merge-k-sorted-lists/
// https://www.interviewbit.com/problems/merge-two-sorted-lists/
// https://practice.geeksforgeeks.org/problems/merge-k-sorted-linked-lists/1


#include<iostream>
#include<vector>
#include<queue>

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
struct compare {
    bool operator()(const Node* l, const Node* r) {
        return l->data > r->data;
    }
};

Node *merge_sorted (vector<Node*> &lists) {
    priority_queue<Node*, vector<Node*>, compare> heap;
    Node head;
    Node *c = &head;
    int i, k, n = lists.size();

    for (i=0; i<n; i++)
        if (lists[i]) heap.push(lists[i]);

    while (!heap.empty()) {
        c->next = heap.top();
        heap.pop();
        c = c->next;
        if (c->next) heap.push(c->next);
    }

    return head.next;
}



int main() {
    // INPUT :
    LinkedList ll1, ll2, ll3;
    ll1.add(1);
    ll1.add(4);
    ll1.add(5);
    ll2.add(1);
    ll2.add(3);
    ll2.add(4);
    ll3.add(2);
    ll3.add(6);
    auto h1 = ll1.get_head();
    auto h2 = ll2.get_head();
    auto h3 = ll3.get_head();

    vector<Node*> lists = {h1, h2, h3};

    // OUTPUT :
    auto result = merge_sorted(lists);
    ll1.print(result);
    
    return 0;
}