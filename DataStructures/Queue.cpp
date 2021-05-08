#include <iostream>

template<class T>
class Queue
{
private:
    struct node {
        T data;
        node* next;
    };

    node* headNode;
    node* tailNode;

public:
    Queue():
        headNode(nullptr),
        tailNode(nullptr)
    {

    }

    ~Queue()
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
        node* newNode = new node{data, nullptr};

        if (nullptr == headNode)
        {
            tailNode = headNode = newNode;
            return;
        }

        tailNode->next = newNode;
        tailNode = newNode;
    }

    T pop()
    {
        if (nullptr == headNode)
        {
            std::cout << "Empty Queue ";
            return T();
        }

        const T data = headNode->data;
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
    auto intQueue = Queue<int>();
    intQueue.push(1);
    intQueue.push(2);
    intQueue.push(3);
    intQueue.print();
    std::cout << "Popped: " << intQueue.pop() << std::endl;
    intQueue.print();
    std::cout << "Popped: " << intQueue.pop() << std::endl;
    std::cout << "Popped: " << intQueue.pop() << std::endl;
    std::cout << "Popped: " << intQueue.pop() << std::endl;
    intQueue.print();
}