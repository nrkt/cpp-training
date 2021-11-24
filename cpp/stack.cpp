#include <memory>

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
    int64_t getLength();
    T getTop();
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
        return T{};
    }
    else {
        T top_val = top->value;
        top = std::move(top->next);
        length--;
        return top_val;
    }
};

template <class T>
int64_t Stack<T>::getLength() {
    return length;
};

template <class T>
T Stack<T>::getTop() {
    if (length == 0) {
        return T{};
    }
    else {
        return top->value;
    }
};
