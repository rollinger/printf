/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prolling <prolling@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 12:32:16 by prolling          #+#    #+#             */
/*   Updated: 2021/10/06 11:08:17 by prolling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
* Outputs the string c to given file descriptor.
* BUG: does not check if fd is valid.
*/
void	ft_printstring(char *s, int fd)
{
	char	nulc;

	nulc = '\0';
	if (!s)
		return ;
	while (*s != '\0')
	{
		if (*s == '\xff')
			write(fd, &nulc, 1);
		else
			write(fd, s, 1);
		++s;
	}
	return ;
}
