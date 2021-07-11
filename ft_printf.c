/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prolling <prolling@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 08:37:55 by prolling          #+#    #+#             */
/*   Updated: 2021/07/11 15:12:16 by prolling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
* Interpolates (Convert and print) the variable given va_arg and fpos
* Returns the length of the printed string
*/
static size_t	interpolate_var(char **fpos, va_list args)
{
	t_format	*format;
	size_t	len;

	format = build_format_struct(fpos, args);
	//convert_variable(t_format *format);

	/*char	*var_str;
	var_str = convert_variable(t_flags *flags);

	len = print_s(var_str);
	free(var_str);
	free(flags);
	return (len);
	*/
	print_c(format->conv);
	len = print_s(format->var_s);
	free_flags(format);
	return (len);
	//return (print_s(va_arg(args, char *)));
}

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
	else if (*p == '%')
	{
		*total += print_c(*p);
		reset_fpos(fpos);
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

	fpos[0] = (char *)str;
	reset_fpos(fpos);
	va_start(args, str);
	while (*str != '\0')
	{
		if (process_pos(str, fpos, &total) == 1)
		{
			total += interpolate_var(fpos, args);
			reset_fpos(fpos);
		}
		str++;
	}
	va_end(args);
	return (total);
}
