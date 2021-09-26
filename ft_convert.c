/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prolling <prolling@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 11:46:10 by prolling          #+#    #+#             */
/*   Updated: 2021/08/28 11:43:18 by prolling         ###   ########.fr       */
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
		ft_convert_uint(format);
	else if (ft_strchr("xX", format->conv))
		ft_convert_hex(format);
	else if (format->conv == 'p')
		ft_convert_ptr(format);
	return ;
}
