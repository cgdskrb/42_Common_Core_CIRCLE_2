/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cakaraba <cakaraba@student.42kocaeli.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 00:36:16 by cakaraba          #+#    #+#             */
/*   Updated: 2025/02/17 01:26:31 by cakaraba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <stdlib.h>
# include <unistd.h>

typedef struct s_stacks
{
	int		*a;
	int		*b;
	int		sizeof_a;
	int		sizeof_b;
	char	*sticked_args;
}	t_stacks;

void	error_case(t_stacks *s, char *msg);
void	init_stacks(int argc, char **argv, t_stacks *s);
void	sep_numbers(t_stacks *s);
void	check_if_sorted_or_has_double(t_stacks *s, int i);
void	create_index(t_stacks *s);
int		ft_atol(const char *n, t_stacks *s);
void	swap(char *str, int *array, int size);
void	push(char *str, t_stacks *s);
void	rotate(int *array, int size, char *direction, char *list);
void	three_args(t_stacks *s);
void	four_or_five_args(t_stacks *s);
void	radix_sort(t_stacks *s);
int		is_sorted(t_stacks *s);
int		word_counter(char *str, char sep);
char	**ft_split(char const *s, char c);

#endif
