/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 20:39:30 by romukena          #+#    #+#             */
/*   Updated: 2025/07/20 20:42:26 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	sorted_list(t_mylist *stack)
{
	t_mylist	*current;
	t_mylist	*nextone;

	current = stack;
	nextone = stack;
	if (!stack)
		return (1);
	if (!stack->next)
		return (1);
	while (current)
	{
		nextone = current->next;
		if (nextone && current->value > nextone->value)
			return (false);
		current = current->next;
	}
	return (true);
}

void	sort_three(t_mylist **stack)
{
	if (!stack || !*stack || !(*stack)->next || !(*stack)->next->next)
		return ;
	if ((*stack)->value > (*stack)->next->value
		&& (*stack)->next->value < (*stack)->next->next->value
		&& (*stack)->value < (*stack)->next->next->value)
		swap(stack, "sa");
	else if ((*stack)->value > (*stack)->next->value
		&& (*stack)->next->value < (*stack)->next->next->value)
		rotate(stack, "ra");
	else if ((*stack)->value > (*stack)->next->value
		&& (*stack)->next->value > (*stack)->next->next->value)
	{
		rotate(stack, "ra");
		swap(stack, "sa");
	}
	else if ((*stack)->value < (*stack)->next->value
		&& (*stack)->next->value > (*stack)->next->next->value
		&& (*stack)->value < (*stack)->next->next->value)
	{
		reverse_rotate(stack, "rra");
		swap(stack, "sa");
	}
	else if ((*stack)->value < (*stack)->next->value
		&& (*stack)->next->value > (*stack)->next->next->value)
		reverse_rotate(stack, "rra");
}

void	handle_five(t_mylist **a, t_mylist **b)
{
	while (stack_len(*a) > 3)
	{
		init_nodes(*a, *b);
		finish_rotation(a, find_smallest(*a), 'a');
		pb(b, a, false);
	}
}