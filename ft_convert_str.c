/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prolling <prolling@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 16:44:50 by prolling          #+#    #+#             */
/*   Updated: 2021/08/27 11:22:27 by prolling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
* Converts the format->var_s into the correct representation at format->str
* Applies flag conversions: ...
* Returns nothing
*/
void	ft_convert_str(t_format *format)
{
	if (format->str)
		free(format->str);
	if (format->precision == -1)
		format->str = ft_strdup(format->var_s);
	else if (format->precision == 0 )
		format->str = ft_strdup("");
	else
		format->str = ft_substr(format->var_s, 0, format->precision);
	return ;
}
