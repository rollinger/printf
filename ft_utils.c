/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prolling <prolling@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 10:27:51 by prolling          #+#    #+#             */
/*   Updated: 2021/07/11 16:57:54 by prolling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
* Resets fpos to NULL at index 1 & 2
*/
void	reset_fpos(char **fpos)
{
	fpos[1] = NULL;
	fpos[2] = NULL;
	return ;
}

/*
* Prints a character and returns the length
*/
size_t	print_c(char c)
{
	ft_putchar(c);
	return (1);
}

/*
* Prints the string and return the length of the string.
*/
size_t	print_s(char *s)
{
	if (s)
	{
		ft_putstr(s);
		return (ft_strlen(s));
	}
	return (0);
}
