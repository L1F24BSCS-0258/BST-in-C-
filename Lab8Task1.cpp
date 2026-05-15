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


void tickHand(CNode<int>* &hand, int ticks)
{
    cout << "Ticking " << ticks << " steps:  ";

    // print starting position
    cout << hand->data;

    for (int i = 0; i < ticks; i++)
    {
        hand = hand->next; // move forward
        cout << " -> " << hand->data;
    }

    cout << endl;
}


int main()
{
    CircularLinkedList<int> clock;

    // Insert 1 to 12
    for (int i = 1; i <= 12; i++)
    {
        clock.insertEnd(i);
    }

    // Display clock
    cout << "Clock:  ";
    clock.display();

    // Start from head (1)
    CNode<int>* hand = clock.getHead();

    cout << "\nHand starts at: " << hand->data << endl;

    // First tick
    tickHand(hand, 5);
    cout << "Hand is now at:   " << hand->data << endl;

    // Second tick
    tickHand(hand, 9);
    cout << "Hand is now at:   " << hand->data << endl;

    // 🔹 User input
    int start, ticks;

    cout << "\nEnter starting hour (1-12): ";
    cin >> start;

    cout << "Enter number of ticks: ";
    cin >> ticks;

    // Move hand to starting position
    hand = clock.getHead();
    while (hand->data != start)
    {
        hand = hand->next;
    }

    tickHand(hand, ticks);
    cout << "Hand is now at:   " << hand->data << endl;

    return 0;
}
