#include <stddef.h>
#include "sort.h"

/**
 * swap_item_with_next - Swap double-linked item with next
 *   and adjust all links.
 * @current: list item currently processed
 * Return: pointer to same item (which has "moved right")
 */
listint_t *swap_item_with_next(listint_t *current)
{
	listint_t *preceding;
	listint_t *following;

	/* @warning USELESS does NOT protect against NULL dereferencing */
	/*preceding = (current->prev) ? current->prev : NULL;*/
	/*following = (current->next) ? current->next : NULL;*/

	/* Better way: leaving early if we don't have the minimum to work. */
	if (!current || !current->next)
		return (NULL);
	/* Adjusts "backlinking" for the item pushed "behind current". */
	preceding = current->prev;
	following = current->next;

	if (preceding)
	{
		preceding->next = following;
		following->prev = preceding;
		/* Technically could be outside if because worst case */
		/*   it would just be NULL but I find it clearer like this. */
	}
	else
		following->prev = NULL;
	/* Adjusts "forwardlinking" for the n+2 item for which */
	/*   "current" becomes the previous one. */
	if (following->next)
	{
		following->next->prev = current;
		current->next = following->next;
	} /* Same note as above */
	else
		current->next = NULL;
	/* We can finally wrap up with "current's previous". */
	current->prev = following;
	following->next = current;

	/* @warning Following is the "new current". */
	return (following);
}

/**
 * insertion_sort_list - Sort items "Insertion algorithm""
 *   until finding right place.
 * @list: list to sort
 *
 * Additional notes
 * You are not allowed to modify the integer n of a node.
 *   You have to swap the nodes themselves.
 * You're expected to print the list after each time
 *   you swap two elements.
 */
void insertion_sort_list(listint_t **list)
{
	/* Insertion basic: we make N loops in which each item */
	/* is "pushed through list" until finding higher than it */
	/* (n switching place with n+1 "repeatedly" */
	/* BUT each time the switched one must also "fall down" until */
	/*  it found a "floor" (value of previous inferior to its own). */
	/* The loop must break once we had one full pass on array */
	/*   without a single swap. */
	listint_t *list_cursor;
	listint_t *current;
	listint_t *preceding;
	listint_t *following;
	/* list Pointeur vers la racine ? */

	if (list == NULL || *list == NULL)
		return;
	while (list->next)
	{
		if (list->n > list->next->n)
		{
			/* FIRST SWAP */
			current = list;
			following = current->next;
			if (current->prev != NULL)
			{
				preceding = current->prev;
				preceding->next = following;
				following->prev = preceding;
			}

			current->prev = following;
			if (following->next)
			{
				current->next = following->next->next;
				following->next->prev = current;
			}
			following->next = current;
		}
	}
}
