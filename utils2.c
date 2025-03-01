/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cakaraba <cakaraba@student.42kocaeli.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 00:31:05 by cakaraba          #+#    #+#             */
/*   Updated: 2025/02/17 00:31:06 by cakaraba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atol(const char *n, t_stacks *s)
{
	int			i;
	long		sign;
	long long	res;

	res = 0;
	sign = 1;
	i = 0;
	while (n[i] == ' ' || (n[i] >= '\t' && n[i] <= '\r'))
		i++;
	if (n[i] == '+' || n[i] == '-')
	{
		if (n[i] == '-')
			sign = -1;
		i++;
	}
	while (n[i])
	{
		if (res > 2147483647 || (res * sign) < -2147483648 || ft_strlen(n) > 11)
			error_case(s, "Error\n");
		if (!(n[i] >= '0' && n[i] <= '9'))
			error_case(s, "Error\n");
		res = res * 10 + (n[i] - '0');
		i++;
	}
	return ((int)(res * sign));
}

int	is_sorted(t_stacks *s)
{
	int	i;

	i = 0;
	while (i < s->sizeof_a - 1)
	{
		if (s->a[i] > s->a[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	check_if_sorted_or_has_double(t_stacks *s, int i)
{
	int	j;

	if (i == 0)
	{
		while (i < s->sizeof_a)
		{
			j = i + 1;
			while (j < s->sizeof_a)
			{
				if (s->a[i] == s->a[j])
					error_case(s, "Error\n");
				j++;
			}
			i++;
		}
	}
	if (is_sorted(s))
		error_case(s, NULL);
}

int	word_counter(char *str, char sep)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && str[i] == sep)
			i++;
		if (str[i])
		{
			count++;
			while (str[i] && str[i] != sep)
				i++;
		}
	}
	return (count);
}
