# My Linked List Library

## Getting Started

To use this library, include the `mylinkedlist.h` header file in your C program and compile it along with `mylinkedlist.c`. Ensure you have a C compiler installed on your system.

## Description

This repository contains a basic implementation of a linked list data structure to store student information. It includes functions to create a new linked list, add and remove elements, retrieve elements by index, and perform operations such as finding the minimum, maximum, and average GPAs of students.

## Usage

To utilize this library, follow these steps:

1. Clone this repository to your local machine using Git.
2. Include the `mylinkedlist.h` header file in your C program.
3. Compile your program along with `mylinkedlist.c`.
4. Use the provided functions to manipulate linked lists of student data.

## Example

Below is a simple example demonstrating the usage of this library:

```c
#include <stdio.h>
#include "mylinkedlist.h"

int main() {
    linked_list_T *list = NewLinkedList();

    // Add some students to the list
    Enlist(list, NewStudentCell(1, 3.5, "Alice"));
    Enlist(list, NewStudentCell(2, 3.2, "Bob"));
    Enlist(list, NewStudentCell(3, 3.9, "Charlie"));

    // Print all students
    PrintAllStudents(list);

    // Remove a student and print
    student_cell_T *removed = Delist(list);
    printf("Removed Student: %s\n", removed->name);

    // Free memory
    FreeLinkedList(list);

    return 0;
}
