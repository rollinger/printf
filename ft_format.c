/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prolling <prolling@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 11:46:14 by prolling          #+#    #+#             */
/*   Updated: 2021/07/22 15:58:48 by prolling         ###   ########.fr       */
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

	format = init_format();
	format = build_conv(format, fpos, fstr, args);
	format = build_flags(format, fpos, fstr, args);
	return (format);
}

t_format	*build_conv(t_format *f, int *fpos, const char *fstr, va_list args)
{
	f->conv = fstr[fpos[2]];
	if (f->conv == 's')
	{
		free(f->var_s);
		f->var_s = ft_strdup(va_arg(args, char *));
	}
	else if (f->conv == 'c')
		f->var_i = va_arg(args, int);
	else if (f->conv == '%')
	{
		free(f->var_s);
		f->var_s = ft_strdup("%");
	}
	else if (ft_strchr("di", f->conv))
		f->var_i = va_arg(args, int);
	else if (f->conv == 'u')
		f->var_ui = va_arg(args, unsigned int);
	else if (ft_strchr("xX", f->conv))
		f->var_ui = va_arg(args, unsigned int);
	else if (ft_strchr("p", f->conv))
		f->var_ulli = va_arg(args, unsigned long long int);
	return (f);
}

t_format	*build_flags(t_format *f, int *fpos, const char *fstr, va_list args)
{
	char		*flagstr;

	(void) args;
	flagstr = ft_substr(fstr, fpos[1], fpos[2] - fpos[1] + 1);
	f->field_width = ft_get_field_width(flagstr);
	if (ft_strchr(flagstr, ' '))
		f->flg_space = 1;
	if (ft_strchr(flagstr, '+'))
		f->flg_plus = 1;
	if (ft_strchr(flagstr, '#'))
		f->flg_alt_form = 1;
	if (ft_strchr(flagstr, '-'))
		f->flg_rpad = 1;
	if (ft_strchr(flagstr, '0'))
	{
		if (f->flg_rpad == 1)
			f->pad_char = ' ';
		else
			f->pad_char = '0';
	}
	free(flagstr);
	return (f);
}

/*
* Inits an empty t_format type with defaults and returns it.
*/
t_format	*init_format(void)
{
	t_format	*format;

	format = (t_format *)malloc(sizeof(t_format));
	format->str = (char *)ft_calloc(sizeof(char), 1);
	format->conv = 0;
	format->var_s = (char *)ft_calloc(sizeof(char), 1);
	format->var_i = 0;
	format->var_ulli = 0;
	format->is_neg = 0;
	format->field_width = 0;
	format->flg_space = 0;
	format->flg_alt_form = 0;
	format->flg_plus = 0;
	format->flg_lpad = 1;
	format->flg_rpad = 0;
	format->pad_char = ' ';
	return (format);
}

/*
* Frees the struct and all elements
*/
void	free_format(t_format *format)
{
	/**/
	if (format->str)
		free(format->str);
	if (format->var_s)
		free(format->var_s);
	if (format)
		free(format);
	return ;
}
