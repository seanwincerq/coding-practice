#include <iostream>


template<class T>
class SizedQueue
{
public:
    SizedQueue(const int size)
        : m_data(nullptr)
        , head(0)
        , tail(0)
    {
        m_data = new T[size];
    }

    ~SizedQueue()
    {
        delete [] m_data;
    }

    void push(const T data)
    {
        m_data[tail++] = data;
    }

    T pop()
    {
        if (empty())
        {
            std::cout << "Empty Queue\n";
            return T();
        }
        
        return m_data[head++];
    }

    bool empty()
    {
        return head >= tail;
    }

    void print()
    {
        for (int i = head; i < tail; ++i)
        {
            std::cout << m_data[i] << " ";
        }

        std::cout << std::endl;
    }

private:
    T* m_data;
    int head;
    int tail;
};

int main()
{
    auto q = SizedQueue<int>(10);
    q.push(1);
    q.push(2);
    q.push(3);
    q.print();

    q.pop();
    q.print();

    q.pop();
    q.print();

    q.pop();
    q.print();

    q.pop();
    q.print();
}