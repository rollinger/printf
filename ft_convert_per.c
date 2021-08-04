/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_per.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prolling <prolling@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/03 13:37:08 by prolling          #+#    #+#             */
/*   Updated: 2021/08/04 10:59:30 by prolling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_convert_percent(t_format *format)
{
	format->var_c = '%';
	format->str = ft_strfjoin(format->str, ft_ctos(format->var_c));
	return ;
}
