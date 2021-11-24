#include <iostream>

template <class T>
class Stack {
private:
    struct Element {
        Element* next;
        T value;
    };
    Element* top;
    int64_t length;

public:
    Stack(): top(nullptr), length(0) {};
    ~Stack(){};

    void push(T value);
    T pop();
    int64_t getLength();
    T topElement();
};

template <class T>
void Stack<T>::push(T value) {
    // TODO: use smart pointer
    Element* new_element = new Element{top, value};
    top = new_element;
    length++;
    return;
}

template <class T>
T Stack<T>::pop() {
    // TODO: use smart pointer, don't use delete
    if (top == nullptr) return NULL;
    Element* top_next = top->next;
    T retval = top->value;
    delete top;
    top = top_next;
    length--;
    return retval;
}

template <class T>
int64_t Stack<T>::getLength() {
    return length;
}

int main() {
    Stack<int64_t> stack{};
    stack.push(1);
    stack.push(2);
    stack.push(3);
    std::cout << "stack pop = " << stack.pop() << std::endl;
    std::cout << "stack pop = " << stack.pop() << std::endl;
    std::cout << "stack pop = " << stack.pop() << std::endl;
    return 0;
}