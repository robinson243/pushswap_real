/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_command.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 20:32:49 by romukena          #+#    #+#             */
/*   Updated: 2025/07/21 01:11:16 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * Bottom to top
 */
static void	reverse_rotate(t_mylist **stack)
{
	t_mylist	*last;
	int			len;

	len = countlist(*stack);
	if (NULL == *stack || NULL == stack || 1 == len)
		return ;
	last = find_last_node(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	rra(t_mylist **a, bool checker)
{
	reverse_rotate(a);
	if (!checker)
		ft_putstr("rra\n");
}

void	rrb(t_mylist **b, bool checker)
{
	reverse_rotate(b);
	if (!checker)
		ft_putstr("rrb\n");
}

void	rrr(t_mylist **a, t_mylist **b, bool checker)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!checker)
		ft_putstr("rrr\n");
}
