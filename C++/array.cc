#include <iostream>
using namespace std;
class ArrayError{};

template<typename T>
class Array
{
    unsigned int size_;
    T* data_;
    
public:
    Array(unsigned int size)
    : data_(new T[size]),
      size_(size)
    {
    }    
    
    ~Array()
    {
        delete [] data_;
    }
    
    T& at(unsigned int index)
    {
        if(index >= size_ || index < 0)
        {
            throw ArrayError();
        }
        return data_[index];   
    }
    
    T& operator[](unsigned int index)
    {
        return at(index);
    }
    
    int size() const
    {
        return size_;
    }
};

int main()
{
    Array<int> array(10);
    
    for(int i = 0; i < array.size(); ++i)
    {
        array.at(i) = i;
    }
    
    for(int i = 0; i < array.size(); ++i)
    {
        cout << array.at(i) << "  ";    
    }
    cout<< endl;
    
    Array<double> array2(10);
    
    for(int i = 0; i < array2.size(); i++)
    {
        array2[i] = i * 3.14;
    }
    
    for(int i = 0; i < array.size(); i++)
    {
        cout << array2[i] << "  ";
    }
    cout << endl;
    
    return 0;
}
