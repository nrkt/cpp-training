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

// int main() {
//     Stack<int64_t> stack_int{};
//     stack_int.push(1);
//     stack_int.push(2);
//     stack_int.push(3);
//     assert(stack_int.pop() == 3);
//     assert(stack_int.pop() == 2);
//     assert(stack_int.pop() == 1);
//     assert(stack_int.pop() == 0);

//     Stack<char> stack_char{};
//     stack_char.push('1');
//     stack_char.push('2');
//     stack_char.push('3');
//     assert(stack_char.pop() == '3');
//     assert(stack_char.pop() == '2');
//     assert(stack_char.pop() == '1');

//     Stack<char*> stack_chars{};
//     stack_chars.push("11");
//     stack_chars.push("22");
//     stack_chars.push("33");
//     assert(stack_chars.pop() == "33");
//     assert(stack_chars.pop() == "22");
//     assert(stack_chars.pop() == "11");

//     struct stack_elem {
//         int64_t val;
//     };
    
//     Stack<stack_elem> stack_struct{};
//     stack_struct.push(stack_elem{1});
//     stack_struct.push(stack_elem{2});
//     stack_struct.push(stack_elem{3});
//     assert(stack_struct.pop().val == 3);
//     assert(stack_struct.pop().val == 2);
//     assert(stack_struct.pop().val == 1);

//     std::cout << "ok" << std::endl;

//     return 0;
// }
