/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prolling <prolling@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 10:54:50 by prolling          #+#    #+#             */
/*   Updated: 2021/07/15 11:21:46 by prolling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
* Interpolates (convert and print) the variable given va_arg and fpos
* Returns the *t_format
*/
static char	*interpolate_var(char **fpos, va_list args)
{
	t_format	*format;
	char		*str;

	format = build_format_struct(fpos, args);
	ft_convert_variable(format);
	str = format->str;
	free_format(format);
	return (str);
}

/*
* processes the character pos and stores beginning & end of the formatter in
* fpos[1&2]. Returns 1 if a format-start was found, return 2 if a format-end
* was found, otherwise 0.
*/
static size_t	process_pos(const char *p, char **fpos)
{
	if (*p == FORMAT_FLAG)
	{
		fpos[1] = (char *)p;
		return (1);
	}
	else if (ft_strchr(CONVERSIONS, *p) || *p == FORMAT_FLAG)
	{
		fpos[2] = (char *)p;
		return (2);
	}
	return (0);
}

/*
* Write formatted fstr to *str. Return bytes written.
* Worker Function for ft_sprintf and ft_printf
*/
int ft_vprintf(char *str, const char *fstr, va_list args)
{
	char	*fpos[3];
	size_t	pp;

	reset_fpos(fpos, fstr);
	while (*fstr != '\0')
	{
		pp = process_pos(fstr, fpos);
		if (pp == 1)
		{
			//join str and normal
			str = ft_strjoin(str, ft_substr(fstr, fpos[0] - fstr, fpos[1] - fpos[0]));
			fpos[0] = fpos[1]; //shift fpos
		}
		else if (pp == 2)
		{
			//join str and interpolation
			str = ft_strjoin(str, interpolate_var(fpos, args));
			reset_fpos(fpos, fpos[2]); //resets fpos[0] with fpos[2]
		}
		fstr++;
	}
	return (0);
}

/*
* Write formatted <fstr> to <str>. Return bytes written.
* str is defined outside and it is not freed
*/
int ft_sprintf(char *str, const char *fstr, ...)
{
	va_list	args;
	int		total;

	if (!str || !fstr)
		return (-1);
	va_start(args, fstr);
	total = ft_vprintf(str, fstr, args);
	va_end(args);
	return (total);
}

/*
* Write formatted fstr to stdout. Return bytes written.
* Creates str itself for printing to stdout and frees it before returning.
*/
int	ft_printf(const char *fstr, ...)
{
	char 	*str;
	va_list	args;
	int		total;

	str = (char *)ft_calloc(sizeof(char), 1);
	if (!str || !fstr)
		return (-1);
	va_start(args, fstr);
	total = ft_vprintf(str, fstr, args);
	va_end(args);
	ft_putstr(str);
	free(str);
	return (total);
}
