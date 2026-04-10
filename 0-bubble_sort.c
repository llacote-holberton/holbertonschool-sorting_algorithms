#include <stddef.h>
#include "sort.h"

/**
 * bubble_sort - Sort items by side-by-side comparison
 *   until finding right place.
 * @array: array to sort in ascending order
 * @size: array size used to know when to stop.
 *
 * Additional notes
 * - You're expected to print the array WHENEVER A SWAP OCCURS
 */
void bubble_sort(int *array, size_t size)
{
	/* Bubble basic: we make N loops in which */
	/* an array is traversed linearly, each time */
	/* comparing n and n+1 and switching them as needed */
	/* to have the lowest value "on the left". */
	/* The loop must break once we had one full pass on array */
	/*   without a single swap. */
	int swaps_done = 0; /* Loop breaker, will require do_while */
	size_t i; /* Inner loop iterator for items comparison */
	int swap_placeholder;

	if (!array || size == 0)
		return;
	do {
		/*Reinitializing the swaps_done INSIDE the loop. */
		swaps_done = 0;
		for (i = 0; i < size - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap_placeholder = array[i + 1];
				array[i + 1] = array[i];
				array[i] = swap_placeholder;
				swaps_done++;
				print_array(array, size);
			}
		}
	} while (swaps_done != 0);
}
