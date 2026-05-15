#include <iostream>
using namespace std;

// 🔹 Doubly Node
template <class T>
class DNode {
public:
    T data;
    DNode* next;
    DNode* prev;

    DNode(T val) : data(val), next(nullptr), prev(nullptr) {}
};

// 🔹 Doubly Linked List
template <class T>
class DoublyLinkedList {
private:
    DNode<T>* head;
    DNode<T>* tail;

public:
    DoublyLinkedList() {
        head = tail = nullptr;
    }

    // Insert at end
    void insertEnd(T val) {
        DNode<T>* newNode = new DNode<T>(val);

        if (head == nullptr) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    // Get head
    DNode<T>* getHead() {
        return head;
    }

    // Display forward
    void display() {
        DNode<T>* temp = head;

        while (temp != nullptr) {
            cout << temp->data;
            if (temp->next != nullptr)
                cout << " <-> ";
            temp = temp->next;
        }
        cout << endl;
    }
};


// 🔥 Move to next image
void nextImage(DNode<string>* &cur)
{
    if (cur->next != nullptr) {
        cur = cur->next;
        cout << "Viewing: " << cur->data << endl;
    }
    else {
        cout << "Already at the last image." << endl;
    }
}


// 🔥 Move to previous image
void prevImage(DNode<string>* &cur)
{
    if (cur->prev != nullptr) {
        cur = cur->prev;
        cout << "Viewing: " << cur->data << endl;
    }
    else {
        cout << "Already at the first image." << endl;
    }
}


int main()
{
    DoublyLinkedList<string> gallery;

    gallery.insertEnd("Sunset.jpg");
    gallery.insertEnd("Mountain.jpg");
    gallery.insertEnd("Beach.jpg");
    gallery.insertEnd("Forest.jpg");
    gallery.insertEnd("City.jpg");

    cout << "Gallery: ";
    gallery.display();

    DNode<string>* current = gallery.getHead();

    cout << "\nViewing: " << current->data << "   [start]\n\n";

    cout << "next -> "; nextImage(current);
    cout << "next -> "; nextImage(current);
    cout << "next -> "; nextImage(current);
    cout << "next -> "; nextImage(current);
    cout << "next -> "; nextImage(current); 

    cout << endl;

    cout << "prev -> "; prevImage(current);
    cout << "prev -> "; prevImage(current);
    cout << "prev -> "; prevImage(current);
    cout << "prev -> "; prevImage(current);
    cout << "prev -> "; prevImage(current); 

    return 0;
}