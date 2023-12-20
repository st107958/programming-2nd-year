#include <iostream>

template <typename T>
class Node {
public:
    T data;
    Node* next;

    Node(T value);
};

template<typename T>
inline Node<T>::Node(T value) : data(value), next(nullptr) {}

template <typename T>
class CLList {
private:
    Node<T>* head;

public:
    CLList() : head(nullptr) {}

    bool isEmpty() const;
    void append(T data);
    void display() const;
    Node<T>* getNodeAtIndex(int index);
    ~CLList();
};

template <typename T>
bool CLList<T>::isEmpty() const {
    return head == nullptr;
}

template <typename T>
void CLList<T>::append(T data) {
    Node<T>* newNode = new Node<T>(data);
    if (isEmpty()) {
        head = newNode;
        head->next = head;
    }
    else {
        Node<T>* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
}

template <typename T>
void CLList<T>::display() const {
    if (isEmpty()) {
        std::cout << "The list is empty." << std::endl;
        return;
    }

    Node<T>* temp = head;

    do {
        std::cout << temp->data << " -> ";
        temp = temp->next;
    } while (temp != head);

    std::cout << std::endl;
}

template <typename T>
CLList<T>::~CLList() {
    if (!isEmpty()) {
        Node<T>* current = head;
        Node<T>* nextNode = nullptr;

        do {
            nextNode = current->next;
            delete current;
            current = nextNode;
        } while (current != head);

        head = nullptr;
    }
}

template <typename T>
Node<T>* CLList<T>::getNodeAtIndex(int index) {
    if (isEmpty() || index < 0) {
        return nullptr;
    }

    int currentIndex = 0;
    Node<T>* current = head;

    do {
        if (currentIndex == index) {
            return current;
        }

        current = current->next;
        currentIndex++;
    } while (current != head);

    return nullptr;
}
