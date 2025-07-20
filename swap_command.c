/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 20:37:36 by romukena          #+#    #+#             */
/*   Updated: 2025/07/21 00:52:09 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
 * ATTENTION
 * There may be only 2 nodes
*/
static void	swap(t_mylist **head)
{
	int	len;

	len = countlist(*head);
	if (NULL == *head || NULL == head || 1 == len)
		return ;
	*head = (*head)->next;
	(*head)->prev->prev = *head;
	(*head)->prev->next = (*head)->next;
	if ((*head)->next)
		(*head)->next->prev = (*head)->prev;
	(*head)->next = (*head)->prev;
	(*head)->prev = NULL;
}

void	sa(t_mylist	**a, bool checker)
{
	swap(a);
	if (!checker)
		ft_putstr("sa");
}

void	sb(t_mylist **b, bool checker)
{
	swap(b);
	if (!checker)
		ft_putstr("sb");
}

void	ss(t_mylist **a, t_mylist **b, bool checker)
{
	swap(a);
	swap(b);
	if (!checker)
		ft_putstr("ss");
}
