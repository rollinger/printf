/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prolling <prolling@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 11:46:10 by prolling          #+#    #+#             */
/*   Updated: 2021/08/23 14:50:09 by prolling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
* Converts the variable into the correct string representation at format->str
* more conversions csipduxX
*/
void	ft_convert_variable(t_format *format)
{
	if (format->conv == 's')
		ft_convert_str(format);
	else if (format->conv == 'c')
		ft_convert_char(format);
	else if (format->conv == '%')
		ft_convert_percent(format);
	else if (ft_strchr("di", format->conv))
		ft_convert_int(format);
	else if (format->conv == 'u')
		ft_convert_int(format);
	else if (ft_strchr("xX", format->conv))
		ft_convert_hex(format);
	else if (format->conv == 'p')
		ft_convert_ptr(format);
	return ;
}

/* field width flag */
void	ft_apply_format_field_width(t_format *format)
{
	if (format->field_width > 0)
	{
		if (format->flg_rpad == 1)
		{
			if (format->flg_plus == 1 || format->is_neg == 1)
				format->field_width--;
			format->str = ft_rpad(format->str, format->field_width, \
				format->pad_char);
		}
		else if (format->flg_lpad == 1)
		{
			if (format->flg_plus == 1 || format->is_neg == 1)
				format->field_width--;
			format->str = ft_lpad(format->str, format->field_width, \
			format->pad_char);
		}
	}
	return ;
}

/* flag alternative form  */
void	ft_apply_format_flg_alt_form(t_format *format)
{
	if (format->flg_alt_form == 1)
	{
		if (format->conv == 'x')
			format->str = ft_strfjoin(ft_strdup("0x"), format->str);
		else if (format->conv == 'X')
			format->str = ft_strfjoin(ft_strdup("0X"), format->str);
	}
	return ;
}

void	ft_apply_format_precision(t_format *format)
{
	if (ft_strchr("di", format->conv))
	{
		if (format->precision > 0)
			format->str = ft_lpad(format->str, format->precision, '0');	
	}
	return ;
}

void	ft_apply_format_sign_flags(t_format *format)
{
	if (ft_strchr("di", format->conv))
	{
		if (format->flg_space == 1 && format->is_neg == 0)
			format->str = ft_strfjoin(ft_strdup(" "), format->str);
		if (format->is_neg == 1)
			format->str = ft_strfjoin(ft_strdup("-"), format->str);
		if (format->flg_plus == 1 && format->is_neg == 0)
			format->str = ft_strfjoin(ft_strdup("+"), format->str);
	}
	return ;
}

/*
* Apply various flags to variable
*/
void	ft_apply_flags_to_variable(t_format *format)
{
	ft_apply_format_precision(format);
	ft_apply_format_flg_alt_form(format);
	ft_apply_format_field_width(format);
	ft_apply_format_sign_flags(format);
	return ;
}

