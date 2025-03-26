#ifndef MAIN_H
#define MAIN_H

// ==========================
// Q1: Linked_List Declaration
// ==========================

class Linked_List {
private:
    // Node struct represents an element in the linked list
    struct Node {
        int data;         // Holds the integer value
        Node* next;       // Pointer to the next node in the list

        // Constructor to initialize node with value and null next pointer
        Node(int val);
    };

    Node* head;           // Pointer to the first node in the list
    Node* tail;           // Pointer to the last node in the list
    size_t num_items;     // Tracks the number of elements in the list

public:
    // Constructor: initializes an empty linked list
    Linked_List();

    // Destructor: deletes all nodes to prevent memory leaks
    ~Linked_List();

    // Adds an element at the front of the list
    void push_front(int val);

    // Adds an element at the back of the list
    void push_back(int val);

    // Removes the front element of the list
    void pop_front();

    // Removes the last element of the list
    void pop_back();

    // Returns the value at the front of the list
    int front() const;

    // Returns the value at the back of the list
    int back() const;

    // Checks whether the list is empty
    bool empty() const;

    // Inserts a value at a specified index
    // If index is 0, inserts at front
    // If index >= size, inserts at the end
    void insert(size_t index, int item);

    // Removes the item at the specified index
    // Returns true if removal was successful, false otherwise
    bool remove(size_t index);

    // Returns the index of the first occurrence of a given value
    // Returns the size of the list if the item is not found
    size_t find(int item) const;

    // Prints all elements in the list
    void print_list() const;

    // Returns the number of elements in the list
    size_t size() const;
};

// ==========================
// Q2: mainStack Declaration (Vector-Based Stack)
// ==========================

#include <vector>  // for std::vector used in stack implementation

class mainStack {
private:
    std::vector<int> stack;  // Vector to store stack elements

public:
    // Pushes a value onto the top of the stack
    void push(int value);

    // Removes the top element from the stack
    void pop();

    // Checks if the stack is empty
    bool empty() const;

    // Returns the top element of the stack
    int top() const;

    // Calculates and returns the average of stack elements
    double average() const;

    // Displays the elements in the stack from bottom to top
    void display() const;
};

#endif
