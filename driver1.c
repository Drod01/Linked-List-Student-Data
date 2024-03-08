/*
 * File: driver1.c
 * David Rodriguez 
 * ....
 */

#include <stdio.h>
#include "mylinkedlist.h" 

// Functions like ReadLine()

int main() {

  LinkedList* list = NewLinkedList();

  // Menu loop
  while(1) {
    // Print menu and get choice
    
    if(choice == 1) {
      // Get student info and add to list
      
    } else if(choice == 2) {
      // Remove and print first student
      
    } else if(choice == 3) {
      // Print number of students 
    
    } else if(choice == 4) {
      // Print student at index
      
    } else if(choice == 5) {
      PrintAllStudents(list);
      
    } else if(choice == 6) {
      // Print min, avg, max GPAs
      
    } else if(choice == 7) { 
      // Remove student with max GPA
      
    } else if(choice == 8) {
      // Free list
      break;
    }
  }
  
  return 0;
}