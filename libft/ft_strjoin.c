/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cakaraba <cakaraba@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 22:40:44 by cakaraba          #+#    #+#             */
/*   Updated: 2024/10/27 02:17:41 by cakaraba         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*alloc;
	int		i;
	int		j;

	i = 0;
	j = 0;
	alloc = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!alloc)
		return (NULL);
	while (s1[i])
	{
		alloc[j] = s1[i];
		i++;
		j++;
	}
	i = 0;
	while (s2[i])
	{
		alloc[j] = s2[i];
		i++;
		j++;
	}
	alloc[j] = 0;
	return (alloc);
}
