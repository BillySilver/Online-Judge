class Stack {
    int now;
    queue<int> q[2];

public:
    Stack() {
        now = 0;
    }
    // Push element x onto stack.
    void push(int x) {
        q[!now].push(x);
        while (!q[now].empty()) {
            q[!now].push( q[now].front() );
            q[now].pop();
        }
        now = !now;
    }

    // Removes the element on top of the stack.
    void pop() {
        q[now].pop();
    }

    // Get the top element.
    int top() {
        return q[now].front();
    }

    // Return whether the stack is empty.
    bool empty() {
        return q[now].empty();
    }
};
