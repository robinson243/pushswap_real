/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 20:39:30 by romukena          #+#    #+#             */
/*   Updated: 2025/07/21 00:57:52 by romukena         ###   ########.fr       */
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
		sa(stack, false);
	else if ((*stack)->value > (*stack)->next->value
		&& (*stack)->next->value < (*stack)->next->next->value)
		ra(stack, false);
	else if ((*stack)->value > (*stack)->next->value
		&& (*stack)->next->value > (*stack)->next->next->value)
	{
		ra(stack, false);
		sa(stack, false);
	}
	else if ((*stack)->value < (*stack)->next->value
		&& (*stack)->next->value > (*stack)->next->next->value
		&& (*stack)->value < (*stack)->next->next->value)
	{
		rra(stack, false);
		sa(stack, false);
	}
	else if ((*stack)->value < (*stack)->next->value
		&& (*stack)->next->value > (*stack)->next->next->value)
		rra(stack, false);
}

void	handle_five(t_mylist **a, t_mylist **b)
{
	while (countlist(*a) > 3)
	{
		init_nodes(*a, *b);
		finish_rotation(a, find_smallest(*a), 'a');
		pb(b, a, false);
	}
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (write(1, &s[i++], 1))
		{
		}
	}
}
