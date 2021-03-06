/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_ptr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prolling <prolling@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/12 11:16:16 by prolling          #+#    #+#             */
/*   Updated: 2021/09/15 18:29:12 by prolling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
* Converts the format->var_i into the correct representation at format->str
* Applies flag conversions: ...
* Returns nothing
* format->str = ft_strdup("(nil)");
*/
void	ft_convert_ptr(t_format *format)
{
	if (format->var_ulli == 0)
		format->str = ft_strfjoin(format->str, ft_strdup("0x0"));
	else
		format->str = ft_strfjoin(ft_strdup("0x"), ft_uitox(format->var_ulli));
	return ;
}
