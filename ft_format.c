/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prolling <prolling@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 11:46:14 by prolling          #+#    #+#             */
/*   Updated: 2021/08/31 09:22:03 by prolling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
* Builds the structure of conversion, flags and variable and returns it. Used
* for later interpolation
*/
t_format	*build_format_struct(int *fpos, const char *fstr, va_list args)
{
	t_format	*format;

	format = (t_format *)malloc(sizeof(t_format));
	if (format)
	{
		format = init_format(format);
		format = build_conv(format, fpos, fstr, args);
		format = build_flags(format, fpos, fstr);
	}
	return (format);
}

/*
* ft_strfjoin(f->var_s, ft_strdup(va_arg(args, char *)));
* (char *)va_arg(args, char *);
*/
t_format	*build_conv(t_format *f, int *fpos, const char *fstr, va_list args)
{
	char	*str;

	f->conv = fstr[fpos[2]];
	if (f->conv == 's')
	{
		str = va_arg(args, char *);
		if (!str)
			str = "(null)";
		f->var_s = ft_strdup(str);
	}
	else if (f->conv == 'c')
		f->var_c = va_arg(args, int);
	else if (f->conv == '%')
		f->var_c = '%';
	else if (ft_strchr("diu", f->conv))
		f->var_lli = (long long int)va_arg(args, int);
	else if (ft_strchr("xX", f->conv))
		f->var_ulli = va_arg(args, unsigned int);
	else if (ft_strchr("p", f->conv))
		f->var_ulli = va_arg(args, unsigned long long int);
	return (f);
}

t_format	*build_flags(t_format *f, int *fpos, const char *fstr)
{
	char		*flagstr;

	flagstr = ft_substr(fstr, fpos[1] + 1, fpos[2] - fpos[1] - 1);
	f->field_width = ft_get_field_width(flagstr);
	f->precision = ft_get_precision(flagstr);
	f->pad_char = ft_get_zero_padding(flagstr);
	if (f->pad_char == '0')
		f->flg_zero_pad = 1;
	if (f->precision > 0)
	{
		f->flg_zero_pad = 0;
		f->pad_char = ' ';
	}
	if (ft_strchr(flagstr, ' '))
		f->flg_space = 1;
	if (ft_strchr(flagstr, '+'))
		f->flg_plus = 1;
	if (ft_strchr(flagstr, '#'))
		f->flg_alt_form = 1;
	if (ft_strchr(flagstr, '-'))
		f->flg_rpad = 1;
	free(flagstr);
	return (f);
}

/*
* Inits an empty t_format type with defaults and returns it.
* char* //(char *)ft_calloc(sizeof(char), 1);
*/
t_format	*init_format(t_format *format)
{
	format->str = NULL;
	format->conv = 0;
	format->var_s = NULL;
	format->var_c = 0;
	format->var_lli = 0;
	format->var_ulli = 0;
	format->is_neg = 0;
	format->field_width = 0;
	format->precision = -1;
	format->flg_break = 0;
	format->flg_space = 0;
	format->flg_alt_form = 0;
	format->flg_plus = 0;
	format->flg_lpad = 1;
	format->flg_rpad = 0;
	format->flg_zero_pad = 0;
	format->pad_char = ' ';
	format->exe_flags = 1;
	return (format);
}

/*
* Frees the malloc'ed char*
*/
void	free_format(t_format *format)
{
	if (format->str)
		free(format->str);
	if (format->var_s)
		free(format->var_s);
	return ;
}
