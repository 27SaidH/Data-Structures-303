#include <iostream>        // for input/output operations
#include <stdexcept>       // for throwing runtime errors
#include <numeric>         // for std::accumulate (used in stack average)
#include "main.h"          // includes class declarations from header
using namespace std;


// Q1: Singly Linked List 


// Node constructor: initializes a new node with given value and null next pointer
Linked_List::Node::Node(int val) : data(val), next(nullptr) {}

// Linked_List constructor: initializes an empty list with head and tail set to null
Linked_List::Linked_List() : head(nullptr), tail(nullptr), num_items(0) {}

// Destructor: deletes all nodes from memory to prevent memory leaks
Linked_List::~Linked_List() {
    Node* current = head;
    // Traverse the list and delete each node one by one
    while (current != nullptr) {
        Node* temp = current;
        current = current->next;  // move to next node
        delete temp;              // delete the current node
    }
}

// Adds a new node with the given value to the front of the list
void Linked_List::push_front(int val) {
    Node* new_node = new Node(val); // create new node
    new_node->next = head;          // new node points to current head
    head = new_node;                // head is updated to new node
    if (tail == nullptr)            // if list was empty, tail also becomes new node
        tail = new_node;
    num_items++;                    // increment number of items
}

// Adds a new node with the given value to the end of the list
void Linked_List::push_back(int val) {
    Node* new_node = new Node(val); // create new node
    if (tail != nullptr) {
        tail->next = new_node;      // existing tail points to new node
    } else {
        head = new_node;            // if list is empty, head is also the new node
    }
    tail = new_node;                // update tail to new node
    num_items++;
}

// Removes the front node from the list
void Linked_List::pop_front() {
    if (head == nullptr) return;    // do nothing if list is empty
    Node* temp = head;
    head = head->next;              // move head to the next node
    delete temp;                    // delete old head
    num_items--;
    if (head == nullptr)            // if list becomes empty, tail should also be null
        tail = nullptr;
}

// Removes the last node from the list
void Linked_List::pop_back() {
    if (head == nullptr) return;            // empty list, do nothing
    if (head == tail) {                     // only one node
        delete head;
        head = tail = nullptr;
    } else {
        Node* current = head;
        // traverse to the second last node
        while (current->next != tail) {
            current = current->next;
        }
        delete tail;                        // delete last node
        tail = current;                     // update tail to second last
        tail->next = nullptr;
    }
    num_items--;
}

// Returns the data of the front node
int Linked_List::front() const {
    if (head == nullptr)
        throw runtime_error("List is empty");
    return head->data;
}

// Returns the data of the last node
int Linked_List::back() const {
    if (tail == nullptr)
        throw runtime_error("List is empty");
    return tail->data;
}

// Checks if the list is empty
bool Linked_List::empty() const {
    return num_items == 0;
}

// Inserts a new node with the given value at a specific index
void Linked_List::insert(size_t index, int item) {
    if (index == 0) {
        push_front(item);   // insert at beginning
        return;
    }
    if (index >= num_items) {
        push_back(item);    // insert at end if index is beyond bounds
        return;
    }

    // insert in the middle
    Node* new_node = new Node(item);
    Node* current = head;
    for (size_t i = 0; i < index - 1; ++i) {
        current = current->next;  // move to node before the target index
    }
    new_node->next = current->next;  // new node points to next node
    current->next = new_node;        // previous node now points to new node
    num_items++;
}

// Removes a node at a specific index
bool Linked_List::remove(size_t index) {
    if (index >= num_items) return false; // invalid index
    if (index == 0) {
        pop_front();  // remove from front
        return true;
    }

    Node* current = head;
    for (size_t i = 0; i < index - 1; ++i) {
        current = current->next; // move to node before target
    }

    Node* temp = current->next;         // node to remove
    current->next = temp->next;         // skip over node to remove
    if (temp == tail) tail = current;   // update tail if needed
    delete temp;                        // delete node
    num_items--;
    return true;
}

// Searches for a value and returns the index of the first occurrence
// If not found, returns the size of the list
size_t Linked_List::find(int item) const {
    Node* current = head;
    size_t index = 0;
    while (current != nullptr) {
        if (current->data == item) return index;
        current = current->next;
        index++;
    }
    return num_items;  // item not found
}

// Prints all the values in the list from head to tail
void Linked_List::print_list() const {
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " -> ";
        current = current->next;
    }
    cout << "NULL" << endl;
}

// Returns the number of elements in the list
size_t Linked_List::size() const {
    return num_items;
}


// ==========================
// Q2: Stack Feature using vector
// ==========================

// Adds an element to the top of the stack
void mainStack::push(int value) {
    stack.push_back(value); // vector push_back is used to simulate stack push
}

// Removes the top element of the stack
void mainStack::pop() {
    if (!stack.empty()) {
        stack.pop_back();
    } else {
        cout << "Stack is empty. Cannot pop.\n";
    }
}

// Checks whether the stack is empty
bool mainStack::empty() const {
    return stack.empty();
}

// Returns the top element of the stack
int mainStack::top() const {
    if (!stack.empty()) {
        return stack.back();  // last element of vector
    } else {
        throw runtime_error("Stack is empty. No top element.");
    }
}

// Returns the average of all elements in the stack
double mainStack::average() const {
    if (stack.empty()) return 0.0;
    int sum = accumulate(stack.begin(), stack.end(), 0); // sum of all elements
    return static_cast<double>(sum) / stack.size();
}

// Displays all elements in the stack from bottom to top
void mainStack::display() const {
    cout << "Stack (bottom to top): ";
    for (size_t i = 0; i < stack.size(); ++i) {
        cout << stack[i];
        if (i < stack.size() - 1) {
            cout << " -> ";
        }
    }
    cout << " -> NULL" << endl;
}




// Main Program Execution

int main() {
    // -------------------------
    // Q1: Linked List operations
    // -------------------------
    Linked_List list;

    list.push_front(10); // Add 10 to the front of the list
    cout << "After push_front(10): ";
    list.print_list();

    list.push_back(20);  // Add 20 to the back
    list.push_back(30);  // Add 30 to the back
    cout << "After push_back(20) and push_back(30): ";
    list.print_list();

    // Retrieve and print first and last values
    cout << "Front: " << list.front() << endl;
    cout << "Back: " << list.back() << endl;

    // Check if list is empty
    cout << "Is list empty? " << (list.empty() ? "Yes" : "No") << endl;

    list.insert(1, 99); // Insert 99 at index 1
    cout << "After insert(1, 99): ";
    list.print_list();

    // Remove element at index 1
    bool removed = list.remove(1);
    cout << "Remove at index 1: " << (removed ? "True" : "False") << endl;
    list.print_list();

    // Find index of value 20
    size_t index = list.find(20);
    cout << "Index of 20: " << index << endl;

    // Remove from front and back
    list.pop_front();
    cout << "After pop_front(): ";
    list.print_list();

    list.pop_back();
    cout << "After pop_back(): ";
    list.print_list();

    // Q2: Stack operations
   
    cout << endl;
    cout << "Vector-Based Stack";
    cout << endl << endl;

    // 1) Create a stack object
    mainStack s;
    cout << "1) Stack object created.\n";

    // 2) Check if stack is empty
    cout << "2) Is stack empty? " << (s.empty() ? "Yes" : "No") << endl;

    // 3) Insert values into the stack
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "3) After pushing 10, 20, 30:\n";
    s.display();

    // 4) Remove (pop) the top value
    s.pop();
    cout << "4) After one pop:\n";
    s.display();

    // 5) Show the top of the stack
    cout << "5) Top of the stack: " << s.top() << endl;

    // 6) Calculate and show average of stack
    cout << "6) Average of stack elements: " << s.average() << endl;
}
