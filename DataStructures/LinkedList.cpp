#include <iostream>

template<class T>
class LinkedList {
private: 
    struct node {
        T data;
        node* next;
    };

    node* headNode;
    node* tailNode;
    uint32_t length;

public:
    LinkedList():
        headNode(nullptr),
        tailNode(nullptr),
        length(0)
    {
    }

    ~LinkedList()
    {
        node* target = headNode;
        while (nullptr != target)
        {
            node* tmp = target->next;
            delete target;
            target = tmp;
        }
    }

    uint32_t size()
    {
        return length;
    }

    void insert(const T data)
    {
        node* newNode = new node{data, nullptr};

        if (nullptr == headNode)
        { 
            tailNode = headNode = newNode;
        }
        else
        {
            tailNode->next = newNode;
            tailNode = newNode;
        }
        
        length++;
    }

    void insert(const T data, uint32_t index)
    {
        node* newNode = new node{data, nullptr};

        uint32_t currIdx = 0;
        node* prevNode = nullptr;
        for (node* target = headNode; target != nullptr; target = target->next)
        {
            if (currIdx == index)
            {
                newNode->next = target;
                if (nullptr == prevNode)
                {
                    newNode->next = target;
                    headNode = newNode;
                }
                else
                {
                    newNode->next = target;
                    prevNode->next = newNode;
                }

                length++;
                return;
            }
            prevNode = target;
            currIdx++;
        }

        prevNode->next = newNode;
        tailNode = newNode;
    }

    void print()
    {   
        for (node* target = headNode; target != nullptr; target = target->next)
        {
            std::cout << target->data;
            if (nullptr != target->next)
                std::cout << " ";
        }        
        std::cout << "\n";
    }
};


int main()
{
    auto intList = LinkedList<int>();
    intList.insert(1);
    intList.insert(2);
    intList.insert(3);
    intList.insert(4);
    intList.print();
    intList.insert(5, 3);
    intList.insert(5, 1000);
    intList.print();

    auto charList = LinkedList<char>();
    charList.insert('a');
    charList.insert('b');
    charList.insert('c');
    charList.insert('d');
    charList.print();
    charList.insert('e', 0);
    charList.print();
}