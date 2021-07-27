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
	t_format 	*format;
	char		*flagstr;

	format = init_format();
	format->conv = fstr[fpos[2]];
	if (format->conv == 's')
		format->var_s = va_arg(args, char *);
	else if (format->conv == 'c')
		format->var_i = va_arg(args, int);
	else if (format->conv == '%')
		format->var_s = "%";
	else if (ft_strchr("di", format->conv))
		format->var_i = va_arg(args, int);
	else if (format->conv == 'u')
		format->var_ui = va_arg(args, unsigned int);
	else if (ft_strchr("xX", format->conv))
		format->var_ui = va_arg(args, unsigned int);
	else if (ft_strchr("p", format->conv))
		format->var_ulli = va_arg(args, unsigned long long int);
	
	/* Get flags " +" */
	flagstr = ft_substr(fstr, fpos[1] + 1, fpos[2] - fpos[1] - 1);
	format->field_width = ft_get_field_width(flagstr);
	if (ft_strchr(flagstr, ' '))
		format->flg_space = 1;
	if (ft_strchr(flagstr, '+'))
		format->flg_plus = 1;
	if (ft_strchr(flagstr, '#'))
		format->flg_alt_form = 1;
	if (ft_strchr(flagstr, '-'))
		format->flg_rpad = 1;
	if (ft_strchr(flagstr, '0'))
	{
		if (format->flg_rpad == 1)
			format->pad_char = ' ';
		else
			format->pad_char = '0';
	}
	free(flagstr);
	return (format);
}

/*
* Inits an empty t_format type with defaults and returns it.
*/
t_format	*init_format()
{
	t_format *format;

	format = (t_format *)malloc(sizeof(t_format));
	format->str = NULL;
	format->conv = 0;
	format->var_s = NULL;
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
* ??? Does not need to free attached elements ???
*/
void	free_format(t_format *format)
{
	/*if (format->str != NULL)
		free(format->str);
	if (format->var_s != NULL)
		free(format->var_s);*/
	free(format);
	return ;
}
