#include <iostream>
using namespace std;



class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

class CList
{
    Node* last;

public:
    CList()
    {
        last = nullptr;
    }

    void insertAtlast(int value)
    {
        Node* temp = new Node(value);
        if (last == NULL)
        {
            last = temp;
            last->next = last;
        }
        else
        {
            temp->next = last->next;
            last->next = temp;
            last = temp;

        }
    }

    Node* getLast()
    {
        return last;
    }
};



int hotPotato(CList& list, int n, int k)
{
    //Implement your logic here

    int winner = -1; 
    Node* prev = list.getLast();  // prev store the last child

    if (prev->next == nullptr)   // Check if list is empty or not
    {
        return winner;
    }

    else {
         Node* curr = prev->next;   //current stores the first child
          int count = 1;            // counter for k times
          do {
             if (count == k)        // Check counter equals to k = 3 or not
             { 
                cout << "Eliminated: Child " << curr->data << endl;  // display eliminated child
                prev->next = curr->next;      // link prev node to next node
                delete curr;                   // delete eliminated node
                curr = prev->next;             // restoring node to next valid node
                count = 1;                    // reset counter
                n--;                  //decreasing n
            } 
            else { 
                //moving both node to the next valid node
                curr = curr->next;     
                prev = prev->next; 
                count++;     // increament count
            } 
        } while (n != 1);    // check until one node is remaining 
        winner = curr->data;     // stores the last remaining node

        return winner;
    }
}


int main() {

    CList list;
    list.insertAtlast(1);
    list.insertAtlast(2);
    list.insertAtlast(3);
    list.insertAtlast(4);
    list.insertAtlast(5);
    list.insertAtlast(6);

    int n = 6, k = 3;

    int winner = hotPotato(list, n, k);
    cout << "Winner: Child " << winner << endl;
    return 0;
}
