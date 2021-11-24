#include <iostream>
#include <memory>
#include <cassert>

template <class T>
class Stack {
private:
    struct Element;
    std::shared_ptr<Element> top;
    int64_t length;

public:
    Stack(): top(nullptr), length(0) {};
    ~Stack(){};

    void push(T value);
    T pop();
};

template <class T>
struct Stack<T>::Element {
    std::shared_ptr<Element> next;
    T value;
};

template <class T>
void Stack<T>::push(T value) {
    top = std::make_shared<Element>(Element{top, value});
    length++;
    return;
};

template <class T>
T Stack<T>::pop() {
    if (length == 0) { // empty
        return 0;
    }
    else {
        T top_val = top->value;
        top = std::move(top->next);
        length--;
        return top_val;
    }
};

int main() {
    Stack<int64_t> stack{};
    stack.push(1);
    stack.push(2);
    stack.push(3);
    assert(stack.pop() == 3);
    assert(stack.pop() == 2);
    assert(stack.pop() == 1);
    assert(stack.pop() == 0);
    std::cout << "ok" << std::endl;
    return 0;
}
