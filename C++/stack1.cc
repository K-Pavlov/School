#include <iostream>
#include <string>
using namespace std;

class StackError{};

template<typename T>
class Stack
{
    const static int SIZE = 10;
    T data_[SIZE];
    int top_;
public:
    Stack()
    : top_(0)
    {        
    }
    
    bool empty() const
    {
        return top_ == 0;
    }
    
    bool full() const
    {
        return top_ == SIZE;
    }
    
    void push(T val)
    {
        if(full())
        {
            throw StackError();
        }
        data_[top_++] = val;
    }
    
    T pop()
    {
        if(empty())
        {
            throw StackError();
        }
        return data_[--top_]; 
    }
};

int main()
{
    Stack<int> stack;
    
    for(int i = 0; i < 10; i++)
    {
        stack.push(10);
    }
    stack.pop();
    
    Stack<double> stack2;
    
    for(int i = 0; i < 10; i++)
    {
        stack2.push(i*3.14);
    }
    
    while(!stack2.empty())
    {
        cout << stack2.pop() << endl;
    }
    
    Stack<string> stack3;
    
    for(int i = 0; i < 10; i++)
    {
        stack3.push("hello");
    }
    
    while(!stack3.empty())
    {
        cout << stack3.pop() << endl;
    }
    return 0;
}
