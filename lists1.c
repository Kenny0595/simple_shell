#include "shell.h"

/**
 * list_len - determines length of linked list
 * @h: pointer to 1st  node
 *
 * Return: size of list
 * this code is written by KENNY and MBULA 
 * wishing myself sucsess
 */
size_t list_len(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * list_to_strings - produces an array of strings from the list->str
 * @head: pointer to 1st  node
 *
 * Return: array of strings
 * this code is written by KENNY and MBULA 
 * wishing myself sucsess
 */
char **list_to_strings(list_t *head)
{
	list_t *node = head;
	size_t i = list_len(head), j;
	char **strs;
	char *str;

	if (!head || !i)
		return (NULL);
	strs = malloc(sizeof(char *) * (i + 1));
	if (!strs)
		return (NULL);
	for (i = 0; node; node = node->next, i++)
	{
		str = malloc(_strlen(node->str) + 1);
		if (!str)
		{
			for (j = 0; j < i; j++)
				free(strs[j]);
			free(strs);
			return (NULL);
		}

		str = _strcpy(str, node->str);
		strs[i] = str;
	}
	strs[i] = NULL;
	return (strs);
}


/**
 * print_list - All elements of a list_t linked list are printed.
 * @h: pointer to 1st  node
 *
 * Return: size of list
 * this code is written by KENNY and MBULA 
 * wishing myself sucsess
 */
size_t print_list(const list_t *h)
{
	size_t i = 0;

	while (h)
	{
		_puts(convert_number(h->num, 10, 0));
		_putchar(':');
		_putchar(' ');
		_puts(h->str ? h->str : "(nil)");
		_puts("\n");
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * node_starts_with - yields the node whose string begins with the prefix
 * @node: pointer to list head
 * @prefix: string to match
 * @c: the character following the prefix that matches
 *
 * Return: match node or null
 * this code is written by KENNY and MBULA 
 * wishing myself sucsess
 */
list_t *node_starts_with(list_t *node, char *prefix, char c)
{
	char *p = NULL;

	while (node)
	{
		p = starts_with(node->str, prefix);
		if (p && ((c == -1) || (*p == c)))
			return (node);
		node = node->next;
	}
	return (NULL);
}

/**
 * get_node_index - obtains a node's index
 * @head: pointer to list head
 * @node: pointer to the node
 *
 * Return: index of node or -1
 * this code is written by KENNY and MBULA 
 * wishing myself sucsess
 */
ssize_t get_node_index(list_t *head, list_t *node)
{
	size_t i = 0;

	while (head)
	{
		if (head == node)
			return (i);
		head = head->next;
		i++;
	}
	return (-1);
}
