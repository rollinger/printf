/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_format.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: prolling <prolling@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/11 11:46:14 by prolling          #+#    #+#             */
/*   Updated: 2021/07/11 17:08:18 by prolling         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
* Builds the structure of conversion, flags and variable and returns it. Used
* for later interpolation
*/
t_format	*build_format_struct(char **fpos, va_list args)
{
	t_format *format;

	format = (t_format *)malloc(sizeof(t_format));
	format->conv = *fpos[2];
	if (format->conv == 's')
		format->var_s = va_arg(args, char *);
	else if (format->conv == 'c')
		format->var_i = va_arg(args, int);
	else if (format->conv == 'i')
		format->var_i = va_arg(args, int);
	/* more conversions cs - ipduxX */
	/* more flags */
	return (format);
}

/*
* Frees the struct and all elements
*/
void	free_format(t_format *format)
{
	//free(format->str);
	//free(format->var_s);
	free(format);
	return ;
}
