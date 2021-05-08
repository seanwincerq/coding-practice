#include <iostream>

template<class T>
class Stack
{
private:
    struct node {
        T data;
        node* next;
    };

    node* headNode;

public:
    Stack():
        headNode(nullptr)
    {

    }

    ~Stack()
    {
        node* targetNode = headNode;
        while (targetNode != nullptr)
        {
            node* tmp = targetNode->next;
            delete targetNode;
            targetNode = tmp;
        }
    }

    void push(const T data)
    {
        node* newNode = new node{data, headNode};
        headNode = newNode;
    }

    T pop()
    {
        if (nullptr == headNode)
        {
            std::cout << "Stack Empty ";
            return T();
        }

        T data = headNode->data;
        node* tmp = headNode->next;
        delete headNode;
        headNode = tmp;

        return data;
    }

    void print()
    {
        for (node* targetNode = headNode; targetNode != nullptr; targetNode = targetNode->next)
        {
            std::cout << targetNode->data;
            if (nullptr != targetNode->next)
                std::cout << " ";
        }
        std::cout << "\n";
    }
};

int main()
{
    auto intStack = Stack<int>();
    intStack.push(1);
    intStack.push(2);
    intStack.push(3);
    intStack.print();
    std::cout << "Popped " << intStack.pop() << std::endl;
    intStack.print();
    std::cout << "Popped " << intStack.pop() << std::endl;
    std::cout << "Popped " << intStack.pop() << std::endl;
    std::cout << "Popped " << intStack.pop() << std::endl;
    intStack.print();
}