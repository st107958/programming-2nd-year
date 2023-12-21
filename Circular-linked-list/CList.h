#include <iostream>
#include <assert.h>

template <typename T>
class CLList {

    struct Node {
    public:
        T data;
        Node* next;

        Node(T value = 0) : data(value), next(nullptr) {};
    };

public:
    Node* head;
    Node* tail;
    int size;

    CLList(T data)
    {
        this->head = new Node(data);
        this->tail = this->head;
        this->size = 1;
    }

    int GetSize()
    {
        return size;
    }

    T GetValue(Node* head)
    {
        if (head != nullptr) {
            
            return head->data;
        }

        throw std::runtime_error("Root node is nullptr");
    }

    Node* GetNode(int n, Node* head)
    {
        if (n == 0)  return head;
        else return GetNode(n - 1, head->next);

        return nullptr;
    }

    T GetNodeValue(int n, Node* head)
    {
        Node* tempnode = GetNode(n, head);

        T temp = tempnode->data;

        return temp;
    }

    void InsertTail(T data) 
    {
        Node* temp = new Node(data);
        
        if (this->size == 0) {
            this->head = temp;
            this->tail = temp;
            temp->next = this->head;
        }
        else {
            this->tail->next = temp;
            temp->next = this->head;
            this->tail = temp;
        }
        size++;
    }

    void InsertHead(T data)
    {
        Node* temp = new Node(data);

        if (this->size == 0) {
            this->head = temp;
            this->tail = temp;
            temp->next = this->head;
        }

        else {
            this->tail->next = temp;
            temp->next = this->head;
            this->head = temp;
        }

        this->size++;
    }

    T ExtractNode(int n = 0)
    {
        Node* nodeToRemove = GetNode(n, this->head);
        Node* prevNode = GetNode(n - 1, this->head);

        if (nodeToRemove == nullptr)
        {
            throw std::runtime_error("Invalid index");
        }

        T extractedData = nodeToRemove->data;

        if (nodeToRemove == this->head)
        {
            this->head = this->head->next;

            if (&(this->head->next) == &(this->head))
            {
                delete this->head;
                this->head = nullptr;
                this->size--;
                return extractedData;
            }
        }

        prevNode->next = nodeToRemove->next;

        delete nodeToRemove;

        this->size--;

        return extractedData;
    }

    void Display() const
    {

        if (this->size == 0) {
            std::cout << "List is empty" << std::endl;
            return;
        }

        Node* temp = this->head;

        do {
            std::cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != this->head);

        std::cout << std::endl;
    }
    
    ~CLList() 
    {
        if (this->size != 0) {
            Node* current = this->head;
            Node* nextNode = nullptr;

            do {
                nextNode = current->next;
                delete current;
                current = nextNode;
            } while (current != head);

            head = nullptr;
        }
    }
};

void test()
{
    CLList<int> list(5);

    assert(list.GetSize() == 1);
    assert(list.GetNodeValue(0, list.head) == 5);

    list.InsertTail(10);
    assert(list.GetSize() == 2);
    assert(list.GetNodeValue(1, list.head) == 10);

    list.InsertHead(3);
    assert(list.GetSize() == 3);
    assert(list.GetNodeValue(0, list.head) == 3);
    assert(list.GetNodeValue(1, list.head) == 5);
    assert(list.GetNodeValue(2, list.head) == 10);

    int extractedData = list.ExtractNode(1);
    assert(list.GetSize() == 2);
    assert(extractedData == 5);
    assert(list.GetNodeValue(0, list.head) == 3);
    assert(list.GetNodeValue(1, list.head) == 10);
}








