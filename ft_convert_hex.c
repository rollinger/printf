/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_hex.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prolling <prolling@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 11:16:16 by prolling          #+#    #+#             */
/*   Updated: 2021/07/13 10:28:28 by prolling         ###   ########.fr       */
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
	format->str = ft_strfjoin(format->str, ft_uitox(format->var_ui));
	if (format->conv == 'X')
		format->str = ft_strupcase(format->str);
	return ;
}
