// PROBLEM: Find median in a stream
// https://practice.geeksforgeeks.org/problems/find-median-in-a-stream-1587115620/1

#include<iostream>
#include<queue>

using namespace std;

double median;
priority_queue<int> maxq;
priority_queue<int, vector<int>, greater<int>> minq;

// SOLUTION
void balance_heaps () {
    if (abs(int(maxq.size() - minq.size())) > 1) {
        if (maxq.size() > minq.size()) {
            minq.push(maxq.top());
            maxq.pop();
        } else {
            maxq.push(minq.top());
            minq.pop();
        }
    }
}

void insert_heap (int &x) {
    if (maxq.empty())
        maxq.push(x);
    else if (x > maxq.top())
        minq.push(x);
    else if (minq.empty()) {
        minq.push(maxq.top());
        maxq.pop();
        maxq.push(x);
    }
    else
        maxq.push(x);
    balance_heaps();
}

double get_median() {
    if ((maxq.size() + minq.size()) % 2 == 0) {
        median = (maxq.top() + minq.top());
        median /= 2;
    } else {
        if (minq.empty())
            median = maxq.top();
        else if (minq.size() < maxq.size())
            median = maxq.top();
        else
            median = minq.top();
    }

    return median;
}


int main() {
    // INPUT :
    vector<int> x = {5,15,1,3};

    // OUTPUT :
    for (auto i : x) {
        insert_heap(i);
        cout<<get_median()<<endl;
    }

    return 0;
}