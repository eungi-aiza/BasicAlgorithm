#include <stdio.h>
#include <stdlib.h>

typedef struct element {
  int priority;
  int data;
} element;

typedef struct priority_queue {
  int capacity;
  int size;
  element *array;
} priority_queue;

// Create a new priority queue
priority_queue *create_pq(int capacity) {
  priority_queue *pq = malloc(sizeof(priority_queue));
  pq->capacity = capacity;
  pq->size = 0;
  pq->array = malloc(sizeof(element) * capacity);
  return pq;
}

// Free the memory of a priority queue
void free_pq(priority_queue *pq) {
  free(pq->array);
  free(pq);
}

// Swap two elements in an array
void swap(element *array, int i, int j) {
  element temp = array[i];
  array[i] = array[j];
  array[j] = temp;
}

// Move an element up the heap until it satisfies the heap property
void siftup(priority_queue *pq, int i) {
  while (i > 0 && pq->array[i].priority < pq->array[(i - 1) / 2].priority) {
    swap(pq->array, i, (i - 1) / 2);
    i = (i - 1) / 2;
  }
}

// Move an element down the heap until it satisfies the heap property
void siftdown(priority_queue *pq, int i) {
  while (2 * i + 1 < pq->size) {
    int max_child = 2 * i + 1;
    if (2 * i + 2 < pq->size && pq->array[2 * i + 2].priority < pq->array[max_child].priority) {
      max_child = 2 * i + 2;
    }
    if (pq->array[i].priority > pq->array[max_child].priority) {
      swap(pq->array, i, max_child);
      i = max_child;
    } else {
      break;
    }
  }
}

// Insert a new element into the priority queue
void insert_pq(priority_queue *pq, int data, int priority) {
  if (pq->size == pq->capacity) {
    // Resize the array if it is full
    pq->capacity *= 2;
    pq->array = realloc(pq->array, sizeof(element) * pq->capacity);
  }
  // Add the new element at the end of the array
  pq->array[pq->size].data = data;
  pq->array[pq->size].priority = priority;
  pq->size++;
  // Move it up to its proper position
  siftup(pq, pq->size - 1);
}

// Remove and return the element with the highest priority from the priority queue
element remove_pq(priority_queue *pq) {
  if (pq->size == 0) {
    // Return a dummy element if the queue is empty
    element dummy = {-1, -1};
    return dummy;
  }
  
   // Reduce the array size if it is too sparse
   if (pq->capacity > 16 && pq->size < pq->capacity / 4) {
     pq->capacity /= 2;
     pq->array = realloc(pq->array, sizeof(element) * pq->capacity);
   }

   // Save the element at the root
   element max = pq->array[0];
   // Replace it with the last element in the array
   pq->array[0] = pq->array[pq->size - 1];
   pq->size--;
   // Move it down to its proper position
   siftdown(pq, 0);
   // Return the saved element
   return max;
}

int main() {
  
   // Create a priority queue with initial capacity of 16
   priority_queue *pq = create_pq(16);

   // Insert some elements with different priorities
   insert_pq(pq, 'A', 3);
   insert_pq(pq, 'B', 1);
   insert_pq(pq, 'C', 2);

   // Remove and print the elements in order of priority
   printf("%c\n", remove_pq(pq).data); // B
   printf("%c\n", remove_pq(pq).data); // C
   printf("%c\n", remove_pq(pq).data); // A

   // Free the memory of the priority queue
   free_pq(pq);

   return 0;
}
