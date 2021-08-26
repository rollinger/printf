/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prolling <prolling@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 11:46:14 by prolling          #+#    #+#             */
/*   Updated: 2021/08/26 10:53:16 by prolling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
* return the first digit 1-9, atoi the number and return it.
*/
size_t	ft_get_field_width(const char *str)
{
	while (*str != '\0')
	{
		if (*str >= '1' && *str <= '9')
			return (ft_atoi(str));
		str++;
	}
	return (0);
}

/*
* fast forward to '.' and then atoi the number an return
*/
size_t	ft_get_precision(const char *str)
{
	while (*str != '\0')
	{
		if (*str == '.')
		{
			if (ft_isdigit(*(str + 1)))
				return (ft_atoi(++str));
			else
				return (0);
		}
		str++;
	}
	return (-1);
}

/*
* find first 0 before any other digit
*/
char	ft_get_zero_padding(const char *str)
{
	while (*str != '\0' && !ft_strchr("-123456789", *str))
	{
		if (*str == '0')
			return ('0');
		str++;
	}
	return (' ');
}
