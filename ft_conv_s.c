/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_conv_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prolling <prolling@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 13:59:12 by prolling          #+#    #+#             */
/*   Updated: 2021/07/09 14:17:34 by prolling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
* Convert a fragment into a resulting string. Returns a result string
* representing the varg's transformation.
* 1) gets the varg variable
*/
void	ft_conv_s(char **result, char conv, char *flags, va_list args)
{
	*result = va_arg(args, char*);
	return ;
}
