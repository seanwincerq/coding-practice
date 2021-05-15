#include<iostream>

template<class T>
class SizedStack
{
public:
    SizedStack(const int size)
        : m_data(nullptr)
        , size(0)
    {
        m_data = new T[size];
    }

    ~SizedStack()
    {
        delete [] m_data;
    }

    void push(const T data)
    {
        m_data[size++] = data;
    }

    T pop()
    {
        if (!size)
        {
            std::cout << "Empty Stack\n";
            return T();
        }

        return m_data[--size];
    }

    void print()
    {
        for (int i = size - 1; i >= 0; --i)
        {
            std::cout << m_data[i] << " ";
        }
        std::cout << std::endl;
    }

private:
    T* m_data;
    int size;
};

int main()
{
    auto s = SizedStack<int>(10);
    s.push(1);
    s.push(2);
    s.push(3);
    s.print();

    s.pop();
    s.print();

    s.pop();
    s.print();

    s.pop();
    s.print();

    s.pop();
    s.print();
}