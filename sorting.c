/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cakaraba <cakaraba@student.42kocaeli.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 00:30:53 by cakaraba          #+#    #+#             */
/*   Updated: 2025/02/17 00:30:54 by cakaraba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_args(t_stacks *s)
{
	if (s->a[2] != 2)
	{
		if (s->a[0] == 2)
			rotate(s->a, s->sizeof_a, "up", "a");
		else
			rotate(s->a, s->sizeof_a, "down", "a");
	}
	if (s->a[0] > s->a[1])
		swap("sa", s->a, s->sizeof_a);
}

void	four_or_five_args(t_stacks *s)
{
	while (s->sizeof_b <= 1)
	{
		if (s->a[0] == 0 || s->a[0] == 1)
			push("pb", s);
		else
			rotate(s->a, s->sizeof_a, "up", "a");
	}
	if (s->b[0] == 0)
		swap("sb", s->b, s->sizeof_b);
	if (s->a[2] != 4)
	{
		if (s->a[0] == 4)
			rotate(s->a, s->sizeof_a, "up", "a");
		else
			rotate(s->a, s->sizeof_a, "down", "a");
	}
	if (s->a[0] > s->a[1])
		swap("sa", s->a, s->sizeof_a);
	push("pa", s);
	push("pa", s);
}

static void	radix_b(t_stacks *s, int b_size, int bit_size, int j)
{
	while (b_size-- && j <= bit_size && !is_sorted(s))
	{
		if (((s->b[0] >> j) & 1) == 0)
			rotate(s->b, s->sizeof_b, "up", "b");
		else
			push("pa", s);
	}
	if (is_sorted(s))
	{
		while (s->sizeof_b != 0)
			push("pa", s);
	}
}

void	radix_sort(t_stacks *stacks)
{
	int	j;
	int	bit_size;
	int	size;

	bit_size = 0;
	size = stacks->sizeof_a;
	while (size > 1 && ++bit_size)
		size /= 2;
	j = -1;
	while (++j <= bit_size)
	{
		size = stacks->sizeof_a;
		while (size-- && !is_sorted(stacks))
		{
			if (((stacks->a[0] >> j) & 1) == 0)
				push("pb", stacks);
			else
				rotate(stacks->a, stacks->sizeof_a, "up", "a");
		}
		radix_b(stacks, stacks->sizeof_b, bit_size, j + 1);
	}
	while (stacks->sizeof_b != 0)
		push("pa", stacks);
}
