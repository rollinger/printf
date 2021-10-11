/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prolling <prolling@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 16:44:50 by prolling          #+#    #+#             */
/*   Updated: 2021/10/11 20:23:20 by prolling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
* Converts the format->var_i into the correct representation at format->str
* Applies flag conversions: ... flg_break
* Returns nothing
* format->str = ft_strfjoin(format->str, ft_strdup("\007"));
//format->flg_break = 1;
//format->nullterm = 1;
//format->invisible_n = 0;
*/
void	ft_convert_char(t_format *format)
{
	if (format->var_c == 0)
	{
		format->str = ft_strfjoin(format->str, ft_strdup("\x6c\x6f\x6c"));
		format->magic_char = 2;
	}
	else
		format->str = ft_strfjoin(format->str, ft_ctos(format->var_c));
	return ;
}
