/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prolling <prolling@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 11:46:10 by prolling          #+#    #+#             */
/*   Updated: 2021/07/11 15:11:15 by prolling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf"

/*
* Converts the variable into the correct string representation at format->str
*/
void	convert_variable(t_format *format);
{
	/* more conversions cs - ipduxX */
	if (format->conv == 's')
		format->str = convert_str(flags);
	else if (format->conv == 'c')
		format->str = convert_char(flags);
}
