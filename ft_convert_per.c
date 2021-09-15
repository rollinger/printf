/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_per.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prolling <prolling@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 13:37:08 by prolling          #+#    #+#             */
/*   Updated: 2021/08/28 10:01:00 by prolling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_percent(t_format *format)
{
	format->str = ft_strfjoin(format->str, ft_ctos(format->var_c));
	format->exe_flags = 0;
	return ;
}
