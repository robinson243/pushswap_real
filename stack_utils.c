/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 09:49:59 by utente            #+#    #+#             */
/*   Updated: 2025/07/21 00:51:52 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_mylist	*find_last_node(t_mylist *head)
{
	if (NULL == head)
		return (NULL);
	while (head->next)
		head = head->next;
	return (head);
}

/*
 * Search for the last node and append
 * 🚨 Pay attention if the stack empty?
 */
void	append_node(t_mylist **stack, int nbr)
{
	t_mylist	*node;
	t_mylist	*last_node;

	if (NULL == stack)
		return ;
	node = malloc(sizeof(t_mylist));
	if (NULL == node)
		return ;
	node->next = NULL;
	node->value = nbr;
	if (NULL == *stack)
	{
		*stack = node;
		node->prev = NULL;
	}
	else
	{
		last_node = find_last_node(*stack);
		last_node->next = node;
		node->prev = last_node;
	}
}

/*
 * Find the smallest value node
 */
t_mylist	*find_smallest(t_mylist *stack)
{
	long		smallest;
	t_mylist	*smallest_node;

	if (NULL == stack)
		return (NULL);
	smallest = LONG_MAX;
	while (stack)
	{
		if (stack->value < smallest)
		{
			smallest = stack->value;
			smallest_node = stack;
		}
		stack = stack->next;
	}
	return (smallest_node);
}

/*
 * Return the cheapest node
 * that is already flagged
 */
t_mylist	*return_cheapest(t_mylist *stack)
{
	if (NULL == stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

int	countlist(t_mylist *head)
{
	t_mylist	*current;
	int			i;

	current = head;
	i = 0;
	while (current)
	{
		current = current->next;
		i++;
	}
	return (i);
}
