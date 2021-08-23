/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prolling <prolling@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 16:44:50 by prolling          #+#    #+#             */
/*   Updated: 2021/08/23 15:25:36 by prolling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
* Converts the format->var_i into the correct representation at format->str
* Applies flag conversions: ...
* Returns nothing
*/
void	ft_convert_int(t_format *format)
{
	char *numberstring;

	if (format->precision == 0)
		format->str = ft_strdup("");
	else
	{
		format->is_neg = ft_is_neg(format->var_lli);
		if (format->conv == 'u')
			numberstring = ft_strfjoin(format->str, ft_uitoa((unsigned int)format->var_lli));
		else
			numberstring = ft_strfjoin(format->str, ft_uitoa(ft_abs(format->var_lli)));
		if (format->precision < 0)
			format->str = numberstring;
		else if (format->precision > 0)
		{
			format->str = ft_substr(numberstring, 0, format->precision);
			free(numberstring);
		}
	}
	return ;
}