# Overview

This directory will be used to learn about sorting algorithms, how they work and what they are used for.

# Rules
- Allowed editors: vi, vim, emacs
- All your files will be compiled on Ubuntu 20.04 LTS using gcc, using the options -Wall -Werror -Wextra -pedantic -std=gnu89
- All your files should end with a new line
- A README.md file, at the root of the folder of the project is mandatory
- Your code should use the Betty style. It will be checked using betty-style.pl and betty-doc.pl
- You are not allowed to use global variables
- No more than 5 functions per file
- Unless specified otherwise, you are not allowed to use the standard library. Any use of functions like printf, puts… is totally forbidden.
- In the following examples, the main.c files are shown as examples. You can use them to test your functions, but you don't have to push them to your repo 
   (if you do we - won't take them into account). We will use our own main.c files at compilation. Our main.c files might be different from the one shown in the examples
- The prototypes of all your functions should be included in your header file called sort.h
- Don't forget to push your header fileAll your header files should be include guarded
- A list/array does not need to be sorted if its size is less than 2.
- Our files print_array.c and print_list.c (containing the print_array and print_list functions) will be compiled with your functions during the correction.
- Please declare the prototype of the provided functions print_array and print_list in your sort.h header file
- Please use the provided data structure for doubly linked list:

# Exercises

| Task name           | Filename                                | Prototype                                     |
|---------------------|-----------------------------------------|-----------------------------------------------|
| 00. Bubble sort     | 0-bubble_sort.c, 0-O (log file)         | void bubble_sort(int *array, size_t size);    |
| 01. Insertion sort  | 1-insertion_sort_list.c, 1-O (log file) | void insertion_sort_list(listint_t **list);   |
| 02. Selection sort  | 2-selection_sort.c, 2-O (log file)      | void selection_sort(int *array, size_t size); |
| 03. Quick sort      | 3-quick_sort.c, 3-O (log file)          | void quick_sort(int *array, size_t size);     |


## Compiling commands
00. `gcc -Wall -Wextra -Werror -pedantic 0-bubble_sort.c 0-main.c print_array.c -o SortAlgs_Exo-00-bubble.out`
01. `gcc -Wall -Wextra -Werror -pedantic 1-main.c 1-insertion_sort_list.c print_list.c -o SortAlgs_Exo-01-insertion.out`
02. `gcc -Wall -Wextra -Werror -pedantic 2-main.c 2-selection_sort.c print_array.c -o SortAlgs_Exo-02-select`
03. `gcc -Wall -Wextra -Werror -pedantic -std=gnu89 3-main.c 3-quick_sort.c print_array.c -o SortAlgs_Exo-03-quick`

# Resources

The following are provided to help implement the tasks.

## Structures

### listint_s 
```
/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;
```

## Functions
NOTE: these functions may be included into the repository as a helper to facilitate development.

### print_array
```
#include <stdlib.h>
#include <stdio.h>

/**
 * print_array - Prints an array of integers
 *
 * @array: The array to be printed
 * @size: Number of elements in @array
 */
void print_array(const int *array, size_t size)
{
    size_t i;

    i = 0;
    while (array && i < size)
    {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
}
```

### print_array
```
#include <stdio.h>
#include "sort.h"

/**
 * print_list - Prints a list of integers
 *
 * @list: The list to be printed
 */
void print_list(const listint_t *list)
{
    int i;

    i = 0;
    while (list)
    {
        if (i > 0)
            printf(", ");
        printf("%d", list->n);
        ++i;
        list = list->next;
    }
    printf("\n");
}
```
