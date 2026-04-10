#include <stddef.h>
#include "sort.h"

/**
 * sort_subtree - Recursively call itself to
 *   split array in "sorted" (left) and "unsorted" (right)
 *   relative to a "pivot value" until array given
 *   is size 1.
 * @array: part of the tree to sort
 * @start: beginning point of tree
 * @size:  size of the subsection of the full array
 * @total_size: size of the full array (for print_array)
 */
void sort_subtree(int *array, int start, int size, size_t total_size)
{
	int idx_pivot;
	int temp;
	int i;
	int j;
	int end;

	if (!array || size < 2)
		return;

	end = start + size - 1;
	idx_pivot = end;
	i = start - 1;

	for (j = start; j < end; j++)
	{
		if (array[j] <= array[idx_pivot])
		{
			i++;
			if (i != j)
			{
				temp = array[i];
				array[i] = array[j];
				array[j] = temp;
				print_array(array, total_size);
			}
		}
	}
	if (idx_pivot  != i + 1)
	{
		temp = array[idx_pivot];
		array[idx_pivot] = array[i + 1];
		array[i + 1] = temp;
		print_array(array, total_size);
	}
	idx_pivot = i + 1;

	sort_subtree(array, start, idx_pivot - start, total_size);
	sort_subtree(array, idx_pivot + 1, end - idx_pivot, total_size);
}

/**
 * quick_sort - Sorts an array by combining sub-partitioning
 *   and reordering recursively until each subpartition is size 1.
 * @array: array to sort
 * @size: array size (required to know the loop limit)
 */
void quick_sort(int *array, size_t size)
{
	sort_subtree(array, 0, (int)size, size);
}
