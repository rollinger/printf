/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prolling <prolling@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 08:37:55 by prolling          #+#    #+#             */
/*   Updated: 2021/07/11 11:10:59 by prolling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
* processes the character pos and stores beginning & end of the formatter in
* fpos[1&2]. Returns 1 if a formatter was found, otherwise 0.
*/
static size_t	process_pos(const char *p, char **fpos, int *total)
{
	if (fpos[1] == NULL)
	{
		if (*p == FORMAT_FLAG)
			fpos[1] = (char *)p;
		else
			*total += print_c(*p);
	}
	else if (ft_strchr(CONVERSIONS, *p))
	{
		fpos[2] = (char *)p;
		return (1);
	}
	return (0);
}

/*
* printf takes a string and variadic data, interpolates it and prints it out.
* <str>	format string containing %<flags><conv> formatter.
* ... elipsis for variadic arguments.
* VARIABLES:
* va_list	args; 	=> variadic argument list
* int		total;	=> total printed characters
* char	*fpos[3];	=> [str_start, format_start, format_end]
* char	*var_str;
* ALGORITHM:
*/
int	ft_printf(const char *str, ...)
{
	va_list		args;
	int			total;
	char		*fpos[3];
	//char		*var_str;

	fpos[0] = (char *)str;
	reset_fpos(fpos);
	va_start(args, str);
	while (*str != '\0')
	{
		if (process_pos(str, fpos, &total) == 1)
		{
			total += print_s("FORMAT");
			reset_fpos(fpos);
		}
		str++;
	}
	va_end(args);
	return (total);
}
