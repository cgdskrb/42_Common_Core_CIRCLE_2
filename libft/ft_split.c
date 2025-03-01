/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cakaraba <cakaraba@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 17:43:50 by cakaraba          #+#    #+#             */
/*   Updated: 2024/10/27 06:40:21 by cakaraba         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	free_malloc(char **str, int i)
{
	while (i-- > 0)
		free(str[i]);
}

static int	count_word(const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i] != '\0')
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		if (s[i] != c && s[i] != '\0')
			j++;
		while (s[i] != c && s[i] != '\0')
			i++;
	}
	return (j);
}

static int	word_len(const char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static int	place_char(char **str, char const *s, char c, int i)
{
	int	w_len;
	int	j;

	j = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			w_len = word_len(&s[i], c);
			str[j] = (char *)malloc(sizeof(char) * (w_len + 1));
			if (!str[j])
			{
				free_malloc(str, j);
				return (1);
			}
			w_len = 0;
			while (s[i] && s[i] != c)
				str[j][w_len++] = s[i++];
			str[j++][w_len] = '\0';
		}
		else
			i++;
	}
	str[j] = NULL;
	return (0);
}

char	**ft_split(char const *s, char c)
{
	char	**alloc;
	int		op;
	int		i;

	i = 0;
	if (!s)
		return (NULL);
	alloc = (char **)malloc(sizeof(char *) * (count_word(s, c) + 1));
	if (!alloc)
		return (NULL);
	op = place_char(alloc, s, c, i);
	if (op != 0)
	{
		free(alloc);
		return (NULL);
	}
	return (alloc);
}
