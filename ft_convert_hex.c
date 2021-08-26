/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prolling <prolling@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 11:16:16 by prolling          #+#    #+#             */
/*   Updated: 2021/08/26 16:25:32 by prolling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
* Converts the format->var_i into the correct representation at format->str
* Applies flag conversions: ...
* Returns nothing
*/
void	ft_convert_hex(t_format *format)
{
	if (format->precision == 0)
		format->str = ft_strdup("");
	else
	{
		//format->pad_char = '0';
		format->str = ft_strfjoin(format->str, ft_uitox(format->var_ulli));
		if (format->conv == 'X')
			format->str = ft_strupcase(format->str);
	}
	return ;
}
