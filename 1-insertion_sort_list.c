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
	return (current);
}

/**
 * swap_item_with_previous - Swap double-linked item with previous
 *   and adjust all links.
 * @current: list item currently processed
 * Return: pointer to the same item (which has "moved left")
 */
listint_t *swap_item_with_previous(listint_t *current)
{
	listint_t *preceding;
	listint_t *following;

	if (!current || !current->prev)
		return (NULL);
	preceding = current->prev;
	preceding->next = current->next;
	if (current->next)
	{
		following = current->next;
		following->prev = preceding;
	}
	current->next = preceding;
	current->prev = preceding->prev;
	/* Don't forget the n-2, AND don't forget to PROTECT! */
	if (preceding->prev)
		preceding->prev->next = current;
	preceding->prev = current;

	/* @warning it's the same element we want to re-examine!!*/
	return (current);
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
	listint_t *cursor; /* Pointer to cross list one by one. */
	listint_t *item; /* Element to sort */

	if (list == NULL || *list == NULL)
		return;
	/* As long as we have a valid list element */
	cursor = *list;
	while (cursor)
	{
		/* @warning Set cursor to next element "while we know it" BEFORE     */
		/*   we start evaluations which may move current element's position. */
		item = cursor;
		cursor = item->next;
		/* We loop "moving element until no higher element to the left found "*/
		while (item->prev)
		{
			if (item->prev->n > item->n)
			{
				item = swap_item_with_previous(item);
				if (item->prev == NULL)
					*list = item;
				print_list(*list);
			}
			else
				break;
		}
	}
}
