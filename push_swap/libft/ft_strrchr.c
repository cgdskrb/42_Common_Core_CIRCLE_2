/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cakaraba <cakaraba@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/20 20:55:31 by cakaraba          #+#    #+#             */
/*   Updated: 2024/10/20 22:14:55 by cakaraba         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	length;

	length = ft_strlen(s);
	while (length > 0)
	{
		if ((char)c == *(s + length))
			return ((char *)(s + length));
		length--;
	}
	if (*(s + length) == (char)c)
		return ((char *)(s + length));
	return (NULL);
}
