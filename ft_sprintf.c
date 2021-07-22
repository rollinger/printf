/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prolling <prolling@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 10:54:50 by prolling          #+#    #+#             */
/*   Updated: 2021/07/22 15:51:54 by prolling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
* Interpolates (convert and print) the variable given va_arg and fpos
* Returns the *t_format
*/
static char	*interpolate_var(int *fpos, const char *fstr, va_list args)
{
	t_format	*format;
	char		*str;

	format = build_format_struct(fpos, fstr, args);
	ft_convert_variable(format);
	str = format->str;
	free_format(format);
	return (str);
}

/*
* processes the character pos and stores beginning & end of the formatter in
* fpos[1&2].
* Sets the fpos[3] status flag: 0-default/none, 1-cpy normal, 2-interpolate,
* Returns fpos[3].
* //if FORMAT_FLAG then strchr until CONVERSIONS+FORMAT_FLAG and set c,s,e,f=2
* //else then strchr until FORMAT_FLAG and set c,s,e,f=1
* //if
*/
static size_t	process_pos(const char *fstr, int *fpos)
{
	const char	*pos;
	const char	*pend;

	pos = &fstr[fpos[0]];

	if (*pos == FORMAT_FLAG)
	{
		pend = ft_strset(pos + 1, CONVERSIONS);
		fpos[1] = fpos[0]; //start
		fpos[2] = (int)(pend - fstr); //end
		fpos[3] = 2; //flag
		fpos[0] = fpos[2];
	}
	else
	{
		pend = ft_strchr(pos, FORMAT_FLAG);
		fpos[1] = fpos[0]; //start
		if (pend)
			fpos[2] = (int)(pend - fstr - 1); //end
		else
			fpos[2] = (int)(ft_strend(fstr) - fstr - 1);
		fpos[3] = 1; //flag
		fpos[0] = fpos[2];
	}
	return (fpos[3]);
}

/*
* Write formatted fstr to *str interpolating the args.
* Worker Function for ft_sprintf and ft_printf
* Return bytes written or zero on error/empty.
*/
int ft_vprintf(char **str, const char *fstr, va_list args)
{
	int		fpos[4]; //cnt, start, end, status
	char	*temp;

	*str = ft_calloc(sizeof(char), 1);
	if (!*str || !*fstr || !args) //args to be removed (hack)
		return (-1);

	reset_fpos(fpos, 0);
	while (fstr[fpos[0]] != '\0')
	{
		process_pos(fstr, fpos);
		if (fpos[3] == 1)
		{
			temp = ft_substr((char const *)fstr, fpos[1], fpos[2] - fpos[1] + 1);
			*str = ft_strjoin((const char *)*str, temp);
			free(temp);
		}
		else if (fpos[3] == 2)
		{
			temp = interpolate_var(fpos, fstr, args);
			*str = ft_strjoin((const char *)*str, temp);
			free(temp);
		}
		fpos[0]++;
	}
	return (ft_strlen(*str));
}

/*
* Write formatted <fstr> to <str>. Return bytes written.
* str is defined outside and it is not freed for later reuse.
*/
int ft_sprintf(char **str, const char *fstr, ...)
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
	char 	**str;
	va_list	args;
	int		total;

	str = (char **)ft_calloc(sizeof(char *), 1);
	if (!str || !fstr)
		return (-1);
	va_start(args, fstr);
	total = ft_vprintf(str, fstr, args);
	va_end(args);
	ft_putstr(*str);
	free(str);
	return (total);
}
