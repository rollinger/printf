/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prolling <prolling@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 10:27:51 by prolling          #+#    #+#             */
/*   Updated: 2021/07/14 19:57:32 by prolling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
* Resets fpos to NULL at index 1 & 2
*/
void	reset_fpos(char **fpos, char *zero)
{
	fpos[0] = zero;
	fpos[1] = NULL;
	fpos[2] = NULL;
	return ;
}

/*
* Sets fpos [0] to 1
*/
void	shift_fpos(char **fpos)
{
	fpos[0] = fpos[1];
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
