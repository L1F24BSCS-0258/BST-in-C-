#include <iostream>
using namespace std;

template <class T>
class CNode {
public:
    T data;
    CNode* next;
    CNode(T val) : data(val), next(nullptr) {}
};

template <class T>
class CircularLinkedList {
private:
    CNode<T>* tail;   // tail->next == head

public:
    // Constructor
    CircularLinkedList() {
        tail = nullptr; // initially empty list
    }

    // Insert at end
    void insertEnd(T val) {
        CNode<T>* newNode = new CNode<T>(val);

        // Case 1: Empty list
        if (tail == nullptr) {
            tail = newNode;
            tail->next = tail; // circular link to itself
        }
        else {
            // Case 2: Non-empty list
            newNode->next = tail->next; // new node points to head
            tail->next = newNode;       // old tail points to new node
            tail = newNode;             // update tail
        }
    }

    // Get head (first node)
    CNode<T>* getHead() {
        if (tail == nullptr)
            return nullptr;
        return tail->next; // head
    }

    // Calculate size of circular list
    int size() {
        if (tail == nullptr)
            return 0;

        int count = 0;
        CNode<T>* temp = tail->next; // start from head

        do {
            count++;
            temp = temp->next;
        } while (temp != tail->next);

        return count;
    }

    // Display one full circular traversal
    void display() {
        if (tail == nullptr) {
            cout << "List is empty\n";
            return;
        }

        CNode<T>* temp = tail->next; // head

        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != tail->next);
        temp = tail->next;
        cout<<"(Back to "<<temp->data<<")" << endl;
    }

    CNode<T>* getlast()
    {
        return tail;
    }
};

void reverselist(CircularLinkedList<int> list)
{
    CNode<int>* prev = list.getlast();
    CNode<int>* curr = list.getHead();
    CNode<int>* right = curr->next;

    while()
    {
        
    }
}

int main()
{
    CircularLinkedList<int> list;
    list.insertEnd(1);
    list.insertEnd(2);
    list.insertEnd(3);
    list.insertEnd(4);
    list.insertEnd(5);
    list.insertEnd(6);
    list.display();

    reverselist(list);
    return 0;
}
