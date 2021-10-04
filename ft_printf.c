/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prolling <prolling@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 10:54:50 by prolling          #+#    #+#             */
/*   Updated: 2021/10/03 15:33:26 by prolling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
* Interpolates (convert and print) the variable given va_arg and fpos
* Returns the *t_format
*/
static char	*interpolate_var(int *fpos, const char *fstr, va_list args)
{
	t_format	format;
	char		*str;

	init_format(&format);
	build_conv(&format, fpos, fstr, args);
	build_flags(&format, fpos, fstr);
	ft_convert_variable(&format);
	if (format.exe_flags == 1)
		ft_apply_flags_to_variable(&format);
	str = ft_strdup(format.str);
	if (format.flg_break != 0)
		fpos[3] = -1;
	fpos[4] = format.invisible_n;
	free_format(&format);
	return (str);
}

/*
* processes the character pos and stores beginning & end of the formatter in
* fpos[1&2].
* Sets the fpos[3] status flag: 0-default/none, 1-cpy normal, 2-interpolate,
* Returns fpos[3].
* //if FORMAT_FLAG then strchr until CONVERSIONS+FORMAT_FLAG and set c,s,e,f=2
* //else then strchr until FORMAT_FLAG and set c,s,e,f=1
* fpos[4] = counter, start, end, flag
*/
static size_t	process_pos(const char *fstr, int *fpos)
{
	const char	*pos;
	const char	*pend;

	pos = &fstr[fpos[0]];
	if (*pos == FORMAT_FLAG)
	{
		pend = ft_strset(pos + 1, CONVERSIONS);
		fpos[1] = fpos[0];
		fpos[2] = (int)(pend - fstr);
		fpos[3] = 2;
		fpos[0] = fpos[2];
	}
	else
	{
		pend = ft_strchr(pos, FORMAT_FLAG);
		fpos[1] = fpos[0];
		if (pend)
			fpos[2] = (int)(pend - fstr - 1);
		else
			fpos[2] = (int)(ft_strend(fstr) - fstr - 1);
		fpos[3] = 1;
		fpos[0] = fpos[2];
	}
	return (fpos[3]);
}

/*
* Write formatted fstr to *str interpolating the args.
* Worker Function for ft_sprintf and ft_printf
* Return bytes written or zero on error/empty.
* 
* fpos[5] = counter, start, end, flag, invisible character counter
* flag can be -1 exit, 1 normal append, 2 var interpolation
*/
char	*ft_vprintf(const char *fstr, va_list args, int *nbytes)
{
	int		fpos[5];
	char	*temp;
	char	*str;

	str = (char *)ft_calloc(sizeof(char), 1);
	if (!str || !*fstr)
		return (NULL);
	reset_fpos(fpos, 0);
	while (fstr[fpos[0]] != '\0' && fpos[3] != -1)
	{
		process_pos(fstr, fpos);
		if (fpos[3] == 1)
			temp = ft_substr((char const *)fstr, \
				fpos[1], fpos[2] - fpos[1] + 1);
		else if (fpos[3] == 2)
			temp = interpolate_var(fpos, fstr, args);
		*nbytes += ft_strlen(temp) + fpos[4];
		str = ft_strfjoin(str, temp);
		fpos[0]++;
	}
	return (str);
}

/*
* Write formatted <fstr> to <str>. Return bytes written.
* str is defined outside and it is not freed for later reuse.
*/
int	ft_sprintf(char *str, const char *fstr, ...)
{
	va_list	args;
	int		nbytes;

	if (!fstr || !str)
		return (-1);
	nbytes = 0;
	va_start(args, fstr);
	str = ft_vprintf(fstr, args, &nbytes);
	va_end(args);
	return (nbytes);
}

/*
* Write formatted fstr to stdout. Return bytes written.
* Creates str itself for printing to stdout and frees it before returning.
*/
int	ft_printf(const char *fstr, ...)
{
	char	*str;
	va_list	args;
	int		nbytes;

	if (!fstr)
		return (-1);
	nbytes = 0;
	va_start(args, fstr);
	str = ft_vprintf(fstr, args, &nbytes);
	va_end(args);
	ft_printstring(str, 1);
	free(str);
	return (nbytes);
}
