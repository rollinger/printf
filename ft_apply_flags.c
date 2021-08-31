/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_apply_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prolling <prolling@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 11:46:14 by prolling          #+#    #+#             */
/*   Updated: 2021/08/31 09:23:05 by prolling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

/* apply precision to it */
void	ft_apply_format_precision(t_format *format)
{
	if (ft_strchr("di", format->conv))
	{
		if (format->precision > 0)
		{
			format->str = ft_lpad(format->str, format->precision, '0');
			if (format->field_width >= format->precision \
				&& format->precision <= (short int)ft_ndigits(format->var_lli))
			{
				format->pad_char = ' ';
			}
		}
	}
	return ;
}

void	ft_apply_format_sign_flags(t_format *f)
{
	if (ft_strchr("diu", f->conv))
	{
		if (f->flg_space == 1 && f->is_neg == 0 && f->flg_plus == 0)
			f->str = ft_strfjoin(ft_strdup(" "), f->str);
		if (f->is_neg == 1 && f->conv != 'u')
		{
			f->str = ft_strfjoin(ft_strdup("-"), f->str);
			f->field_width += 1;
		}
		if (f->flg_plus == 1 && f->is_neg == 0)
		{
			f->str = ft_strfjoin(ft_strdup("+"), f->str);
			f->field_width += 1;
		}
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
	if (format->flg_zero_pad == 1)
	{
		ft_apply_format_field_width(format);
		ft_apply_format_sign_flags(format);
	}
	else
	{
		ft_apply_format_sign_flags(format);
		ft_apply_format_field_width(format);
	}
	return ;
}
