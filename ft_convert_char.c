/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_char.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prolling <prolling@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 16:44:50 by prolling          #+#    #+#             */
/*   Updated: 2021/08/10 17:25:06 by prolling         ###   ########.fr       */
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
		//format->flg_break = 1;
		//format->str = ft_strfjoin(format->str, ft_strdup("\024"));
		format->str = ft_strdup("\007");//ft_strfjoin(format->str, "\000");
	}
	else
		format->str = ft_strfjoin(format->str, ft_ctos(format->var_c));
	return ;
}
