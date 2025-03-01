/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cakaraba <cakaraba@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 22:29:33 by cakaraba          #+#    #+#             */
/*   Updated: 2024/10/27 02:18:26 by cakaraba         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdlib.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	size_t	len;
	char	*allocation;

	i = 0;
	len = ft_strlen(s1);
	allocation = (char *)malloc(sizeof(char) * (len + 1));
	if (!allocation)
	{
		return (NULL);
	}
	while (s1[i])
	{
		allocation[i] = s1[i];
		i++;
	}
	allocation[i] = '\0';
	return (allocation);
}
