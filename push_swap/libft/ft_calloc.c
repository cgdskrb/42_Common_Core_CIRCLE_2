/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cakaraba <cakaraba@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 22:28:46 by cakaraba          #+#    #+#             */
/*   Updated: 2024/10/27 03:01:08 by cakaraba         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_calloc(size_t count, size_t size)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = malloc(count * size);
	if (!tmp)
	{
		return (NULL);
	}
	while (i < count * size)
	{
		tmp[i] = 0;
		i++;
	}
	return (tmp);
}
