/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 21:09:54 by romukena          #+#    #+#             */
/*   Updated: 2025/07/21 00:56:23 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

/* Structure de données */
typedef struct s_mylist
{
	int				value;
	int				final_index;
	int				push_price;
	int				current_position;
	bool			above_median;
	bool			cheapest;
	struct s_mylist	*target_node;
	struct s_mylist	*next;
	struct s_mylist	*prev;
}					t_mylist;

char				**ft_split(char *str, char separator);
void				stack_init(t_mylist **a, char **argv, bool flag_argc_2);
/*Error and free*/
void				free_tableau(char **tab);
void				free_list(t_mylist **lst);
int					error_repetition(t_mylist *a, int nbr);
int					error_syntax(char *str_nbr);
void				error_free(t_mylist **a, char **argv, bool flag_argc_2);

/*Stack creation */
void				stack_init(t_mylist **a, char **argv, bool flag_argc_2);
void				init_nodes(t_mylist *a, t_mylist *b);
void				set_current_position(t_mylist *stack);
void				set_price(t_mylist *a, t_mylist *b);
void				set_cheapest(t_mylist *b);

//*** linked list utils ***
void				append_node(t_mylist **stack, int nbr);
t_mylist			*find_last_node(t_mylist *head);
t_mylist			*find_smallest(t_mylist *stack);
t_mylist			*return_cheapest(t_mylist *stack);
bool				sorted_list(t_mylist *stack);
int					countlist(t_mylist *stack);
void				finish_rotation(t_mylist **s, t_mylist *n, char c);

//*** Algorithms ***
void				sort_three(t_mylist **a);
void				handle_five(t_mylist **a, t_mylist **b);
void				push_swap(t_mylist **a, t_mylist **b);
void				ft_putstr(char *s);

//*** Commands ***
void				sa(t_mylist **a, bool checker);
void				sb(t_mylist **b, bool checker);
void				ss(t_mylist **a, t_mylist **b, bool checker);
void				ra(t_mylist **a, bool checker);
void				rb(t_mylist **b, bool checker);
void				rr(t_mylist **a, t_mylist **b, bool checker);
void				rra(t_mylist **a, bool checker);
void				rrb(t_mylist **b, bool checker);
void				rrr(t_mylist **a, t_mylist **b, bool checker);
void				pa(t_mylist **a, t_mylist **b, bool checker);
void				pb(t_mylist **b, t_mylist **a, bool checker);

#endif