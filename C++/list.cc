#include <iostream>
using namespace std;

class ListError{};

template<typename T>
class List
{
    struct Element
    {
        T data_;
        Element* next_;
        
        Element(T val)
        : data_(val),
          next_(0)
        {
        }
    };
    Element* head_;
    
    public:
    List()
    : head_(0)
    {
    }
    
    bool empty() const
    {
        return head_ == 0;
    }
    
    void push_front(T val)
    {
        Element* new_element = new Element(val);
        
        new_element -> next_ = head_;
        head_ = new_element;
    }
    
    T front() const
    {
        if(empty())
        {
            throw ListError();
        }
        return head_ -> data_  ;
    }
    
    void pop_front()
    {
        if(empty())
        {
            throw ListError();
        }
        
        Element* old_head = head_;
        head_ = head_ -> next_;
        delete old_head;
    }
};

template<typename T>
class Stack : protected List<T>
{

    public:
    void push(T val)
    {
        List<T>::push_front(val);
    }
    
    T pop()
    {
        T res = List<T>::front();
        List<T>::pop_front();
        return res;
    }
};

int main()
{
    List<int> list;
    
    list.push_front(1023);
    cout << "Element: " << list.front() << endl;
    list.pop_front(); 
    cout << "Empty: " << list.empty() << endl;
    
    List<double> list2;
    
    for(int i = 0; i < 10; i++)
    {
        list2.push_front(i*3.14);
    }
    
    while(!list2.empty())
    {
        cout << list2.front() << ' ';
        list2.pop_front();
    }
    cout<< endl;
    
    Stack<int> stack1;
    
    //cout << stack1.empty() << endl;
    for(int i = 0; i < 10; ++i)
    {
        stack1.push(i*10);
        //stack1.push_front(i*20);
    }
    for(int i = 0; i < 10; ++i)
    {
        cout << stack1.pop() << ' ';
        //cout << stack1.front() << ' ';
        //stack1.pop_front();
    }
    cout << endl;
    return 0;
}
