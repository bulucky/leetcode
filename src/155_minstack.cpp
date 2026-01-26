#include <list>
#include <stack>
#include <memory>
#include <iostream>
#include <algorithm>

class MinStack {
public:
    MinStack() {
        stack_ = std::make_unique<std::stack<int>>();
    }

    void push(int val) {
        stack_->push(val);
        mins_.push_back(val);
        mins_.sort();
    }

    void pop() {
        auto it = std::find(mins_.begin(), mins_.end(), stack_->top());
        mins_.erase(it);
        stack_->pop();
    }

    int top() {
        return stack_->top();
    }

    int getMin() {
        return mins_.front();
    }

private:
    std::list<int> mins_;
    std::unique_ptr<std::stack<int>> stack_;
};

int main(int argc, char const* argv[]) {
    MinStack* minstack = new MinStack;

    // minstack->push(-2);
    // minstack->push(-2);
    // minstack->push(0);
    // minstack->push(-3);
    // std::cout << minstack->getMin() << "\n";
    // minstack->pop();
    // std::cout << minstack->top() << "\n";
    // // std::cout << minstack->top() << "\n";
    // std::cout << minstack->getMin() << "\n";
    
    minstack->push(0);
    minstack->push(1);
    minstack->push(0);
    std::cout << minstack->getMin() << "\n";
    minstack->pop();
    std::cout << minstack->getMin() << "\n";
    minstack->pop();
    std::cout << minstack->getMin() << "\n";
    minstack->pop();
    minstack->push(-2);
    minstack->push(-1);
    minstack->push(-2);
    std::cout << minstack->getMin() << "\n";
    minstack->pop();
    std::cout << minstack->top() << "\n";
    std::cout << minstack->getMin() << "\n";
    minstack->pop();
    std::cout << minstack->getMin() << "\n";
    minstack->pop();
    

    delete minstack;

    return 0;
}