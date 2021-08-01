/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prolling <prolling@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 16:44:50 by prolling          #+#    #+#             */
/*   Updated: 2021/07/13 12:41:38 by prolling         ###   ########.fr       */
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
	format->is_neg = ft_is_neg(format->var_i);
	if (format->is_neg)
		format->str = ft_strfjoin(format->str, ft_itoa(format->var_i *= -1));
	else
		format->str = ft_strfjoin(format->str, ft_itoa(format->var_i));
	return ;
}

void	ft_convert_uint(t_format *format)
{
	format->str = ft_strfjoin(format->str, ft_uitoa(format->var_ui));
	return ;
}
