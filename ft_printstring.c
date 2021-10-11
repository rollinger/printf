/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prolling <prolling@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 12:32:16 by prolling          #+#    #+#             */
/*   Updated: 2021/10/11 21:03:10 by prolling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
* Outputs the string c to given file descriptor.
* BUG: does not check if fd is valid.
*/
int	ft_printstring(char *s, int fd)
{
	int		nbytes;
	int		nullterm;

	nbytes = 0;
	nullterm = 0;
	if (!s)
		return (0);
	while (*s != '\0')
	{
		if (*s == '\x6c' && *(s + 1) == '\x6f' && *(s + 2) == '\x6c')
		{
			write(fd, "\0", 1);
			nullterm = 1;
			s += 2;
		}
		else if (nullterm == 0)
			write(fd, s, 1);
		++s;
		++nbytes;
	}
	return (nbytes);
}
