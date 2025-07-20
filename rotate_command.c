/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_command.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 20:33:52 by romukena          #+#    #+#             */
/*   Updated: 2025/07/21 01:11:45 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Top node to bottom position
 */
static void	rotate(t_mylist **stack)
{
	t_mylist	*last_node;
	int			len;

	len = countlist(*stack);
	if (NULL == stack || NULL == *stack || 1 == len)
		return ;
	last_node = find_last_node(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_mylist **a, bool checker)
{
	rotate(a);
	if (!checker)
		ft_putstr("ra\n");
}

void	rb(t_mylist **b, bool checker)
{
	rotate(b);
	if (!checker)
		ft_putstr("rb\n");
}

void	rr(t_mylist **a, t_mylist **b, bool checker)
{
	rotate(a);
	rotate(b);
	if (!checker)
		ft_putstr("rr\n");
}
