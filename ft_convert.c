/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prolling <prolling@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 11:46:10 by prolling          #+#    #+#             */
/*   Updated: 2021/07/11 16:54:52 by prolling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
* Converts the variable into the correct string representation at format->str
*/
void	ft_convert_variable(t_format *format)
{
	/* more conversions csi - pduxX */
	if (format->conv == 's')
		ft_convert_str(format);
	else if (format->conv == 'c')
		ft_convert_char(format);
	else if (format->conv == 'i')
		ft_convert_int(format);
}
