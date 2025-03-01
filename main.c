/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cakaraba <cakaraba@student.42kocaeli.      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 00:30:42 by cakaraba          #+#    #+#             */
/*   Updated: 2025/02/17 00:35:47 by cakaraba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 0;
	if (argc < 2)
		error_case(NULL, "");
	while (++i < argc)
	{
		j = 0;
		if (!argv[i][0] || (argv[i][0] && argv[i][0] == ' '))
			error_case(NULL, "Error\n");
		while (argv[i][j] != '\0')
		{
			if ((!(ft_isdigit(argv[i][j])) && (argv[i][j] != ' ')
			&& (argv[i][j] != '-' && argv[i][j] != '+' && argv[i][j] != ' '))
			|| (argv[i][j] == '-' && argv[i][j + 1] == '\0')
			|| (argv[i][j] == '+' && argv[i][j + 1] == '\0')
			|| (argv[i][j] == '-' && argv[i][j + 1] == ' ')
			|| (argv[i][j] == '+' && argv[i][j + 1] == ' '))
				error_case(NULL, "Error\n");
			j++;
		}
	}
}

static void	join_args(int argc, char **argv, t_stacks *s)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	i = 0;
	tmp2 = ft_strdup("");
	while (++i < argc && argv[i] != NULL)
	{
		tmp = ft_strjoin(tmp2, argv[i]);
		if (tmp2)
			free(tmp2);
		if (i != argc - 1)
		{
			tmp2 = ft_strjoin(tmp, " ");
			if (tmp)
				free(tmp);
			tmp = tmp2;
		}
	}
	s->sticked_args = ft_strdup(tmp);
	if (s->sticked_args == NULL)
		error_case(s, "Error\n");
	if (tmp)
		free(tmp);
}

int	main(int argc, char **argv)
{
	t_stacks	*stacks;

	check_args(argc, argv);
	stacks = malloc(sizeof(*stacks));
	if (!stacks)
		exit(1);
	init_stacks(argc, argv, stacks);
	join_args(argc, argv, stacks);
	sep_numbers(stacks);
	check_if_sorted_or_has_double(stacks, 0);
	create_index(stacks);
	if (stacks->sizeof_a == 2)
		swap("sa", stacks->a, stacks->sizeof_a);
	else if (stacks->sizeof_a == 3)
		three_args(stacks);
	else if (stacks->sizeof_a >= 4 && stacks->sizeof_a <= 5)
		four_or_five_args(stacks);
	else
		radix_sort(stacks);
	check_if_sorted_or_has_double(stacks, 1);
	error_case(stacks, "Error\n");
	return (0);
}
