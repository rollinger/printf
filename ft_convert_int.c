/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prolling <prolling@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 16:44:50 by prolling          #+#    #+#             */
/*   Updated: 2021/08/26 10:09:40 by prolling         ###   ########.fr       */
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
	char	*nbrstr;

	if (format->precision == 0)
		format->str = ft_strdup("");
	else
	{
		format->is_neg = ft_is_neg(format->var_lli);
		if (format->conv == 'u')
			nbrstr = ft_strfjoin(format->str, \
				ft_uitoa((unsigned int)format->var_lli));
		else
			nbrstr = ft_strfjoin(format->str, \
				ft_uitoa(ft_abs(format->var_lli)));
		if (format->precision < 0)
			format->str = nbrstr;
		else if (format->precision > 0)
		{
			format->str = ft_substr(nbrstr, 0, format->precision);
			free(nbrstr);
		}
	}
	return ;
}
