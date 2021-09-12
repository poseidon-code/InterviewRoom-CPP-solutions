// PROBLEM: Intersection point in Y shaped linked list
// https://leetcode.com/problems/intersection-of-two-linked-lists/
// https://www.interviewbit.com/problems/intersection-of-linked-lists/


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


void createY(Node *headA, Node *headB, int skipA, int skipB) {
    Node *pA = headA, *pB = headB;
    for (int i=skipA; i>1; i--) pA = pA->next;
    for (int i=skipB; i>1; i--) pB = pB->next;
    pB->next = pA->next;
}


// SOLUTION
Node *intersection (Node *headA, Node *headB) {
    Node *pA = headA, *pB = headB;

    if (pA == NULL || pB == NULL) return NULL;

    while (pA!=NULL && pB!=NULL && pA!=pB) {
        pA = pA->next;
        pB = pB->next;

        if (pA == pB) return pA;
        if (pA == NULL) pA = headB;
        if (pB == NULL) pB = headA;
    }

    return pA;
}


int main() {
    // INPUT :
    LinkedList llA, llB;
    llA.add(4); llA.add(1); llA.add(8); llA.add(4); llA.add(5);
    llB.add(5); llB.add(6); llB.add(1); llB.add(8); llB.add(4); llB.add(5);
    auto headA = llA.get_head();
    auto headB = llB.get_head();

    // OUTPUT :
    createY(headA, headB, 2, 3);
    auto intersected = intersection(headA, headB);
    cout<<"Intersected at "<<intersected->data<<endl;

    return 0;
}