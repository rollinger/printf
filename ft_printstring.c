/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prolling <prolling@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/19 12:32:16 by prolling          #+#    #+#             */
/*   Updated: 2021/08/19 12:34:55 by prolling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
* Outputs the string c to given file descriptor.
* BUG: does not check if fd is valid.
*/
void	ft_printstring(char *s, int fd)
{
	if (!s)
		return ;
	while (*s != '\0' && *s != '\007')
	{
		write(fd, s, 1);
		++s;
	}
	return ;
}