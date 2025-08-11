#include <queue>
using namespace std;

class MyStack {
public:
    queue<int> q1; // main queue
    queue<int> q2; // helper queue

    MyStack() {}

    // Push element x onto stack.
    void push(int x) {
        q1.push(x);
    }

    // Removes the element on top of the stack and returns it.
    int pop() {
        // Move elements from q1 to q2, leaving last element in q1
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        // Last element in q1 is the top of stack
        int topElem = q1.front();
        q1.pop();

        // Swap q1 and q2 so q1 has all elements again
        swap(q1, q2);

        return topElem;
    }

    // Get the top element.
    int top() {
        // Similar to pop, but don't remove the element
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        int topElem = q1.front();
        q2.push(topElem); // Put it back into q2
        q1.pop();

        swap(q1, q2);

        return topElem;
    }

    // Returns whether the stack is empty.
    bool empty() {
        return q1.empty();
    }
};


/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */