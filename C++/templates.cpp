#include <iostream>
using namespace std;

template<typename T>
void copy_array(T* dst, T* src, int size)
{
    for(int i = 0; i < size; i++)
    {
            dst[i] = src[i];
    }
}

int main()
{
    int a[] = {0,1,2,3,4,5,6,7,8,9};
    int b[10];
    
    copy_array<int>(b, a, 10);
    
    for(int i = 0; i < 10; i++)
    {
        cout << b[i] << ' ' ;
    }
    cout << endl;
    
    double e[] = {0.0, 1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};
    double f[10];
    
    copy_array<double>(f, e, 10);
    
    for(int i = 0; i < 10; i++)
    {
        cout << f[i] << ' ' ;
    }
    cout << endl;
    
    return 0;
}
