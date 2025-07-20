/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romukena <romukena@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/22 21:09:54 by romukena          #+#    #+#             */
/*   Updated: 2025/07/20 20:51:16 by romukena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>

/* Structure de données */
typedef struct s_mylist
{
	int				value;
	int				final_index;
	int				push_price;
	int				current_position;
	bool			above_median;
	bool			cheapest;
	struct s_mylist *target_node;
	struct s_mylist	*next;
	struct s_mylist	*prev;
}						t_mylist;

char			**ft_split(const char *str, char c);
void	stack_init(t_mylist **a, char **argv, bool flag_argc_2);
/*Error and free*/
void	free_tableau(char **tab);
void	free_list(t_mylist **lst);
int				error_repetition(t_mylist *a, int nbr);
int				error_syntax(char *str_nbr);

/*Stack creation */
void			stack_init(t_mylist **a, char **argv, bool flag_argc_2);
void			init_nodes(t_mylist *a, t_mylist *b);
void			set_current_position(t_mylist *stack);
void			set_price(t_mylist *a, t_mylist *b);
void			set_cheapest(t_mylist *b);

//*** linked list utils ***
void			append_node(t_mylist **stack, int nbr);
t_mylist	*find_last_node(t_mylist *head);
t_mylist	*find_smallest(t_mylist *stack);
t_mylist	*return_cheapest(t_mylist *stack);
bool	sorted_list(t_mylist *stack);
int				countlist(t_mylist *stack);
void			finish_rotation(t_mylist **s, t_mylist *n, char c);

#endif