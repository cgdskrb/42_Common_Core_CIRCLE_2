/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cakaraba <cakaraba@student.42kocaeli.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 00:30:30 by cakaraba          #+#    #+#             */
/*   Updated: 2025/02/17 00:30:31 by cakaraba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(char *str, int *array, int size)
{
	int	tmp;

	if (size <= 1)
		return ;
	tmp = array[0];
	array[0] = array[1];
	array[1] = tmp;
	ft_putendl_fd(str, 1);
}

void	push(char *str, t_stacks *s)
{
	int	tmp;

	if (ft_strncmp(str, "pa", 3) == 0)
	{
		if (s->sizeof_b <= 0)
			return ;
		tmp = s->b[0];
		ft_memmove(s->a + 1, s->a, sizeof(int) * s->sizeof_a);
		s->a[0] = tmp;
		s->sizeof_b--;
		ft_memmove(s->b, s->b + 1, sizeof(int) * s->sizeof_b);
		s->sizeof_a++;
	}
	else if (ft_strncmp(str, "pb", 3) == 0)
	{
		if (s->sizeof_a <= 0)
			return ;
		tmp = s->a[0];
		ft_memmove(s->b + 1, s->b, sizeof(int) * s->sizeof_b);
		s->b[0] = tmp;
		s->sizeof_a--;
		ft_memmove(s->a, s->a + 1, sizeof(int) * s->sizeof_a);
		s->sizeof_b++;
	}
	ft_putendl_fd(str, 1);
}

void	rotate(int *array, int size, char *direction, char *list)
{
	int	tmp;

	if (size <= 0)
		return ;
	if (ft_strncmp(direction, "up", 3) == 0)
	{
		tmp = array[0];
		ft_memmove(array, array + 1, sizeof(int) * (size - 1));
		array[size - 1] = tmp;
		write(1, "r", 1);
	}
	else if (ft_strncmp(direction, "down", 5) == 0)
	{
		tmp = array[size - 1];
		ft_memmove(array + 1, array, sizeof(int) * (size - 1));
		array[0] = tmp;
		write(1, "rr", 2);
	}
	ft_putendl_fd(list, 1);
}
