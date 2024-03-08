/*
 * File: mylinkedlist.c
 * David Rodriguez ... 
 *IMPLEMENT THE FUNCTIONS  here
 * ....
 */


#include "mylinkedlist.h"

// Create new student cell 
student_cell_T* NewStudentCell(int id, double gpa, char* name) {

  // Allocate memory for new cell
  student_cell_T* cell = malloc(sizeof(student_cell_T));

  // Initialize cell fields
  cell->id = id;
  cell->gpa = gpa;

  // Copy name string
  cell->name = strdup(name);

  // Set next pointer to null
  cell->next = NULL;

  // Return new cell
  return cell;
}

// Create new empty linked list
linked_list_T* NewLinkedList() {

  // Allocate memory for linked list
  linked_list_T* list = malloc(sizeof(linked_list_T));

  // Initialize head and tail to null
  list->head = NULL;
  list->tail = NULL;

  // Return new list
  return list;
}

// Free linked list memory 
void FreeLinkedList(linked_list_T* list) {

  // Start at head of list
  student_cell_T* current = list->head;

  // Traverse list freeing each cell
  while (current != NULL) {

    // Store next cell
    student_cell_T* temp = current->next;

    // Free current cell's name
    free(current->name);

    // Free current cell
    free(current);

    // Move to next cell
    current = temp;
  }

  // Free list 
  free(list);
}

// Add student cell to end of linked list
void Enlist(linked_list_T* list, student_cell_T* cell) {

  // If empty list, new cell is head and tail
  if (list->head == NULL) {
    list->head = cell;
    list->tail = cell;

  // Otherwise add to end  
  } else {
    list->tail->next = cell;
    list->tail = cell;
  }

  // Set next pointer of new cell to null
  cell->next = NULL;
}

// Remove student cell from head of list 
student_cell_T* Delist(linked_list_T* list) {

  // If empty list, return null
  if (list->head == NULL) {
    return NULL;
  }

  // Store head cell
  student_cell_T* cell = list->head;

  // Move head to next cell
  list->head = list->head->next;

  // If new head is null, tail is also null
  if (list->head == NULL) {
    list->tail = NULL;
  }

  // Return old head cell
  return cell;
}

// Check if linked list is empty
int LinkedListIsEmpty(linked_list_T* list) {
  return list->head == NULL;
}

// Get number of elements in linked list
int LinkedListLength(linked_list_T* list) {
  
  // Start at head
  student_cell_T* current = list->head;

  // Initialize count
  int count = 0;

  // Traverse list, incrementing count
  while(current != NULL) {
    count++;
    current = current->next;
  }

  // Return total count
  return count;
}

// Get student cell at specified index
student_cell_T* GetLinkedListElement(linked_list_T* list, int index) {

  // Check for invalid index
  if (index < 0 || index >= LinkedListLength(list)) {
    return NULL;
  }

  // Start at head
  student_cell_T* current = list->head;

  // Traverse to index
  for(int i = 0; i < index; i++) {
    current = current->next;
  }

  // Return cell at index
  return current;

}

// Print all students in linked list 
void PrintAllStudents(linked_list_T* list) {
  
  // Start at head
  student_cell_T* current = list->head;

  // Traverse and print each student
  while(current != NULL) {
    printf("%d %lf %s\n", current->id, current->gpa, current->name);
    current = current->next;
  }
}

// Find minimum GPA in list
double FindMinGPA(linked_list_T* list) {
  
  // Start with max value
  double min = INFINITY;

  // Check each student
  student_cell_T* current = list->head;
  while(current != NULL) {
    if(current->gpa < min) {
      min = current->gpa;
    }
    current = current->next;
  }

  // Return minimum
  return min;
}

// Find average GPA of students
double FindAverageGPA(linked_list_T* list) {

  // Initialize sum and count
  double sum = 0;
  int count = 0;

  // Add GPA of each student 
  student_cell_T* current = list->head;
  while(current != NULL) {
    sum += current->gpa;
    count++;
    current = current->next;
  }

  // Return average
  return sum / count;
}

// Find maximum GPA in list
double FindMaxGPA(linked_list_T* list) {

  // Start with minimum value 
  double max = -INFINITY;

  // Check each student
  student_cell_T* current = list->head;
  while(current != NULL) {
    if(current->gpa > max) {
      max = current->gpa;
    }
    current = current->next;
  }

  // Return maximum
  return max;
}

// Remove student with maximum GPA
student_cell_T* RemoveMaxGPA(linked_list_T* list) {

  // Store max cell and value
  student_cell_T* maxCell = list->head;
  double max = maxCell->gpa;

  // Previous cell
  student_cell_T* prev = NULL;

  // Check each student
  student_cell_T* current = list->head;
  while(current != NULL) {
  
    // Update max 
    if(current->gpa > max) {
      max = current->gpa;
      maxCell = current;
      prev = current;
    }
    
    current = current->next;
  }

  // Remove max cell from list
  if(prev != NULL) {
    prev->next = maxCell->next;
  } else {
    list->head = maxCell->next; 
  }

  if(maxCell == list->tail) {
    list->tail = prev;
  }

  // Return removed cell
  return maxCell;
}



/* OTHER FUNCTIONS YOU WOULD NEED....
 * EXPORT THEM HERE, BUT IMPLMENT THEM in mylinkedlist.c 
 */

  