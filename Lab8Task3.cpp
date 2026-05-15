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
};

void SplitTwoList(CircularLinkedList<int> list, int size)
{
    CNode<int>* temp = list.getHead();
    CircularLinkedList<int> list1;
    CircularLinkedList<int> list2;

    for (int i = 0; i < size; i++)
    {
        if(i<3)
        {
            list1.insertEnd(temp->data);
            temp = temp->next;
        }
        else if(i>=3)
        {
            list2.insertEnd(temp->data);
            temp = temp->next;
        }
    }

    list1.display();
    list2.display();
    
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

    SplitTwoList(list, list.size());
    return 0;
}
