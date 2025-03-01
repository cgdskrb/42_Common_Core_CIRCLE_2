/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cakaraba <cakaraba@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 18:55:51 by cakaraba          #+#    #+#             */
/*   Updated: 2024/10/27 02:32:37 by cakaraba         ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static	int	count_digit(int n)
{
	int	res;

	res = 0;
	if (n < 0)
	{
		n = n * -1;
		res++;
	}
	else if (n == 0)
	{
		return (res + 1);
	}
	while (n > 0)
	{
		n = n / 10;
		res++;
	}
	return (res);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		digit;
	char	*alloc;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	nb = n;
	digit = count_digit(nb);
	alloc = (char *)malloc(digit + 1);
	if (!alloc)
		return (NULL);
	alloc[digit--] = '\0';
	if (nb == 0)
		alloc[0] = '0';
	if (nb < 0)
	{
		alloc[0] = '-';
		nb = nb * -1;
	}
	while (nb > 0)
	{
		alloc[digit--] = (nb % 10) + '0';
		nb = nb / 10;
	}
	return (alloc);
}
