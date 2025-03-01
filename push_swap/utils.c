/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cakaraba <cakaraba@student.42kocaeli.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 00:31:12 by cakaraba          #+#    #+#             */
/*   Updated: 2025/02/17 00:31:13 by cakaraba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_case(t_stacks *s, char *msg)
{
	if (msg)
		write(2, msg, ft_strlen(msg));
	if (s)
	{
		if (s->a)
			free(s->a);
		if (s->b)
			free(s->b);
		if (s->sticked_args)
			free(s->sticked_args);
		free(s);
	}
	exit(1);
}

void	init_stacks(int argc, char **argv, t_stacks *s)
{
	int	i;

	i = 0;
	s->sizeof_a = 0;
	s->sizeof_b = 0;
	while (--argc)
	{
		if (word_counter(argv[i + 1], ' '))
			s->sizeof_a += word_counter(argv[i + 1], ' ');
		else
			s->sizeof_a++;
		i++;
	}
	s->a = malloc(s->sizeof_a * sizeof(int));
	if (!s->a)
		error_case(s, "Error\n");
	s->b = malloc(s->sizeof_a * sizeof(int));
	if (!s->b)
		error_case(s, "Error\n");
}

void	sep_numbers(t_stacks *s)
{
	char	**tmp;
	int		i;
	int		z;

	z = 0;
	tmp = ft_split(s->sticked_args, ' ');
	i = 0;
	while (tmp[i] != NULL && tmp[i][0] != '\0')
	{
		s->a[z++] = ft_atol(tmp[i], s);
		free(tmp[i]);
		i++;
	}
	free(tmp);
}

void	create_index(t_stacks *s)
{
	int	i;
	int	j;
	int	k;
	int	*new_a;

	new_a = malloc(s->sizeof_a * sizeof(int));
	if (!new_a)
		error_case(s, "Error\n");
	i = 0;
	while (i < s->sizeof_a)
	{
		k = 0;
		j = -1;
		while (++j < s->sizeof_a)
		{
			if (s->a[i] > s->a[j])
				k++;
		}
		new_a[i] = k;
		i++;
	}
	i = s->sizeof_a;
	while (i--)
		s->a[i] = new_a[i];
	free(new_a);
}
