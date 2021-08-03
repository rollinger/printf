/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prolling <prolling@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 16:44:50 by prolling          #+#    #+#             */
/*   Updated: 2021/07/11 17:20:31 by prolling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
* Converts the format->var_i into the correct representation at format->str
* Applies flag conversions: ... flg_break
* Returns nothing
*/
void	ft_convert_char(t_format *format)
{
	if (format->var_c == 0)
	{
		format->flg_break = 1;
		format->str = ft_strfjoin(format->str, ft_strdup(""));
	}
	else
		format->str = ft_strfjoin(format->str, ft_ctos(format->var_c));
	return ;
}
