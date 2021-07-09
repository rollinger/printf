/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prolling <prolling@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 11:17:28 by prolling          #+#    #+#             */
/*   Updated: 2021/05/26 09:26:04 by prolling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
* Allocates (with malloc(3)) and returns a string representing the integer
* received as an argument. Negative numbers must be handled.
* Returns: The string representing the integer. NULL if the allocation fails.
* -123 => ['-','1','2','3','\0']
*/
static size_t	ft_countd(int n)
{
	size_t	x;

	x = 0;
	if (n < 0)
	{
		n *= -1;
		++x;
	}
	while (n >= 10)
	{
		n /= 10;
		++x;
	}
	return (++x);
}

char	*ft_itoa(int n)
{
	char	*d;
	char	*r;
	size_t	dc;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	dc = ft_countd(n);
	d = ft_calloc(sizeof(char), (dc + 1));
	if (!d)
		return (NULL);
	r = d;
	if (n < 0)
	{
		*d = '-';
		n *= -1;
	}
	d += dc;
	while (n >= 10)
	{
		d--;
		*d = ((n % 10) + '0');
		n /= 10;
	}
	*(--d) = (n % 10) + '0';
	return (r);
}
