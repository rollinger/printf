/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prolling <prolling@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 10:27:51 by prolling          #+#    #+#             */
/*   Updated: 2021/07/11 11:03:08 by prolling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	reset_fpos(char **fpos)
{
	fpos[1] = NULL;
	fpos[2] = NULL;
	return ;
}

size_t	print_c(char c)
{
	ft_putchar(c);
	return(1);
}

size_t	print_s(char *s)
{
	ft_putstr(s);
	return(ft_strlen(s));
}
