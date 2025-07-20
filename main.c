/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 19:03:44 by romukena          #+#    #+#             */
/*   Updated: 2025/07/21 00:47:26 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_mylist	*a;
	t_mylist	*b;

	a = NULL;
	b = NULL;
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (1);
	else if (ac == 2)
		av = ft_split(av[1], ' ');
	stack_init(&a, av + 1, ac == 2);
	if (!sorted_list(a))
	{
		if (countlist(a) == 2)
			sa(&a, false);
		if (countlist(a) == 3)
			sort_three(&a);
		else
			push_swap(&a, &b);
	}
	free_list(&a);
}
