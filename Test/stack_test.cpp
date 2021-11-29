#include "gtest/gtest.h"
#include "Stack/stack.hpp"

TEST(StackTest, Int) {
    Stack<int64_t> stack{};
    
    // push
    EXPECT_EQ(stack.getTop(), 0);
    EXPECT_EQ(stack.getLength(), 0);
    stack.push(1);
    EXPECT_EQ(stack.getTop(), 1);
    EXPECT_EQ(stack.getLength(), 1);
    stack.push(2);
    EXPECT_EQ(stack.getTop(), 2);
    EXPECT_EQ(stack.getLength(), 2);

    // pop
    EXPECT_EQ(stack.pop(), 2);
    EXPECT_EQ(stack.getLength(), 1);
    EXPECT_EQ(stack.pop(), 1);
    EXPECT_EQ(stack.getLength(), 0);
    EXPECT_EQ(stack.pop(), 0);
    EXPECT_EQ(stack.getLength(), 0);
};

TEST(StackTest, Char) {
    Stack<char> stack{};
    
    // push
    EXPECT_EQ(stack.getTop(), 0);
    EXPECT_EQ(stack.getLength(), 0);
    stack.push('1');
    EXPECT_EQ(stack.getTop(), '1');
    EXPECT_EQ(stack.getLength(), 1);
    stack.push('2');
    EXPECT_EQ(stack.getTop(), '2');
    EXPECT_EQ(stack.getLength(), 2);

    // pop
    EXPECT_EQ(stack.pop(), '2');
    EXPECT_EQ(stack.getLength(), 1);
    EXPECT_EQ(stack.pop(), '1');
    EXPECT_EQ(stack.getLength(), 0);
    EXPECT_EQ(stack.pop(), 0);
    EXPECT_EQ(stack.getLength(), 0);
};

TEST(StackTest, String) {
    Stack<char*> stack{};
    
    // push
    EXPECT_EQ(stack.getTop(), nullptr);
    EXPECT_EQ(stack.getLength(), 0);
    stack.push("11");
    EXPECT_EQ(stack.getTop(), "11");
    EXPECT_EQ(stack.getLength(), 1);
    stack.push("22");
    EXPECT_EQ(stack.getTop(), "22");
    EXPECT_EQ(stack.getLength(), 2);

    // pop
    EXPECT_EQ(stack.pop(), "22");
    EXPECT_EQ(stack.getLength(), 1);
    EXPECT_EQ(stack.pop(), "11");
    EXPECT_EQ(stack.getLength(), 0);
    EXPECT_EQ(stack.pop(), nullptr);
    EXPECT_EQ(stack.getLength(), 0);
};

TEST(StackTest, Struct) {
    struct stack_elem {
        int64_t val;
    };
    Stack<stack_elem> stack{};
    
    // push
    EXPECT_EQ(stack.getTop().val, 0);
    EXPECT_EQ(stack.getLength(), 0);
    stack.push(stack_elem{1});
    EXPECT_EQ(stack.getTop().val, 1);
    EXPECT_EQ(stack.getLength(), 1);
    stack.push(stack_elem{2});
    EXPECT_EQ(stack.getTop().val, 2);
    EXPECT_EQ(stack.getLength(), 2);

    // pop
    EXPECT_EQ(stack.pop().val, 2);
    EXPECT_EQ(stack.getLength(), 1);
    EXPECT_EQ(stack.pop().val, 1);
    EXPECT_EQ(stack.getLength(), 0);
    EXPECT_EQ(stack.pop().val, 0);
    EXPECT_EQ(stack.getLength(), 0);
};
