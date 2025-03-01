/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cakaraba <cakaraba@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 15:08:25 by cakaraba          #+#    #+#             */
/*   Updated: 2024/10/25 15:09:58 by cakaraba         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	set_finder(char c, char *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(const char *s1, const char *set)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	s1_len;

	i = 0;
	j = 0;
	if (s1 == 0 || set == 0)
		return (NULL);
	s1_len = ft_strlen(s1);
	while (s1[j] && set_finder(s1[j], (char *)set))
		j++;
	while (s1_len > j && set_finder(s1[s1_len - 1], (char *)set))
		s1_len--;
	str = (char *)malloc(sizeof(char) * (s1_len - j + 1));
	if (!str)
		return (NULL);
	while (j < s1_len)
		str[i++] = s1[j++];
	str[i] = '\0';
	return (str);
}
