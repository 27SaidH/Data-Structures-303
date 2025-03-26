# Data-Structures-303 Assignment #2

Overview
This project consists of two parts:

Part 1: Singly Linked List Implementation
A custom singly linked list (Single_Linked_List) was created with the following capabilities:

push_front – Adds a new element to the beginning of the list.

push_back – Adds a new element to the end of the list.

pop_front – Removes the first element from the list.

pop_back – Removes the last element from the list.

front / back – Retrieves the value at the front or back of the list.

empty – Checks whether the list is empty.

insert(index, item) – Inserts an element at the given index. If the index is beyond the current size, the item is added to the end.

remove(index) – Removes an element at the specified index. Returns a boolean for success/failure.

find(item) – Returns the index of the first occurrence of the item or the size of the list if not found.

This implementation maintains internal pointers to both the head and tail nodes, as well as a counter for num_items.

Part 2: Stack Using a Vector
A stack of integers was implemented using a C++ vector with full functionality:

Check if the stack is empty

Push – Add integers to the stack

Pop – Remove the top element

Top – Display the current top element

Average – Calculate the average of all elements in the stack



------------------------------------------------------------
How to Run the Code
Steps in Visual Studio
Open Visual Studio and create a new C++ project.

Add main.cpp and any relevant header files to the project.

Build the solution (Ctrl + Shift + B).

Run the program (Ctrl + F5).
