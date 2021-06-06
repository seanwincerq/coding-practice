template <typename T>
class SizedStack
{
public:
    SizedStack(const int size)
        : m_size(size),
          stack(new T[size]),
          tail(0)
    {
    }

    ~SizedStack()
    {
        delete stack;
    }

    void push(const T data)
    {
        if (tail >= m_size)
        {
            printf("Stack already full \n");
            return;
        }

        stack[tail++] = data;
    }

    T pop()
    {
        if (empty())
        {
            printf("Stack already empty \n");
            return T();
        }
        return stack[--tail];
    }

    bool empty()
    {
        return tail == 0;
    }

    void show()
    {
        for (int i = tail - 1; i >= 0; --i)
        {
            printf("%d ", stack[i]);
        }
        printf("\n");
    }

private:
    int m_size;
    T *stack;
    int tail;
};